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
extern FORT_DLL_SPEC void FORT_CALL MPI_COMPARE_AND_SWAP( void*, void*, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_compare_and_swap__( void*, void*, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_compare_and_swap( void*, void*, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_compare_and_swap_( void*, void*, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#if defined(F77_NAME_UPPER)
#pragma weak MPI_COMPARE_AND_SWAP = PMPI_COMPARE_AND_SWAP
#pragma weak mpi_compare_and_swap__ = PMPI_COMPARE_AND_SWAP
#pragma weak mpi_compare_and_swap_ = PMPI_COMPARE_AND_SWAP
#pragma weak mpi_compare_and_swap = PMPI_COMPARE_AND_SWAP
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak MPI_COMPARE_AND_SWAP = pmpi_compare_and_swap__
#pragma weak mpi_compare_and_swap__ = pmpi_compare_and_swap__
#pragma weak mpi_compare_and_swap_ = pmpi_compare_and_swap__
#pragma weak mpi_compare_and_swap = pmpi_compare_and_swap__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak MPI_COMPARE_AND_SWAP = pmpi_compare_and_swap_
#pragma weak mpi_compare_and_swap__ = pmpi_compare_and_swap_
#pragma weak mpi_compare_and_swap_ = pmpi_compare_and_swap_
#pragma weak mpi_compare_and_swap = pmpi_compare_and_swap_
#else
#pragma weak MPI_COMPARE_AND_SWAP = pmpi_compare_and_swap
#pragma weak mpi_compare_and_swap__ = pmpi_compare_and_swap
#pragma weak mpi_compare_and_swap_ = pmpi_compare_and_swap
#pragma weak mpi_compare_and_swap = pmpi_compare_and_swap
#endif



#elif defined(HAVE_PRAGMA_WEAK)

#if defined(F77_NAME_UPPER)
extern FORT_DLL_SPEC void FORT_CALL MPI_COMPARE_AND_SWAP( void*, void*, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak MPI_COMPARE_AND_SWAP = PMPI_COMPARE_AND_SWAP
#elif defined(F77_NAME_LOWER_2USCORE)
extern FORT_DLL_SPEC void FORT_CALL mpi_compare_and_swap__( void*, void*, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak mpi_compare_and_swap__ = pmpi_compare_and_swap__
#elif !defined(F77_NAME_LOWER_USCORE)
extern FORT_DLL_SPEC void FORT_CALL mpi_compare_and_swap( void*, void*, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak mpi_compare_and_swap = pmpi_compare_and_swap
#else
extern FORT_DLL_SPEC void FORT_CALL mpi_compare_and_swap_( void*, void*, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak mpi_compare_and_swap_ = pmpi_compare_and_swap_
#endif

#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#if defined(F77_NAME_UPPER)
#pragma _HP_SECONDARY_DEF PMPI_COMPARE_AND_SWAP  MPI_COMPARE_AND_SWAP
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma _HP_SECONDARY_DEF pmpi_compare_and_swap__  mpi_compare_and_swap__
#elif !defined(F77_NAME_LOWER_USCORE)
#pragma _HP_SECONDARY_DEF pmpi_compare_and_swap  mpi_compare_and_swap
#else
#pragma _HP_SECONDARY_DEF pmpi_compare_and_swap_  mpi_compare_and_swap_
#endif

#elif defined(HAVE_PRAGMA_CRI_DUP)
#if defined(F77_NAME_UPPER)
#pragma _CRI duplicate MPI_COMPARE_AND_SWAP as PMPI_COMPARE_AND_SWAP
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma _CRI duplicate mpi_compare_and_swap__ as pmpi_compare_and_swap__
#elif !defined(F77_NAME_LOWER_USCORE)
#pragma _CRI duplicate mpi_compare_and_swap as pmpi_compare_and_swap
#else
#pragma _CRI duplicate mpi_compare_and_swap_ as pmpi_compare_and_swap_
#endif
#endif /* HAVE_PRAGMA_WEAK */
#endif /* USE_WEAK_SYMBOLS */
/* End MPI profiling block */


/* These definitions are used only for generating the Fortran wrappers */
#if defined(USE_WEAK_SYMBOLS) && defined(HAVE_MULTIPLE_PRAGMA_WEAK) && \
    defined(USE_ONLY_MPI_NAMES)
extern FORT_DLL_SPEC void FORT_CALL MPI_COMPARE_AND_SWAP( void*, void*, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_compare_and_swap__( void*, void*, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_compare_and_swap( void*, void*, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_compare_and_swap_( void*, void*, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#if defined(F77_NAME_UPPER)
#pragma weak mpi_compare_and_swap__ = MPI_COMPARE_AND_SWAP
#pragma weak mpi_compare_and_swap_ = MPI_COMPARE_AND_SWAP
#pragma weak mpi_compare_and_swap = MPI_COMPARE_AND_SWAP
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak MPI_COMPARE_AND_SWAP = mpi_compare_and_swap__
#pragma weak mpi_compare_and_swap_ = mpi_compare_and_swap__
#pragma weak mpi_compare_and_swap = mpi_compare_and_swap__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak MPI_COMPARE_AND_SWAP = mpi_compare_and_swap_
#pragma weak mpi_compare_and_swap__ = mpi_compare_and_swap_
#pragma weak mpi_compare_and_swap = mpi_compare_and_swap_
#else
#pragma weak MPI_COMPARE_AND_SWAP = mpi_compare_and_swap
#pragma weak mpi_compare_and_swap__ = mpi_compare_and_swap
#pragma weak mpi_compare_and_swap_ = mpi_compare_and_swap
#endif

#endif

/* Map the name to the correct form */
#ifndef MPICH_MPI_FROM_PMPI
#if defined(USE_WEAK_SYMBOLS) && defined(HAVE_MULTIPLE_PRAGMA_WEAK)
/* Define the weak versions of the PMPI routine*/
#ifndef F77_NAME_UPPER
extern FORT_DLL_SPEC void FORT_CALL PMPI_COMPARE_AND_SWAP( void*, void*, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
#endif
#ifndef F77_NAME_LOWER_2USCORE
extern FORT_DLL_SPEC void FORT_CALL pmpi_compare_and_swap__( void*, void*, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
#endif
#ifndef F77_NAME_LOWER_USCORE
extern FORT_DLL_SPEC void FORT_CALL pmpi_compare_and_swap_( void*, void*, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
#endif
#ifndef F77_NAME_LOWER
extern FORT_DLL_SPEC void FORT_CALL pmpi_compare_and_swap( void*, void*, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#endif

#if defined(F77_NAME_UPPER)
#pragma weak pmpi_compare_and_swap__ = PMPI_COMPARE_AND_SWAP
#pragma weak pmpi_compare_and_swap_ = PMPI_COMPARE_AND_SWAP
#pragma weak pmpi_compare_and_swap = PMPI_COMPARE_AND_SWAP
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak PMPI_COMPARE_AND_SWAP = pmpi_compare_and_swap__
#pragma weak pmpi_compare_and_swap_ = pmpi_compare_and_swap__
#pragma weak pmpi_compare_and_swap = pmpi_compare_and_swap__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak PMPI_COMPARE_AND_SWAP = pmpi_compare_and_swap_
#pragma weak pmpi_compare_and_swap__ = pmpi_compare_and_swap_
#pragma weak pmpi_compare_and_swap = pmpi_compare_and_swap_
#else
#pragma weak PMPI_COMPARE_AND_SWAP = pmpi_compare_and_swap
#pragma weak pmpi_compare_and_swap__ = pmpi_compare_and_swap
#pragma weak pmpi_compare_and_swap_ = pmpi_compare_and_swap
#endif /* Test on name mapping */
#endif /* Use multiple pragma weak */

#ifdef F77_NAME_UPPER
#define mpi_compare_and_swap_ PMPI_COMPARE_AND_SWAP
#elif defined(F77_NAME_LOWER_2USCORE)
#define mpi_compare_and_swap_ pmpi_compare_and_swap__
#elif !defined(F77_NAME_LOWER_USCORE)
#define mpi_compare_and_swap_ pmpi_compare_and_swap
#else
#define mpi_compare_and_swap_ pmpi_compare_and_swap_
#endif /* Test on name mapping */

/* This defines the routine that we call, which must be the PMPI version
   since we're renaming the Fortran entry as the pmpi version.  The MPI name
   must be undefined first to prevent any conflicts with previous renamings. */
#undef MPI_Compare_and_swap
#define MPI_Compare_and_swap PMPI_Compare_and_swap 

#else

#ifdef F77_NAME_UPPER
#define mpi_compare_and_swap_ MPI_COMPARE_AND_SWAP
#elif defined(F77_NAME_LOWER_2USCORE)
#define mpi_compare_and_swap_ mpi_compare_and_swap__
#elif !defined(F77_NAME_LOWER_USCORE)
#define mpi_compare_and_swap_ mpi_compare_and_swap
/* Else leave name alone */
#endif


#endif /* MPICH_MPI_FROM_PMPI */

/* Prototypes for the Fortran interfaces */
#include "fproto.h"
FORT_DLL_SPEC void FORT_CALL mpi_compare_and_swap_ ( void*v1, void*v2, void*v3, MPI_Fint *v4, MPI_Fint *v5, MPI_Fint *v6, MPI_Fint *v7, MPI_Fint *ierr ){
    *ierr = MPI_Compare_and_swap( v1, v2, v3, (MPI_Datatype)(*v4), (int)*v5, (MPI_Aint)*v6, (MPI_Win)*v7 );
}