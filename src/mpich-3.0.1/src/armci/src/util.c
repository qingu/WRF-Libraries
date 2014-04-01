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


/** Fatal error, print the message and abort the program with the provided
  * error code.
  */
void ARMCI_Error(char *msg, int code) {
  fprintf(stderr, "[%d] ARMCI Error: %s\n", ARMCI_GROUP_WORLD.rank, msg);
  fflush(NULL);
  MPI_Abort(ARMCI_GROUP_WORLD.comm, code);
}


/* -- begin weak symbols block -- */
#if defined(HAVE_PRAGMA_WEAK)
#  pragma weak ARMCI_Barrier = PARMCI_Barrier
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#  pragma _HP_SECONDARY_DEF PARMCI_Barrier ARMCI_Barrier
#elif defined(HAVE_PRAGMA_CRI_DUP)
#  pragma _CRI duplicate ARMCI_Barrier as PARMCI_Barrier
#endif
/* -- end weak symbols block -- */

/** Barrier synchronization.  Collective on the world group (not the default
  * group!).
  */
void PARMCI_Barrier(void) {
  PARMCI_AllFence();
  MPI_Barrier(ARMCI_GROUP_WORLD.comm);

  if (ARMCII_GLOBAL_STATE.debug_flush_barriers) {
    ARMCII_Flush_local();
  }
}

/* -- begin weak symbols block -- */
#if defined(HAVE_PRAGMA_WEAK)
#  pragma weak ARMCI_Fence = PARMCI_Fence
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#  pragma _HP_SECONDARY_DEF PARMCI_Fence ARMCI_Fence
#elif defined(HAVE_PRAGMA_CRI_DUP)
#  pragma _CRI duplicate ARMCI_Fence as PARMCI_Fence
#endif
/* -- end weak symbols block -- */

/** Wait for remote completion on one-sided operations targeting process proc.
  * In MPI-2, this is a no-op since get/put/acc already guarantee remote
  * completion.
  *
  * @param[in] proc Process to target
  */
void PARMCI_Fence(int proc) {
  return;
}


/* -- begin weak symbols block -- */
#if defined(HAVE_PRAGMA_WEAK)
#  pragma weak ARMCI_AllFence = PARMCI_AllFence
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#  pragma _HP_SECONDARY_DEF PARMCI_AllFence ARMCI_AllFence
#elif defined(HAVE_PRAGMA_CRI_DUP)
#  pragma _CRI duplicate ARMCI_AllFence as PARMCI_AllFence
#endif
/* -- end weak symbols block -- */

/** Wait for remote completion on all one-sided operations.  In MPI-2, this is
  * a no-op since get/put/acc already guarantee remote completion.
  */
void PARMCI_AllFence(void) {
  return;
}


int ARMCI_Uses_shm(void) {
  return 0;
}


void ARMCI_Set_shm_limit(unsigned long shmemlimit) {
  return;
}


int ARMCI_Uses_shm_grp(ARMCI_Group *group) {
  return 0;
}


/** Copy local data.
  *
  * @param[in]  src  Source buffer
  * @param[out] dst  Destination buffer
  * @param[in]  size Number of bytes to copy
  */
void ARMCI_Copy(void *src, void *dst, int size) {
#ifndef COPY_WITH_SENDRECV
  memcpy(dst, src, size);
#else
  static MPI_Comm copy_comm = MPI_COMM_NULL;

  if (copy_comm == MPI_COMM_NULL)
    MPI_Comm_dup(MPI_COMM_SELF, &copy_comm);

  MPI_Sendrecv(src, size, MPI_BYTE,
      0 /* rank */, 0 /* tag */,
      dst, size, MPI_BYTE,
      0 /* rank */, 0 /* tag */,
      copy_comm, MPI_STATUS_IGNORE);
#endif
}


/** Zero out the given buffer.
  */
void ARMCII_Bzero(void *buf, armci_size_t size) {
  armci_size_t i;
  uint8_t *buf_b = (uint8_t *)buf;

  for (i = 0; i < size; i++)
    buf_b[i] = 0;
}


static const unsigned char log2_table[256] = 
    { 0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
      5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6,
      6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
      6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
      6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7,
      7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
      7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
      7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
      7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
      7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
      7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7 };

/** Calculate the base 2 logarithm of a given integer.
  */
int ARMCII_Log2(unsigned int val) {
  unsigned int v16, v8;
  int lg = 0;

  if (val == 0) return -1;

  if ((v16 = val >> 16))
    lg = (v8 = v16 >> 8) ? log2_table[v8] + 24 : log2_table[v16] + 16;
  else
    lg = (v8 = val >> 8) ? log2_table[v8] + 8 : log2_table[val];

  return lg;
}


/** Retrieve the value of a boolean environment variable.
  */
int ARMCII_Getenv_bool(char *varname, int default_value) {
  char *var = getenv(varname);

  if (var == NULL)
    return default_value;
  
  if (var[0] == 'T' || var[0] == 't' || var[0] == '1' || var[0] == 'y' || var[0] == 'Y')
    return 1;

  else
    return 0;
}


/** Retrieve the value of a environment variable.
  */
char *ARMCII_Getenv(char *varname) {
  return getenv(varname);
}


/** Retrieve the value of an integer environment variable.
  */
int ARMCII_Getenv_int(char *varname, int default_value) {
  char *var = getenv("ARMCI_IOV_BATCHED_LIMIT");
  if (var) 
    return atoi(var);
  else
    return default_value;
}
