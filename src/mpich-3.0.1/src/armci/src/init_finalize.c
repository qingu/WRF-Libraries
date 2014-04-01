/*
 * Copyright (C) 2010. See COPYRIGHT in top-level directory.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

#include <armci.h>
#include <armci_internals.h>
#include <debug.h>
#include <gmr.h>

/* -- begin weak symbols block -- */
#if defined(HAVE_PRAGMA_WEAK)
#  pragma weak ARMCI_Init = PARMCI_Init
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#  pragma _HP_SECONDARY_DEF PARMCI_Init ARMCI_Init
#elif defined(HAVE_PRAGMA_CRI_DUP)
#  pragma _CRI duplicate ARMCI_Init as PARMCI_Init
#endif
/* -- end weak symbols block -- */

/** Initialize ARMCI.  MPI must be initialized before this can be called.  It
  * invalid to make ARMCI calls before initialization.  Collective on the world
  * group.
  *
  * @return            Zero on success
  */
int PARMCI_Init(void) {
  char *var;

  /* GA/TCGMSG end up calling ARMCI_Init() multiple times. */
  if (ARMCII_GLOBAL_STATE.init_count > 0) {
    ARMCII_GLOBAL_STATE.init_count++;
    return 0;
  }

  /* Check for MPI initialization */
  {
    int mpi_is_init, mpi_is_fin;
    MPI_Initialized(&mpi_is_init);
    MPI_Finalized(&mpi_is_fin);
    if (!mpi_is_init || mpi_is_fin) 
      ARMCII_Error("MPI must be initialized before calling ARMCI_Init");
  }

  /* Set defaults */
#ifdef ARMCI_GROUP
  ARMCII_GLOBAL_STATE.noncollective_groups = 1;
#endif
#ifdef NO_SEATBELTS
  ARMCII_GLOBAL_STATE.iov_checks           = 0;
#endif

  /* Check for debugging flags */

  ARMCII_GLOBAL_STATE.debug_alloc          = ARMCII_Getenv_bool("ARMCI_DEBUG_ALLOC", 0);
  ARMCII_GLOBAL_STATE.debug_flush_barriers = ARMCII_Getenv_bool("ARMCI_FLUSH_BARRIERS", 1);
  ARMCII_GLOBAL_STATE.verbose              = ARMCII_Getenv_bool("ARMCI_VERBOSE", 0);

  /* Group formation options */

  ARMCII_GLOBAL_STATE.cache_rank_translation=ARMCII_Getenv_bool("ARMCI_CACHE_RANK_TRANSLATION", 1);
  if (ARMCII_Getenv("ARMCI_NONCOLLECTIVE_GROUPS"))
    ARMCII_GLOBAL_STATE.noncollective_groups = ARMCII_Getenv_bool("ARMCI_NONCOLLECTIVE_GROUPS", 0);

  /* Check for IOV flags */

  ARMCII_GLOBAL_STATE.iov_checks           = ARMCII_Getenv_bool("ARMCI_IOV_CHECKS", 0);
  ARMCII_GLOBAL_STATE.iov_batched_limit    = ARMCII_Getenv_int("ARMCI_IOV_BATCHED_LIMIT", 0);

  if (ARMCII_GLOBAL_STATE.iov_batched_limit < 0) {
    ARMCII_Warning("Ignoring invalid value for ARMCI_IOV_BATCHED_LIMIT (%d)\n", ARMCII_GLOBAL_STATE.iov_batched_limit);
    ARMCII_GLOBAL_STATE.iov_batched_limit = 0;
  }

  var = ARMCII_Getenv("ARMCI_IOV_METHOD");

  ARMCII_GLOBAL_STATE.iov_method = ARMCII_IOV_AUTO;

  if (var != NULL) {
    if (strcmp(var, "AUTO") == 0)
      ARMCII_GLOBAL_STATE.iov_method = ARMCII_IOV_AUTO;
    else if (strcmp(var, "CONSRV") == 0)
      ARMCII_GLOBAL_STATE.iov_method = ARMCII_IOV_CONSRV;
    else if (strcmp(var, "BATCHED") == 0)
      ARMCII_GLOBAL_STATE.iov_method = ARMCII_IOV_BATCHED;
    else if (strcmp(var, "DIRECT") == 0)
      ARMCII_GLOBAL_STATE.iov_method = ARMCII_IOV_DIRECT;
    else if (ARMCI_GROUP_WORLD.rank == 0)
      ARMCII_Warning("Ignoring unknown value for ARMCI_IOV_METHOD (%s)\n", var);
  }

  /* Check for Strided flags */

  var = ARMCII_Getenv("ARMCI_STRIDED_METHOD");

  ARMCII_GLOBAL_STATE.strided_method = ARMCII_STRIDED_DIRECT;

  if (var != NULL) {
    if (strcmp(var, "IOV") == 0)
      ARMCII_GLOBAL_STATE.strided_method = ARMCII_STRIDED_IOV;
    else if (strcmp(var, "DIRECT") == 0)
      ARMCII_GLOBAL_STATE.strided_method = ARMCII_STRIDED_DIRECT;
    else if (ARMCI_GROUP_WORLD.rank == 0)
      ARMCII_Warning("Ignoring unknown value for ARMCI_STRIDED_METHOD (%s)\n", var);
  }

  /* Shared buffer handling method */

  var = ARMCII_Getenv("ARMCI_SHR_BUF_METHOD");

  ARMCII_GLOBAL_STATE.shr_buf_method = ARMCII_SHR_BUF_COPY;

  if (var != NULL) {
    if (strcmp(var, "COPY") == 0)
      ARMCII_GLOBAL_STATE.shr_buf_method = ARMCII_SHR_BUF_COPY;
    else if (strcmp(var, "NOGUARD") == 0)
      ARMCII_GLOBAL_STATE.shr_buf_method = ARMCII_SHR_BUF_NOGUARD;
    else if (ARMCI_GROUP_WORLD.rank == 0)
      ARMCII_Warning("Ignoring unknown value for ARMCI_SHR_BUF_METHOD (%s)\n", var);
  }

  /* Setup groups and communicators */

  MPI_Comm_dup(MPI_COMM_WORLD, &ARMCI_GROUP_WORLD.comm);
  ARMCII_Group_init_from_comm(&ARMCI_GROUP_WORLD);
  ARMCI_GROUP_DEFAULT = ARMCI_GROUP_WORLD;

  /* Create GOP operators */

  MPI_Op_create(ARMCII_Absmin_op, 1 /* commute */, &MPI_ABSMIN_OP);
  MPI_Op_create(ARMCII_Absmax_op, 1 /* commute */, &MPI_ABSMAX_OP);

  MPI_Op_create(ARMCII_Msg_sel_min_op, 1 /* commute */, &MPI_SELMIN_OP);
  MPI_Op_create(ARMCII_Msg_sel_max_op, 1 /* commute */, &MPI_SELMAX_OP);

  ARMCII_GLOBAL_STATE.init_count++;

  if (ARMCII_GLOBAL_STATE.verbose) {
    if (ARMCI_GROUP_WORLD.rank == 0) {
      int major, minor;

      MPI_Get_version(&major, &minor);

      printf("ARMCI-MPI initialized with %d process%s, MPI v%d.%d\n", ARMCI_GROUP_WORLD.size, ARMCI_GROUP_WORLD.size > 1 ? "es":"", major, minor);
#ifdef NO_SEATBELTS
      printf("  NO_SEATBELTS           = ENABLED\n");
#endif
      printf("  STRIDED_METHOD         = %s\n", ARMCII_Strided_methods_str[ARMCII_GLOBAL_STATE.strided_method]);
      printf("  IOV_METHOD             = %s\n", ARMCII_Iov_methods_str[ARMCII_GLOBAL_STATE.iov_method]);

      if (   ARMCII_GLOBAL_STATE.iov_method == ARMCII_IOV_BATCHED
          || ARMCII_GLOBAL_STATE.iov_method == ARMCII_IOV_AUTO)
      {
        if (ARMCII_GLOBAL_STATE.iov_batched_limit > 0)
          printf("  IOV_BATCHED_LIMIT      = %d\n", ARMCII_GLOBAL_STATE.iov_batched_limit);
        else
          printf("  IOV_BATCHED_LIMIT      = UNLIMITED\n");
      }

      printf("  IOV_CHECKS             = %s\n", ARMCII_GLOBAL_STATE.iov_checks             ? "TRUE" : "FALSE");
      printf("  SHR_BUF_METHOD         = %s\n", ARMCII_Shr_buf_methods_str[ARMCII_GLOBAL_STATE.shr_buf_method]);
      printf("  NONCOLLECTIVE_GROUPS   = %s\n", ARMCII_GLOBAL_STATE.noncollective_groups   ? "TRUE" : "FALSE");
      printf("  CACHE_RANK_TRANSLATION = %s\n", ARMCII_GLOBAL_STATE.cache_rank_translation ? "TRUE" : "FALSE");
      printf("  DEBUG_ALLOC            = %s\n", ARMCII_GLOBAL_STATE.debug_alloc            ? "TRUE" : "FALSE");
      printf("  FLUSH_BARRIERS         = %s\n", ARMCII_GLOBAL_STATE.debug_flush_barriers   ? "TRUE" : "FALSE");
      printf("\n");
      fflush(NULL);
    }

    MPI_Barrier(ARMCI_GROUP_WORLD.comm);
  }

  return 0;
}


