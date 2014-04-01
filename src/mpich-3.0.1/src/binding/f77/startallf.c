/* -*- Mode: C; c-basic-offset:4 ; -*- */
/*  
 *  (C) 2001 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 *
 * This file is automatically generated by buildiface 
 * DO NOT EDIT
 */
#include "mpi_fortimpl.h"


/* Begin MPI profiling block */
#if defined(USE_WEAK_SYMBOLS) && !defined(USE_ONLY_MPI_NAMES) 
#if defined(HAVE_MULTIPLE_PRAGMA_WEAK)
extern FORT_DLL_SPEC void FORT_CALL MPI_STARTALL( MPI_Fint *, MPI_Fint [], MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_startall__( MPI_Fint *, MPI_Fint [], MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_startall( MPI_Fint *, MPI_Fint [], MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_startall_( MPI_Fint *, MPI_Fint [], MPI_Fint * );

#if defined(F77_NAME_UPPER)
#pragma weak MPI_STARTALL = PMPI_STARTALL
#pragma weak mpi_startall__ = PMPI_STARTALL
#pragma weak mpi_startall_ = PMPI_STARTALL
#pragma weak mpi_startall = PMPI_STARTALL
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak MPI_STARTALL = pmpi_startall__
#pragma weak mpi_startall__ = pmpi_startall__
#pragma weak mpi_startall_ = pmpi_startall__
#pragma weak mpi_startall = pmpi_startall__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak MPI_STARTALL = pmpi_startall_
#pragma weak mpi_startall__ = pmpi_startall_
#pragma weak mpi_startall_ = pmpi_startall_
#pragma weak mpi_startall = pmpi_startall_
#else
#pragma weak MPI_STARTALL = pmpi_startall
#pragma weak mpi_startall__ = pmpi_startall
#pragma weak mpi_startall_ = pmpi_startall
#pragma weak mpi_startall = pmpi_startall
#endif



#elif defined(HAVE_PRAGMA_WEAK)

#if defined(F77_NAME_UPPER)
extern FORT_DLL_SPEC void FORT_CALL MPI_STARTALL( MPI_Fint *, MPI_Fint [], MPI_Fint * );

#pragma weak MPI_STARTALL = PMPI_STARTALL
#elif defined(F77_NAME_LOWER_2USCORE)
extern FORT_DLL_SPEC void FORT_CALL mpi_startall__( MPI_Fint *, MPI_Fint [], MPI_Fint * );

#pragma weak mpi_startall__ = pmpi_startall__
#elif !defined(F77_NAME_LOWER_USCORE)
extern FORT_DLL_SPEC void FORT_CALL mpi_startall( MPI_Fint *, MPI_Fint [], MPI_Fint * );

#pragma weak mpi_startall = pmpi_startall
#else
extern FORT_DLL_SPEC void FORT_CALL mpi_startall_( MPI_Fint *, MPI_Fint [], MPI_Fint * );

#pragma weak mpi_startall_ = pmpi_startall_
#endif

#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#if defined(F77_NAME_UPPER)
#pragma _HP_SECONDARY_DEF PMPI_STARTALL  MPI_STARTALL
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma _HP_SECONDARY_DEF pmpi_startall__  mpi_startall__
#elif !defined(F77_NAME_LOWER_USCORE)
#pragma _HP_SECONDARY_DEF pmpi_startall  mpi_startall
#else
#pragma _HP_SECONDARY_DEF pmpi_startall_  mpi_startall_
#endif

#elif defined(HAVE_PRAGMA_CRI_DUP)
#if defined(F77_NAME_UPPER)
#pragma _CRI duplicate MPI_STARTALL as PMPI_STARTALL
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma _CRI duplicate mpi_startall__ as pmpi_startall__
#elif !defined(F77_NAME_LOWER_USCORE)
#pragma _CRI duplicate mpi_startall as pmpi_startall
#else
#pragma _CRI duplicate mpi_startall_ as pmpi_startall_
#endif
#endif /* HAVE_PRAGMA_WEAK */
#endif /* USE_WEAK_SYMBOLS */
/* End MPI profiling block */


/* These definitions are used only for generating the Fortran wrappers */
#if defined(USE_WEAK_SYMBOLS) && defined(HAVE_MULTIPLE_PRAGMA_WEAK) && \
    defined(USE_ONLY_MPI_NAMES)
extern FORT_DLL_SPEC void FORT_CALL MPI_STARTALL( MPI_Fint *, MPI_Fint [], MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_startall__( MPI_Fint *, MPI_Fint [], MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_startall( MPI_Fint *, MPI_Fint [], MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_startall_( MPI_Fint *, MPI_Fint [], MPI_Fint * );

#if defined(F77_NAME_UPPER)
#pragma weak mpi_startall__ = MPI_STARTALL
#pragma weak mpi_startall_ = MPI_STARTALL
#pragma weak mpi_startall = MPI_STARTALL
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak MPI_STARTALL = mpi_startall__
#pragma weak mpi_startall_ = mpi_startall__
#pragma weak mpi_startall = mpi_startall__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak MPI_STARTALL = mpi_startall_
#pragma weak mpi_startall__ = mpi_startall_
#pragma weak mpi_startall = mpi_startall_
#else
#pragma weak MPI_STARTALL = mpi_startall
#pragma weak mpi_startall__ = mpi_startall
#pragma weak mpi_startall_ = mpi_startall
#endif

#endif

/* Map the name to the correct form */
#ifndef MPICH_MPI_FROM_PMPI
#if defined(USE_WEAK_SYMBOLS) && defined(HAVE_MULTIPLE_PRAGMA_WEAK)
/* Define the weak versions of the PMPI routine*/
#ifndef F77_NAME_UPPER
extern FORT_DLL_SPEC void FORT_CALL PMPI_STARTALL( MPI_Fint *, MPI_Fint [], MPI_Fint * );
#endif
#ifndef F77_NAME_LOWER_2USCORE
extern FORT_DLL_SPEC void FORT_CALL pmpi_startall__( MPI_Fint *, MPI_Fint [], MPI_Fint * );
#endif
#ifndef F77_NAME_LOWER_USCORE
extern FORT_DLL_SPEC void FORT_CALL pmpi_startall_( MPI_Fint *, MPI_Fint [], MPI_Fint * );
#endif
#ifndef F77_NAME_LOWER
extern FORT_DLL_SPEC void FORT_CALL pmpi_startall( MPI_Fint *, MPI_Fint [], MPI_Fint * );

#endif

#if defined(F77_NAME_UPPER)
#pragma weak pmpi_startall__ = PMPI_STARTALL
#pragma weak pmpi_startall_ = PMPI_STARTALL
#pragma weak pmpi_startall = PMPI_STARTALL
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak PMPI_STARTALL = pmpi_startall__
#pragma weak pmpi_startall_ = pmpi_startall__
#pragma weak pmpi_startall = pmpi_startall__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak PMPI_STARTALL = pmpi_startall_
#pragma weak pmpi_startall__ = pmpi_startall_
#pragma weak pmpi_startall = pmpi_startall_
#else
#pragma weak PMPI_STARTALL = pmpi_startall
#pragma weak pmpi_startall__ = pmpi_startall
#pragma weak pmpi_startall_ = pmpi_startall
#endif /* Test on name mapping */
#endif /* Use multiple pragma weak */

#ifdef F77_NAME_UPPER
#define mpi_startall_ PMPI_STARTALL
#elif defined(F77_NAME_LOWER_2USCORE)
#define mpi_startall_ pmpi_startall__
#elif !defined(F77_NAME_LOWER_USCORE)
#define mpi_startall_ pmpi_startall
#else
#define mpi_startall_ pmpi_startall_
#endif /* Test on name mapping */

/* This defines the routine that we call, which must be the PMPI version
   since we're renaming the Fortran entry as the pmpi version.  The MPI name
   must be undefined first to prevent any conflicts with previous renamings. */
#undef MPI_Startall
#define MPI_Startall PMPI_Startall 

#else

#ifdef F77_NAME_UPPER
#define mpi_startall_ MPI_STARTALL
#elif defined(F77_NAME_LOWER_2USCORE)
#define mpi_startall_ mpi_startall__
#elif !defined(F77_NAME_LOWER_USCORE)
#define mpi_startall_ mpi_startall
/* Else leave name alone */
#endif


#endif /* MPICH_MPI_FROM_PMPI */

/* Prototypes for the Fortran interfaces */
#include "fproto.h"
FORT_DLL_SPEC void FORT_CALL mpi_startall_ ( MPI_Fint *v1, MPI_Fint v2[], MPI_Fint *ierr ){
    *ierr = MPI_Startall( (int)*v1, (MPI_Request *)(v2) );
}
