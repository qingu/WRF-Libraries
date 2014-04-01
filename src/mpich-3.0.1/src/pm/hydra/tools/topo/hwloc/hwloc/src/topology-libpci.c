/*
 * Copyright © 2009 CNRS
 * Copyright © 2009-2012 Inria.  All rights reserved.
 * Copyright © 2009-2011 Université Bordeaux 1
 * See COPYING in top-level directory.
 */

#include <private/autogen/config.h>
#include <hwloc.h>
#include <hwloc/helper.h>
#include <private/private.h>
#include <private/debug.h>
#include <private/misc.h>

#include <pci/pci.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>
#include <setjmp.h>

#define CONFIG_SPACE_CACHESIZE 256

static void
hwloc_pci_traverse_print_cb(void * cbdata __hwloc_attribute_unused,
			    struct hwloc_obj *pcidev, int depth __hwloc_attribute_unused)
{
  char busid[14];
  snprintf(busid, sizeof(busid), "%04x:%02x:%02x.%01x",
           pcidev->attr->pcidev.domain, pcidev->attr->pcidev.bus, pcidev->attr->pcidev.dev, pcidev->attr->pcidev.func);

  if (pcidev->type == HWLOC_OBJ_BRIDGE) {
    if (pcidev->attr->bridge.upstream_type == HWLOC_OBJ_BRIDGE_HOST)
      hwloc_debug("%*s HostBridge", depth, "");
    else
      hwloc_debug("%*s %s Bridge [%04x:%04x]", depth, "", busid,
		  pcidev->attr->pcidev.vendor_id, pcidev->attr->pcidev.device_id);
    hwloc_debug(" to %04x:[%02x:%02x]\n",
		pcidev->attr->bridge.downstream.pci.domain, pcidev->attr->bridge.downstream.pci.secondary_bus, pcidev->attr->bridge.downstream.pci.subordinate_bus);
  } else
    hwloc_debug("%*s %s Device [%04x:%04x (%04x:%04x) rev=%02x class=%04x]\n", depth, "", busid,
		pcidev->attr->pcidev.vendor_id, pcidev->attr->pcidev.device_id,
		pcidev->attr->pcidev.subvendor_id, pcidev->attr->pcidev.subdevice_id,
		pcidev->attr->pcidev.revision, pcidev->attr->pcidev.class_id);
}

static void
hwloc_pci_traverse_setbridgedepth_cb(void * cbdata __hwloc_attribute_unused,
				     struct hwloc_obj *pcidev, int depth)
{
  if (pcidev->type == HWLOC_OBJ_BRIDGE)
    pcidev->attr->bridge.depth = depth;
}

static void
hwloc_pci_traverse_lookuposdevices_cb(void * cbdata,
				      struct hwloc_obj *pcidev, int depth __hwloc_attribute_unused)
{
  struct hwloc_backend *backend = cbdata;

  if (pcidev->type == HWLOC_OBJ_BRIDGE)
    return;

  hwloc_backends_notify_new_object(backend, pcidev);
}

static void
hwloc_pci__traverse(void * cbdata, struct hwloc_obj *root,
		    void (*cb)(void * cbdata, struct hwloc_obj *, int depth),
		    int depth)
{
  struct hwloc_obj *child = root->first_child;
  while (child) {
    cb(cbdata, child, depth);
    if (child->type == HWLOC_OBJ_BRIDGE)
      hwloc_pci__traverse(cbdata, child, cb, depth+1);
    child = child->next_sibling;
  }
}

static void
hwloc_pci_traverse(void * cbdata, struct hwloc_obj *root,
		   void (*cb)(void * cbdata, struct hwloc_obj *, int depth))
{
  hwloc_pci__traverse(cbdata, root, cb, 0);
}

enum hwloc_pci_busid_comparison_e {
  HWLOC_PCI_BUSID_LOWER,
  HWLOC_PCI_BUSID_HIGHER,
  HWLOC_PCI_BUSID_INCLUDED,
  HWLOC_PCI_BUSID_SUPERSET
};

