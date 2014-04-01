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
extern FORT_DLL_SPEC void FORT_CALL MPI_INTERCOMM_MERGE( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_intercomm_merge__( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_intercomm_merge( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_intercomm_merge_( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#if defined(F77_NAME_UPPER)
#pragma weak MPI_INTERCOMM_MERGE = PMPI_INTERCOMM_MERGE
#pragma weak mpi_intercomm_merge__ = PMPI_INTERCOMM_MERGE
#pragma weak mpi_intercomm_merge_ = PMPI_INTERCOMM_MERGE
#pragma weak mpi_intercomm_merge = PMPI_INTERCOMM_MERGE
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak MPI_INTERCOMM_MERGE = pmpi_intercomm_merge__
#pragma weak mpi_intercomm_merge__ = pmpi_intercomm_merge__
#pragma weak mpi_intercomm_merge_ = pmpi_intercomm_merge__
#pragma weak mpi_intercomm_merge = pmpi_intercomm_merge__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak MPI_INTERCOMM_MERGE = pmpi_intercomm_merge_
#pragma weak mpi_intercomm_merge__ = pmpi_intercomm_merge_
#pragma weak mpi_intercomm_merge_ = pmpi_intercomm_merge_
#pragma weak mpi_intercomm_merge = pmpi_intercomm_merge_
#else
#pragma weak MPI_INTERCOMM_MERGE = pmpi_intercomm_merge
#pragma weak mpi_intercomm_merge__ = pmpi_intercomm_merge
#pragma weak mpi_intercomm_merge_ = pmpi_intercomm_merge
#pragma weak mpi_intercomm_merge = pmpi_intercomm_merge
#endif



#elif defined(HAVE_PRAGMA_WEAK)

#if defined(F77_NAME_UPPER)
extern FORT_DLL_SPEC void FORT_CALL MPI_INTERCOMM_MERGE( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak MPI_INTERCOMM_MERGE = PMPI_INTERCOMM_MERGE
#elif defined(F77_NAME_LOWER_2USCORE)
extern FORT_DLL_SPEC void FORT_CALL mpi_intercomm_merge__( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak mpi_intercomm_merge__ = pmpi_intercomm_merge__
#elif !defined(F77_NAME_LOWER_USCORE)
extern FORT_DLL_SPEC void FORT_CALL mpi_intercomm_merge( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak mpi_intercomm_merge = pmpi_intercomm_merge
#else
extern FORT_DLL_SPEC void FORT_CALL mpi_intercomm_merge_( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak mpi_intercomm_merge_ = pmpi_intercomm_merge_
#endif

#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#if defined(F77_NAME_UPPER)
#pragma _HP_SECONDARY_DEF PMPI_INTERCOMM_MERGE  MPI_INTERCOMM_MERGE
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma _HP_SECONDARY_DEF pmpi_intercomm_merge__  mpi_intercomm_merge__
#elif !defined(F77_NAME_LOWER_USCORE)
#pragma _HP_SECONDARY_DEF pmpi_intercomm_merge  mpi_intercomm_merge
#else
#pragma _HP_SECONDARY_DEF pmpi_intercomm_merge_  mpi_intercomm_merge_
#endif

#elif defined(HAVE_PRAGMA_CRI_DUP)
#if defined(F77_NAME_UPPER)
#pragma _CRI duplicate MPI_INTERCOMM_MERGE as PMPI_INTERCOMM_MERGE
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma _CRI duplicate mpi_intercomm_merge__ as pmpi_intercomm_merge__
#elif !defined(F77_NAME_LOWER_USCORE)
#pragma _CRI duplicate mpi_intercomm_merge as pmpi_intercomm_merge
#else
#pragma _CRI duplicate mpi_intercomm_merge_ as pmpi_intercomm_merge_
#endif
#endif /* HAVE_PRAGMA_WEAK */
#endif /* USE_WEAK_SYMBOLS */
/* End MPI profiling block */


/* These definitions are used only for generating the Fortran wrappers */
#if defined(USE_WEAK_SYMBOLS) && defined(HAVE_MULTIPLE_PRAGMA_WEAK) && \
    defined(USE_ONLY_MPI_NAMES)
extern FORT_DLL_SPEC void FORT_CALL MPI_INTERCOMM_MERGE( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_intercomm_merge__( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_intercomm_merge( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_intercomm_merge_( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#if defined(F77_NAME_UPPER)
#pragma weak mpi_intercomm_merge__ = MPI_INTERCOMM_MERGE
#pragma weak mpi_intercomm_merge_ = MPI_INTERCOMM_MERGE
#pragma weak mpi_intercomm_merge = MPI_INTERCOMM_MERGE
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak MPI_INTERCOMM_MERGE = mpi_intercomm_merge__
#pragma weak mpi_intercomm_merge_ = mpi_intercomm_merge__
#pragma weak mpi_intercomm_merge = mpi_intercomm_merge__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak MPI_INTERCOMM_MERGE = mpi_intercomm_merge_
#pragma weak mpi_intercomm_merge__ = mpi_intercomm_merge_
#pragma weak mpi_intercomm_merge = mpi_intercomm_merge_
#else
#pragma weak MPI_INTERCOMM_MERGE = mpi_intercomm_merge
#pragma weak mpi_intercomm_merge__ = mpi_intercomm_merge
#pragma weak mpi_intercomm_merge_ = mpi_intercomm_merge
#endif

#endif

/* Map the name to the correct form */
#ifndef MPICH_MPI_FROM_PMPI
#if defined(USE_WEAK_SYMBOLS) && defined(HAVE_MULTIPLE_PRAGMA_WEAK)
/* Define the weak versions of the PMPI routine*/
#ifndef F77_NAME_UPPER
extern FORT_DLL_SPEC void FORT_CALL PMPI_INTERCOMM_MERGE( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
#endif
#ifndef F77_NAME_LOWER_2USCORE
extern FORT_DLL_SPEC void FORT_CALL pmpi_intercomm_merge__( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
#endif
#ifndef F77_NAME_LOWER_USCORE
extern FORT_DLL_SPEC void FORT_CALL pmpi_intercomm_merge_( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
#endif
#ifndef F77_NAME_LOWER
extern FORT_DLL_SPEC void FORT_CALL pmpi_intercomm_merge( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#endif

#if defined(F77_NAME_UPPER)
#pragma weak pmpi_intercomm_merge__ = PMPI_INTERCOMM_MERGE
#pragma weak pmpi_intercomm_merge_ = PMPI_INTERCOMM_MERGE
#pragma weak pmpi_intercomm_merge = PMPI_INTERCOMM_MERGE
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak PMPI_INTERCOMM_MERGE = pmpi_intercomm_merge__
#pragma weak pmpi_intercomm_merge_ = pmpi_intercomm_merge__
#pragma weak pmpi_intercomm_merge = pmpi_intercomm_merge__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak PMPI_INTERCOMM_MERGE = pmpi_intercomm_merge_
#pragma weak pmpi_intercomm_merge__ = pmpi_intercomm_merge_
#pragma weak pmpi_intercomm_merge = pmpi_intercomm_merge_
#else
#pragma weak PMPI_INTERCOMM_MERGE = pmpi_intercomm_merge
#pragma weak pmpi_intercomm_merge__ = pmpi_intercomm_merge
#pragma weak pmpi_intercomm_merge_ = pmpi_intercomm_merge
#endif /* Test on name mapping */
#endif /* Use multiple pragma weak */

#ifdef F77_NAME_UPPER
#define mpi_intercomm_merge_ PMPI_INTERCOMM_MERGE
#elif defined(F77_NAME_LOWER_2USCORE)
#define mpi_intercomm_merge_ pmpi_intercomm_merge__
#elif !defined(F77_NAME_LOWER_USCORE)
#define mpi_intercomm_merge_ pmpi_intercomm_merge
#else
#define mpi_intercomm_merge_ pmpi_intercomm_merge_
#endif /* Test on name mapping */

/* This defines the routine that we call, which must be the PMPI version
   since we're renaming the Fortran entry as the pmpi version.  The MPI name
   must be undefined first to prevent any conflicts with previous renamings. */
#undef MPI_Intercomm_merge
#define MPI_Intercomm_merge PMPI_Intercomm_merge 

#else

#ifdef F77_NAME_UPPER
#define mpi_intercomm_merge_ MPI_INTERCOMM_MERGE
#elif defined(F77_NAME_LOWER_2USCORE)
#define mpi_intercomm_merge_ mpi_intercomm_merge__
#elif !defined(F77_NAME_LOWER_USCORE)
#define mpi_intercomm_merge_ mpi_intercomm_merge
/* Else leave name alone */
#endif


#endif /* MPICH_MPI_FROM_PMPI */

/* Prototypes for the Fortran interfaces */
#include "fproto.h"
FORT_DLL_SPEC void FORT_CALL mpi_intercomm_merge_ ( MPI_Fint *v1, MPI_Fint *v2, MPI_Fint *v3, MPI_Fint *ierr ){
    int l2;
    l2 = MPIR_FROM_FLOG(*v2);
    *ierr = MPI_Intercomm_merge( (MPI_Comm)(*v1), l2, (MPI_Comm *)(v3) );
}