/* -- begin weak symbols block -- */
#if defined(HAVE_PRAGMA_WEAK)
#  pragma weak ARMCI_Init_args = PARMCI_Init_args
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#  pragma _HP_SECONDARY_DEF PARMCI_Init_args ARMCI_Init_args
#elif defined(HAVE_PRAGMA_CRI_DUP)
#  pragma _CRI duplicate ARMCI_Init_args as PARMCI_Init_args
#endif
/* -- end weak symbols block -- */

/** Initialize ARMCI.  MPI must be initialized before this can be called.  It
  * is invalid to make ARMCI calls before initialization.  Collective on the
  * world group.
  *
  * @param[inout] argc Command line argument count
  * @param[inout] argv Command line arguments
  * @return            Zero on success
  */
int PARMCI_Init_args(int *argc, char ***argv) {
  return PARMCI_Init();
}


/* -- begin weak symbols block -- */
#if defined(HAVE_PRAGMA_WEAK)
#  pragma weak ARMCI_Initialized = PARMCI_Initialized
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#  pragma _HP_SECONDARY_DEF PARMCI_Initialized ARMCI_Initialized
#elif defined(HAVE_PRAGMA_CRI_DUP)
#  pragma _CRI duplicate ARMCI_Initialized as PARMCI_Initialized
#endif
/* -- end weak symbols block -- */