static enum hwloc_pci_busid_comparison_e 
hwloc_pci_compare_busids(struct hwloc_obj *a, struct hwloc_obj *b)
{
  if (a->type == HWLOC_OBJ_BRIDGE)
    assert(a->attr->bridge.upstream_type == HWLOC_OBJ_BRIDGE_PCI);
  if (b->type == HWLOC_OBJ_BRIDGE)
    assert(b->attr->bridge.upstream_type == HWLOC_OBJ_BRIDGE_PCI);

  if (a->attr->pcidev.domain < b->attr->pcidev.domain)
    return HWLOC_PCI_BUSID_LOWER;
  if (a->attr->pcidev.domain > b->attr->pcidev.domain)
    return HWLOC_PCI_BUSID_HIGHER;

  if (a->type == HWLOC_OBJ_BRIDGE
      && b->attr->pcidev.bus >= a->attr->bridge.downstream.pci.secondary_bus
      && b->attr->pcidev.bus <= a->attr->bridge.downstream.pci.subordinate_bus)
    return HWLOC_PCI_BUSID_SUPERSET;
  if (b->type == HWLOC_OBJ_BRIDGE
      && a->attr->pcidev.bus >= b->attr->bridge.downstream.pci.secondary_bus
      && a->attr->pcidev.bus <= b->attr->bridge.downstream.pci.subordinate_bus)
    return HWLOC_PCI_BUSID_INCLUDED;

  if (a->attr->pcidev.bus < b->attr->pcidev.bus)
    return HWLOC_PCI_BUSID_LOWER;
  if (a->attr->pcidev.bus > b->attr->pcidev.bus)
    return HWLOC_PCI_BUSID_HIGHER;

  if (a->attr->pcidev.dev < b->attr->pcidev.dev)
    return HWLOC_PCI_BUSID_LOWER;
  if (a->attr->pcidev.dev > b->attr->pcidev.dev)
    return HWLOC_PCI_BUSID_HIGHER;

  if (a->attr->pcidev.func < b->attr->pcidev.func)
    return HWLOC_PCI_BUSID_LOWER;
  if (a->attr->pcidev.func > b->attr->pcidev.func)
    return HWLOC_PCI_BUSID_HIGHER;

  /* Should never reach here.  Abort on both debug builds and
     non-debug builds */
  assert(0);
  fprintf(stderr, "Bad assertion in hwloc %s:%d (aborting)\n", __FILE__, __LINE__);
  exit(1);
}

static void
hwloc_pci_add_child_before(struct hwloc_obj *root, struct hwloc_obj *child, struct hwloc_obj *new)
{
  if (child) {
    new->prev_sibling = child->prev_sibling;
    child->prev_sibling = new;
  } else {
    new->prev_sibling = root->last_child;
    root->last_child = new;
  }

  if (new->prev_sibling)
    new->prev_sibling->next_sibling = new;
  else
    root->first_child = new;
  new->next_sibling = child;
}

static void
hwloc_pci_remove_child(struct hwloc_obj *root, struct hwloc_obj *child)
{
  if (child->next_sibling)
    child->next_sibling->prev_sibling = child->prev_sibling;
  else
    root->last_child = child->prev_sibling;
  if (child->prev_sibling)
    child->prev_sibling->next_sibling = child->next_sibling;
  else
    root->first_child = child->next_sibling;
  child->prev_sibling = NULL;
  child->next_sibling = NULL;
}

static void hwloc_pci_add_object(struct hwloc_obj *root, struct hwloc_obj *new);

static void
hwloc_pci_try_insert_siblings_below_new_bridge(struct hwloc_obj *root, struct hwloc_obj *new)
{
  enum hwloc_pci_busid_comparison_e comp;
  struct hwloc_obj *current, *next;

  next = new->next_sibling;
  while (next) {
    current = next;
    next = current->next_sibling;

    comp = hwloc_pci_compare_busids(current, new);
    assert(comp != HWLOC_PCI_BUSID_SUPERSET);
    if (comp == HWLOC_PCI_BUSID_HIGHER)
      continue;
    assert(comp == HWLOC_PCI_BUSID_INCLUDED);

    /* move this object below the new bridge */
    hwloc_pci_remove_child(root, current);
    hwloc_pci_add_object(new, current);
  }
}

static void
hwloc_pci_add_object(struct hwloc_obj *root, struct hwloc_obj *new)
{
  struct hwloc_obj *current;

  current = root->first_child;
  while (current) {
    enum hwloc_pci_busid_comparison_e comp = hwloc_pci_compare_busids(new, current);
    switch (comp) {
    case HWLOC_PCI_BUSID_HIGHER:
      /* go further */
      current = current->next_sibling;
      continue;
    case HWLOC_PCI_BUSID_INCLUDED:
      /* insert below current bridge */
      hwloc_pci_add_object(current, new);
      return;
    case HWLOC_PCI_BUSID_LOWER:
    case HWLOC_PCI_BUSID_SUPERSET:
      /* insert before current object */
      hwloc_pci_add_child_before(root, current, new);
      /* walk next siblings and move them below new bridge if needed */
      hwloc_pci_try_insert_siblings_below_new_bridge(root, new);
      return;
    }
  }
  /* add to the end of the list if higher than everybody */
  hwloc_pci_add_child_before(root, NULL, new);
}

