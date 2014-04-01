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
extern FORT_DLL_SPEC void FORT_CALL MPI_RPUT( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_rput__( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_rput( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_rput_( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#if defined(F77_NAME_UPPER)
#pragma weak MPI_RPUT = PMPI_RPUT
#pragma weak mpi_rput__ = PMPI_RPUT
#pragma weak mpi_rput_ = PMPI_RPUT
#pragma weak mpi_rput = PMPI_RPUT
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak MPI_RPUT = pmpi_rput__
#pragma weak mpi_rput__ = pmpi_rput__
#pragma weak mpi_rput_ = pmpi_rput__
#pragma weak mpi_rput = pmpi_rput__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak MPI_RPUT = pmpi_rput_
#pragma weak mpi_rput__ = pmpi_rput_
#pragma weak mpi_rput_ = pmpi_rput_
#pragma weak mpi_rput = pmpi_rput_
#else
#pragma weak MPI_RPUT = pmpi_rput
#pragma weak mpi_rput__ = pmpi_rput
#pragma weak mpi_rput_ = pmpi_rput
#pragma weak mpi_rput = pmpi_rput
#endif



#elif defined(HAVE_PRAGMA_WEAK)

#if defined(F77_NAME_UPPER)
extern FORT_DLL_SPEC void FORT_CALL MPI_RPUT( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak MPI_RPUT = PMPI_RPUT
#elif defined(F77_NAME_LOWER_2USCORE)
extern FORT_DLL_SPEC void FORT_CALL mpi_rput__( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak mpi_rput__ = pmpi_rput__
#elif !defined(F77_NAME_LOWER_USCORE)
extern FORT_DLL_SPEC void FORT_CALL mpi_rput( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak mpi_rput = pmpi_rput
#else
extern FORT_DLL_SPEC void FORT_CALL mpi_rput_( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak mpi_rput_ = pmpi_rput_
#endif

#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#if defined(F77_NAME_UPPER)
#pragma _HP_SECONDARY_DEF PMPI_RPUT  MPI_RPUT
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma _HP_SECONDARY_DEF pmpi_rput__  mpi_rput__
#elif !defined(F77_NAME_LOWER_USCORE)
#pragma _HP_SECONDARY_DEF pmpi_rput  mpi_rput
#else
#pragma _HP_SECONDARY_DEF pmpi_rput_  mpi_rput_
#endif

#elif defined(HAVE_PRAGMA_CRI_DUP)
#if defined(F77_NAME_UPPER)
#pragma _CRI duplicate MPI_RPUT as PMPI_RPUT
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma _CRI duplicate mpi_rput__ as pmpi_rput__
#elif !defined(F77_NAME_LOWER_USCORE)
#pragma _CRI duplicate mpi_rput as pmpi_rput
#else
#pragma _CRI duplicate mpi_rput_ as pmpi_rput_
#endif
#endif /* HAVE_PRAGMA_WEAK */
#endif /* USE_WEAK_SYMBOLS */
/* End MPI profiling block */


/* These definitions are used only for generating the Fortran wrappers */
#if defined(USE_WEAK_SYMBOLS) && defined(HAVE_MULTIPLE_PRAGMA_WEAK) && \
    defined(USE_ONLY_MPI_NAMES)
extern FORT_DLL_SPEC void FORT_CALL MPI_RPUT( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_rput__( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_rput( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_rput_( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#if defined(F77_NAME_UPPER)
#pragma weak mpi_rput__ = MPI_RPUT
#pragma weak mpi_rput_ = MPI_RPUT
#pragma weak mpi_rput = MPI_RPUT
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak MPI_RPUT = mpi_rput__
#pragma weak mpi_rput_ = mpi_rput__
#pragma weak mpi_rput = mpi_rput__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak MPI_RPUT = mpi_rput_
#pragma weak mpi_rput__ = mpi_rput_
#pragma weak mpi_rput = mpi_rput_
#else
#pragma weak MPI_RPUT = mpi_rput
#pragma weak mpi_rput__ = mpi_rput
#pragma weak mpi_rput_ = mpi_rput
#endif

#endif

/* Map the name to the correct form */
#ifndef MPICH_MPI_FROM_PMPI
#if defined(USE_WEAK_SYMBOLS) && defined(HAVE_MULTIPLE_PRAGMA_WEAK)
/* Define the weak versions of the PMPI routine*/
#ifndef F77_NAME_UPPER
extern FORT_DLL_SPEC void FORT_CALL PMPI_RPUT( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
#endif
#ifndef F77_NAME_LOWER_2USCORE
extern FORT_DLL_SPEC void FORT_CALL pmpi_rput__( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
#endif
#ifndef F77_NAME_LOWER_USCORE
extern FORT_DLL_SPEC void FORT_CALL pmpi_rput_( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
#endif
#ifndef F77_NAME_LOWER
extern FORT_DLL_SPEC void FORT_CALL pmpi_rput( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#endif

#if defined(F77_NAME_UPPER)
#pragma weak pmpi_rput__ = PMPI_RPUT
#pragma weak pmpi_rput_ = PMPI_RPUT
#pragma weak pmpi_rput = PMPI_RPUT
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak PMPI_RPUT = pmpi_rput__
#pragma weak pmpi_rput_ = pmpi_rput__
#pragma weak pmpi_rput = pmpi_rput__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak PMPI_RPUT = pmpi_rput_
#pragma weak pmpi_rput__ = pmpi_rput_
#pragma weak pmpi_rput = pmpi_rput_
#else
#pragma weak PMPI_RPUT = pmpi_rput
#pragma weak pmpi_rput__ = pmpi_rput
#pragma weak pmpi_rput_ = pmpi_rput
#endif /* Test on name mapping */
#endif /* Use multiple pragma weak */

#ifdef F77_NAME_UPPER
#define mpi_rput_ PMPI_RPUT
#elif defined(F77_NAME_LOWER_2USCORE)
#define mpi_rput_ pmpi_rput__
#elif !defined(F77_NAME_LOWER_USCORE)
#define mpi_rput_ pmpi_rput
#else
#define mpi_rput_ pmpi_rput_
#endif /* Test on name mapping */

/* This defines the routine that we call, which must be the PMPI version
   since we're renaming the Fortran entry as the pmpi version.  The MPI name
   must be undefined first to prevent any conflicts with previous renamings. */
#undef MPI_Rput
#define MPI_Rput PMPI_Rput 

#else

#ifdef F77_NAME_UPPER
#define mpi_rput_ MPI_RPUT
#elif defined(F77_NAME_LOWER_2USCORE)
#define mpi_rput_ mpi_rput__
#elif !defined(F77_NAME_LOWER_USCORE)
#define mpi_rput_ mpi_rput
/* Else leave name alone */
#endif


#endif /* MPICH_MPI_FROM_PMPI */

/* Prototypes for the Fortran interfaces */
#include "fproto.h"
FORT_DLL_SPEC void FORT_CALL mpi_rput_ ( void*v1, MPI_Fint *v2, MPI_Fint *v3, MPI_Fint *v4, MPI_Fint *v5, MPI_Fint *v6, MPI_Fint *v7, MPI_Fint *v8, MPI_Fint *v9, MPI_Fint *ierr ){
    *ierr = MPI_Rput( v1, (int)*v2, (MPI_Datatype)(*v3), (int)*v4, (MPI_Aint)*v5, (int)*v6, (MPI_Datatype)(*v7), (MPI_Win)*v8, (MPI_Request *)(v9) );
}