/** Check if ARMCI has been initialized.
  *
  * @return Non-zero if ARMCI has been initialized.
  */
int PARMCI_Initialized(void) {
  return ARMCII_GLOBAL_STATE.init_count > 0;
}


/* -- begin weak symbols block -- */
#if defined(HAVE_PRAGMA_WEAK)
#  pragma weak ARMCI_Finalize = PARMCI_Finalize
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#  pragma _HP_SECONDARY_DEF PARMCI_Finalize ARMCI_Finalize
#elif defined(HAVE_PRAGMA_CRI_DUP)
#  pragma _CRI duplicate ARMCI_Finalize as PARMCI_Finalize
#endif
/* -- end weak symbols block -- */

/** Finalize ARMCI.  Must be called before MPI is finalized.  ARMCI calls are
  * not valid after finalization.  Collective on world group.
  *
  * @return            Zero on success
  */
int PARMCI_Finalize(void) {
  int nfreed;

  /* GA/TCGMSG end up calling ARMCI_Finalize() multiple times. */
  if (ARMCII_GLOBAL_STATE.init_count == 0) {
    return 0;
  }

  ARMCII_GLOBAL_STATE.init_count--;

  /* Only finalize on the last matching call */
  if (ARMCII_GLOBAL_STATE.init_count > 0) {
    return 0;
  }

  nfreed = gmr_destroy_all();

  if (nfreed > 0 && ARMCI_GROUP_WORLD.rank == 0)
    ARMCII_Warning("Freed %d leaked allocations\n", nfreed);

  /* Free GOP operators */

  MPI_Op_free(&MPI_ABSMIN_OP);
  MPI_Op_free(&MPI_ABSMAX_OP);

  MPI_Op_free(&MPI_SELMIN_OP);
  MPI_Op_free(&MPI_SELMAX_OP);

  ARMCI_Cleanup();

  ARMCI_Group_free(&ARMCI_GROUP_WORLD);

  return 0;
}


/** Cleaup ARMCI resources.  Call finalize instead.
  */
void ARMCI_Cleanup(void) {
  return;
}