static struct hwloc_obj *
hwloc_pci_find_hostbridge_parent(struct hwloc_topology *topology, struct hwloc_backend *backend,
				 struct hwloc_obj *hostbridge, int *created)
{
  hwloc_bitmap_t cpuset = hwloc_bitmap_alloc();
  struct hwloc_obj *parent;
  char *env;
  int err;

  /* override the cpuset with the environment if given */
  char envname[256];
  snprintf(envname, sizeof(envname), "HWLOC_PCI_%04x_%02x_LOCALCPUS",
	   hostbridge->first_child->attr->pcidev.domain, hostbridge->first_child->attr->pcidev.bus);
  env = getenv(envname);
  if (env) {
    /* force the hostbridge cpuset */
    hwloc_debug("Overriding localcpus using %s in the environment\n", envname);
    hwloc_bitmap_sscanf(cpuset, env);
  } else {
    /* get the hostbridge cpuset by acking the OS backend.
     * it's not a PCI device, so we use its first child locality info.
     */
    err = hwloc_backends_get_obj_cpuset(backend, hostbridge->first_child, cpuset);
    if (err < 0)
      /* if we got nothing, assume the hostbridge is attached to the top of hierarchy */
      hwloc_bitmap_copy(cpuset, hwloc_topology_get_topology_cpuset(topology));
  }

  hwloc_debug_bitmap("Attaching hostbridge to cpuset %s\n", cpuset);

  /* restrict to the existing topology cpuset to avoid errors later */
  hwloc_bitmap_and(cpuset, cpuset, topology->levels[0][0]->cpuset);

  /* if the remaining cpuset is empty, take the root */
  if (hwloc_bitmap_iszero(cpuset))
    hwloc_bitmap_copy(cpuset, hwloc_topology_get_topology_cpuset(topology));

  /* attach the hostbridge now that it contains the right objects */
  parent = hwloc_get_obj_covering_cpuset(topology, cpuset);
  /* in the worst case, we got the root object */

  if (hwloc_bitmap_isequal(cpuset, parent->cpuset)) {
    /* this object has the right cpuset, but it could be a cache or so,
     * go up as long as the cpuset is the same
     */
    while (parent->parent && hwloc_bitmap_isequal(parent->cpuset, parent->parent->cpuset))
      parent = parent->parent;
  } else {
    /* the object we found is too large, insert an intermediate group */
    hwloc_obj_t group_obj = group_obj = hwloc_alloc_setup_object(HWLOC_OBJ_GROUP, -1);
    if (group_obj) {
      group_obj->cpuset = hwloc_bitmap_dup(cpuset);
      group_obj->attr->group.depth = topology->next_group_depth;
      hwloc__insert_object_by_cpuset(topology, group_obj, hwloc_report_os_error);
      parent = group_obj;
      *created = 1;
    }
  }

  hwloc_bitmap_free(cpuset);

  return parent;
}

/* Avoid letting libpci call exit(1) when no PCI bus is available. */
static jmp_buf err_buf;
static void
hwloc_pci_error(char *msg, ...)
{
  va_list args;

  va_start(args, msg);
  fprintf(stderr, "pcilib: ");
  vfprintf(stderr, msg, args);
  fprintf(stderr, "\n");
  longjmp(err_buf, 1);
}

static void
hwloc_pci_warning(char *msg __hwloc_attribute_unused, ...)
{
}

