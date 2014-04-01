/* -*- Mode: C; c-basic-offset:4 ; indent-tabs-mode:nil ; -*- */
/*
 *  (C) 2011 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_T_pvar_reset */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_T_pvar_reset = PMPI_T_pvar_reset
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_T_pvar_reset  MPI_T_pvar_reset
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_T_pvar_reset as PMPI_T_pvar_reset
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_T_pvar_reset
#define MPI_T_pvar_reset PMPI_T_pvar_reset

/* any non-MPI functions go here, especially non-static ones */

#undef FUNCNAME
#define FUNCNAME MPIR_T_pvar_reset_impl
#undef FCNAME
#define FCNAME MPIU_QUOTE(FUNCNAME)
int MPIR_T_pvar_reset_impl(MPI_T_pvar_session session, MPI_T_pvar_handle handle)
{
    int mpi_errno = MPI_SUCCESS;

    /* TODO implement this function */

fn_exit:
    return mpi_errno;
fn_fail:
    goto fn_exit;
}

#endif /* MPICH_MPI_FROM_PMPI */

#undef FUNCNAME
#define FUNCNAME MPI_T_pvar_reset
#undef FCNAME
#define FCNAME MPIU_QUOTE(FUNCNAME)
/*@
MPI_T_pvar_reset - XXX description here

Input Parameters:
+ session - identifier of performance experiment session (handle)
- handle - handle of a performance variable (handle)

.N ThreadSafe

.N Fortran

.N Errors
@*/
int MPI_T_pvar_reset(MPI_T_pvar_session session, MPI_T_pvar_handle handle)
{
    int mpi_errno = MPI_SUCCESS;
    MPID_MPI_STATE_DECL(MPID_STATE_MPI_T_PVAR_RESET);

    MPIU_THREAD_CS_ENTER(ALLFUNC,);
    MPID_MPI_FUNC_ENTER(MPID_STATE_MPI_T_PVAR_RESET);

    /* Validate parameters, especially handles needing to be converted */
#   ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS
        {

            /* TODO more checks may be appropriate */
            if (mpi_errno != MPI_SUCCESS) goto fn_fail;
        }
        MPID_END_ERROR_CHECKS
    }
#   endif /* HAVE_ERROR_CHECKING */

    /* Convert MPI object handles to object pointers */

    /* Validate parameters and objects (post conversion) */
#   ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS
        {
            /* TODO more checks may be appropriate (counts, in_place, buffer aliasing, etc) */
            if (mpi_errno != MPI_SUCCESS) goto fn_fail;
        }
        MPID_END_ERROR_CHECKS
    }
#   endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ...  */

    mpi_errno = MPIR_T_pvar_reset_impl(session, handle);
    if (mpi_errno) MPIU_ERR_POP(mpi_errno);

    /* ... end of body of routine ... */

fn_exit:
    MPID_MPI_FUNC_EXIT(MPID_STATE_MPI_T_PVAR_RESET);
    MPIU_THREAD_CS_EXIT(ALLFUNC,);
    return mpi_errno;

fn_fail:
    /* --BEGIN ERROR HANDLING-- */
#   ifdef HAVE_ERROR_CHECKING
    {
        mpi_errno = MPIR_Err_create_code(
            mpi_errno, MPIR_ERR_RECOVERABLE, FCNAME, __LINE__, MPI_ERR_OTHER,
            "**mpi_t_pvar_reset", "**mpi_t_pvar_reset %p %p", session, handle);
    }
#   endif
    mpi_errno = MPIR_Err_return_comm(NULL, FCNAME, mpi_errno);
    goto fn_exit;
    /* --END ERROR HANDLING-- */
}