static int
hwloc_look_libpci(struct hwloc_backend *backend)
{
  struct hwloc_topology *topology = backend->topology;
  struct pci_access *pciaccess;
  struct pci_dev *pcidev;
  struct hwloc_obj fakehostbridge; /* temporary object covering the whole PCI hierarchy until its complete */
  unsigned current_hostbridge;
  int createdgroups = 0;

  if (!(topology->flags & (HWLOC_TOPOLOGY_FLAG_IO_DEVICES|HWLOC_TOPOLOGY_FLAG_WHOLE_IO)))
    return 0;

  if (!topology->is_thissystem) {
    hwloc_debug("%s", "\nno PCI detection (not thissystem)\n");
    return 0;
  }

  fakehostbridge.first_child = NULL;
  fakehostbridge.last_child = NULL;

  hwloc_debug("%s", "\nScanning PCI buses...\n");

  pciaccess = pci_alloc();
  pciaccess->error = hwloc_pci_error;
  pciaccess->warning = hwloc_pci_warning;

  if (setjmp(err_buf)) {
    pci_cleanup(pciaccess);
    return -1;
  }

  pci_init(pciaccess);
  pci_scan_bus(pciaccess);

  pcidev = pciaccess->devices;
  while (pcidev) {
    char name[128];
    const char *resname;
    u8 config_space_cache[CONFIG_SPACE_CACHESIZE];
    struct hwloc_obj *obj;
    unsigned char headertype;
    unsigned os_index;
    unsigned isbridge;
    unsigned domain;
    unsigned device_class;

    /* cache what we need of the config space */
    pci_read_block(pcidev, 0, config_space_cache, CONFIG_SPACE_CACHESIZE);

    /* read some fields that may not always be available */
#ifdef HWLOC_HAVE_PCIDEV_DOMAIN
    domain = pcidev->domain;
#else
    domain = 0; /* default domain number */
#endif
#ifdef HWLOC_HAVE_PCIDEV_DEVICE_CLASS
    device_class = pcidev->device_class;
#else
    HWLOC_BUILD_ASSERT(PCI_CLASS_DEVICE < CONFIG_SPACE_CACHESIZE);
    device_class = config_space_cache[PCI_CLASS_DEVICE] | (config_space_cache[PCI_CLASS_DEVICE+1] << 8);
#endif

    /* is this a bridge? */
    HWLOC_BUILD_ASSERT(PCI_HEADER_TYPE < CONFIG_SPACE_CACHESIZE);
    headertype = config_space_cache[PCI_HEADER_TYPE] & 0x7f;
    isbridge = (device_class == PCI_CLASS_BRIDGE_PCI
		&& headertype == PCI_HEADER_TYPE_BRIDGE);

    /* might be useful for debugging (note that domain might be truncated) */
    os_index = (domain << 20) + (pcidev->bus << 12) + (pcidev->dev << 4) + pcidev->func;

    obj = hwloc_alloc_setup_object(isbridge ? HWLOC_OBJ_BRIDGE : HWLOC_OBJ_PCI_DEVICE, os_index);
    obj->attr->pcidev.domain = domain;
    obj->attr->pcidev.bus = pcidev->bus;
    obj->attr->pcidev.dev = pcidev->dev;
    obj->attr->pcidev.func = pcidev->func;
    obj->attr->pcidev.vendor_id = pcidev->vendor_id;
    obj->attr->pcidev.device_id = pcidev->device_id;
    obj->attr->pcidev.class_id = device_class;
    HWLOC_BUILD_ASSERT(PCI_REVISION_ID < CONFIG_SPACE_CACHESIZE);
    obj->attr->pcidev.revision = config_space_cache[PCI_REVISION_ID];
    HWLOC_BUILD_ASSERT(PCI_SUBSYSTEM_VENDOR_ID < CONFIG_SPACE_CACHESIZE);
    obj->attr->pcidev.subvendor_id = config_space_cache[PCI_SUBSYSTEM_VENDOR_ID];
    HWLOC_BUILD_ASSERT(PCI_SUBSYSTEM_ID < CONFIG_SPACE_CACHESIZE);
    obj->attr->pcidev.subdevice_id = config_space_cache[PCI_SUBSYSTEM_ID];

    obj->attr->pcidev.linkspeed = 0; /* unknown */
#ifdef HWLOC_HAVE_PCI_FIND_CAP
    {
    struct pci_cap *cap = pci_find_cap(pcidev, PCI_CAP_ID_EXP, PCI_CAP_NORMAL);
    if (cap) {
      if (cap->addr + PCI_EXP_LNKSTA >= CONFIG_SPACE_CACHESIZE) {
        fprintf(stderr, "cannot read PCI_EXP_LNKSTA cap at %d (only %d cached)\n", cap->addr + PCI_EXP_LNKSTA, CONFIG_SPACE_CACHESIZE);
      } else {
        unsigned linksta, speed, width;
        float lanespeed;
        memcpy(&linksta, &config_space_cache[cap->addr + PCI_EXP_LNKSTA], 4);
        speed = linksta & PCI_EXP_LNKSTA_SPEED; /* PCIe generation */
        width = (linksta & PCI_EXP_LNKSTA_WIDTH) >> 4; /* how many lanes */
	/* PCIe Gen1 = 2.5GT/s signal-rate per lane with 8/10 encoding    = 0.25GB/s data-rate per lane
	 * PCIe Gen2 = 5  GT/s signal-rate per lane with 8/10 encoding    = 0.5 GB/s data-rate per lane
	 * PCIe Gen3 = 8  GT/s signal-rate per lane with 128/130 encoding = 1   GB/s data-rate per lane
	 */
        lanespeed = speed <= 2 ? 2.5 * speed * 0.8 : 8.0 * 128/130; /* Gbit/s per lane */
        obj->attr->pcidev.linkspeed = lanespeed * width / 8; /* GB/s */
      }
    }
    }
#endif /* HWLOC_HAVE_PCI_FIND_CAP */

    if (isbridge) {
      HWLOC_BUILD_ASSERT(PCI_PRIMARY_BUS < CONFIG_SPACE_CACHESIZE);
      HWLOC_BUILD_ASSERT(PCI_SECONDARY_BUS < CONFIG_SPACE_CACHESIZE);
      HWLOC_BUILD_ASSERT(PCI_SUBORDINATE_BUS < CONFIG_SPACE_CACHESIZE);
      if (config_space_cache[PCI_PRIMARY_BUS] != pcidev->bus)
	hwloc_debug("  %04x:%02x:%02x.%01x bridge with (ignored) invalid PCI_PRIMARY_BUS %02x\n",
		    domain, pcidev->bus, pcidev->dev, pcidev->func, config_space_cache[PCI_PRIMARY_BUS]);
      obj->attr->bridge.upstream_type = HWLOC_OBJ_BRIDGE_PCI;
      obj->attr->bridge.downstream_type = HWLOC_OBJ_BRIDGE_PCI;
      obj->attr->bridge.downstream.pci.domain = domain;
      obj->attr->bridge.downstream.pci.secondary_bus = config_space_cache[PCI_SECONDARY_BUS];
      obj->attr->bridge.downstream.pci.subordinate_bus = config_space_cache[PCI_SUBORDINATE_BUS];
    }

/* starting from pciutils 2.2, pci_lookup_name() takes a variable number
 * of arguments, and supports the PCI_LOOKUP_NO_NUMBERS flag.
 */

    resname = pci_lookup_name(pciaccess, name, sizeof(name),
#if HAVE_DECL_PCI_LOOKUP_NO_NUMBERS
			      PCI_LOOKUP_VENDOR|PCI_LOOKUP_NO_NUMBERS,
			      pcidev->vendor_id
#else
			      PCI_LOOKUP_VENDOR,
			      pcidev->vendor_id, 0, 0, 0
#endif
			      );
    if (resname)
      hwloc_obj_add_info(obj, "PCIVendor", resname);

    resname = pci_lookup_name(pciaccess, name, sizeof(name),
#if HAVE_DECL_PCI_LOOKUP_NO_NUMBERS
			      PCI_LOOKUP_DEVICE|PCI_LOOKUP_NO_NUMBERS,
			      pcidev->vendor_id, pcidev->device_id
#else
			      PCI_LOOKUP_DEVICE,
			      pcidev->vendor_id, pcidev->device_id, 0, 0
#endif
			      );
    if (resname)
      hwloc_obj_add_info(obj, "PCIDevice", resname);

    resname = pci_lookup_name(pciaccess, name, sizeof(name),
#if HAVE_DECL_PCI_LOOKUP_NO_NUMBERS
			      PCI_LOOKUP_VENDOR|PCI_LOOKUP_DEVICE|PCI_LOOKUP_NO_NUMBERS,
			      pcidev->vendor_id, pcidev->device_id
#else
			      PCI_LOOKUP_VENDOR|PCI_LOOKUP_DEVICE,
			      pcidev->vendor_id, pcidev->device_id, 0, 0
#endif
			      );
    if (resname)
      obj->name = strdup(resname);
    else
      resname = "??";

    hwloc_debug("  %04x:%02x:%02x.%01x %04x %04x:%04x %s\n",
		domain, pcidev->bus, pcidev->dev, pcidev->func,
		device_class, pcidev->vendor_id, pcidev->device_id,
		resname);

    hwloc_pci_add_object(&fakehostbridge, obj);
    pcidev = pcidev->next;
  }

  pci_cleanup(pciaccess);

  hwloc_debug("%s", "\nPCI hierarchy after basic scan:\n");
  hwloc_pci_traverse(NULL, &fakehostbridge, hwloc_pci_traverse_print_cb);

  if (!fakehostbridge.first_child)
    /* found nothing, exit */
    return 0;

  /* walk the hierarchy, set bridge depth and lookup OS devices */
  hwloc_pci_traverse(NULL, &fakehostbridge, hwloc_pci_traverse_setbridgedepth_cb);
  hwloc_pci_traverse(backend, &fakehostbridge, hwloc_pci_traverse_lookuposdevices_cb);

  /*
   * fakehostbridge lists all objects connected to any upstream bus in the machine.
   * We now create one real hostbridge object per upstream bus.
   * It's not actually a PCI device so we have to create it.
   */
  current_hostbridge = 0;
  while (fakehostbridge.first_child) {
    /* start a new host bridge */
    struct hwloc_obj *hostbridge = hwloc_alloc_setup_object(HWLOC_OBJ_BRIDGE, current_hostbridge++);
    struct hwloc_obj *child = fakehostbridge.first_child;
    struct hwloc_obj *next_child;
    struct hwloc_obj *parent;
    unsigned short current_domain = child->attr->pcidev.domain;
    unsigned char current_bus = child->attr->pcidev.bus;
    unsigned char current_subordinate = current_bus;

    hwloc_debug("Starting new PCI hostbridge %04x:%02x\n", current_domain, current_bus);

    /*
     * attach all objects from the same upstream domain/bus
     */
  next_child:
    next_child = child->next_sibling;
    hwloc_pci_remove_child(&fakehostbridge, child);
    hwloc_pci_add_child_before(hostbridge, NULL, child);

    /* compute hostbridge secondary/subordinate buses */
    if (child->type == HWLOC_OBJ_BRIDGE
	&& child->attr->bridge.downstream.pci.subordinate_bus > current_subordinate)
      current_subordinate = child->attr->bridge.downstream.pci.subordinate_bus;

    /* use next child if it has the same domains/bus */
    child = next_child;
    if (child
	&& child->attr->pcidev.domain == current_domain
	&& child->attr->pcidev.bus == current_bus)
      goto next_child;

    /* finish setting up this hostbridge */
    hostbridge->attr->bridge.upstream_type = HWLOC_OBJ_BRIDGE_HOST;
    hostbridge->attr->bridge.downstream_type = HWLOC_OBJ_BRIDGE_PCI;
    hostbridge->attr->bridge.downstream.pci.domain = current_domain;
    hostbridge->attr->bridge.downstream.pci.secondary_bus = current_bus;
    hostbridge->attr->bridge.downstream.pci.subordinate_bus = current_subordinate;
    hwloc_debug("New PCI hostbridge %04x:[%02x-%02x]\n",
		current_domain, current_bus, current_subordinate);

    /* attach the hostbridge where it belongs */
    parent = hwloc_pci_find_hostbridge_parent(topology, backend, hostbridge, &createdgroups);
    hwloc_insert_object_by_parent(topology, parent, hostbridge);
  }

  if (createdgroups)
    topology->next_group_depth++;

  return 1;
}

static struct hwloc_backend *
hwloc_libpci_component_instantiate(struct hwloc_disc_component *component,
				   const void *_data1 __hwloc_attribute_unused,
				   const void *_data2 __hwloc_attribute_unused,
				   const void *_data3 __hwloc_attribute_unused)
{
  struct hwloc_backend *backend;

  /* thissystem may not be fully initialized yet, we'll check flags in discover() */

  backend = hwloc_backend_alloc(component);
  if (!backend)
    return NULL;
  backend->discover = hwloc_look_libpci;
  return backend;
}

static struct hwloc_disc_component hwloc_libpci_disc_component = {
  HWLOC_DISC_COMPONENT_TYPE_ADDITIONAL,
  "libpci",
  HWLOC_DISC_COMPONENT_TYPE_GLOBAL,
  hwloc_libpci_component_instantiate,
  20,
  NULL
};

const struct hwloc_component hwloc_libpci_component = {
  HWLOC_COMPONENT_ABI,
  HWLOC_COMPONENT_TYPE_DISC,
  0,
  &hwloc_libpci_disc_component
};
