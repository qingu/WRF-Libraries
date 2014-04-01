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
extern FORT_DLL_SPEC void FORT_CALL MPI_SENDRECV( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_sendrecv__( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_sendrecv( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_sendrecv_( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#if defined(F77_NAME_UPPER)
#pragma weak MPI_SENDRECV = PMPI_SENDRECV
#pragma weak mpi_sendrecv__ = PMPI_SENDRECV
#pragma weak mpi_sendrecv_ = PMPI_SENDRECV
#pragma weak mpi_sendrecv = PMPI_SENDRECV
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak MPI_SENDRECV = pmpi_sendrecv__
#pragma weak mpi_sendrecv__ = pmpi_sendrecv__
#pragma weak mpi_sendrecv_ = pmpi_sendrecv__
#pragma weak mpi_sendrecv = pmpi_sendrecv__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak MPI_SENDRECV = pmpi_sendrecv_
#pragma weak mpi_sendrecv__ = pmpi_sendrecv_
#pragma weak mpi_sendrecv_ = pmpi_sendrecv_
#pragma weak mpi_sendrecv = pmpi_sendrecv_
#else
#pragma weak MPI_SENDRECV = pmpi_sendrecv
#pragma weak mpi_sendrecv__ = pmpi_sendrecv
#pragma weak mpi_sendrecv_ = pmpi_sendrecv
#pragma weak mpi_sendrecv = pmpi_sendrecv
#endif



#elif defined(HAVE_PRAGMA_WEAK)

#if defined(F77_NAME_UPPER)
extern FORT_DLL_SPEC void FORT_CALL MPI_SENDRECV( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak MPI_SENDRECV = PMPI_SENDRECV
#elif defined(F77_NAME_LOWER_2USCORE)
extern FORT_DLL_SPEC void FORT_CALL mpi_sendrecv__( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak mpi_sendrecv__ = pmpi_sendrecv__
#elif !defined(F77_NAME_LOWER_USCORE)
extern FORT_DLL_SPEC void FORT_CALL mpi_sendrecv( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak mpi_sendrecv = pmpi_sendrecv
#else
extern FORT_DLL_SPEC void FORT_CALL mpi_sendrecv_( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak mpi_sendrecv_ = pmpi_sendrecv_
#endif

#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#if defined(F77_NAME_UPPER)
#pragma _HP_SECONDARY_DEF PMPI_SENDRECV  MPI_SENDRECV
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma _HP_SECONDARY_DEF pmpi_sendrecv__  mpi_sendrecv__
#elif !defined(F77_NAME_LOWER_USCORE)
#pragma _HP_SECONDARY_DEF pmpi_sendrecv  mpi_sendrecv
#else
#pragma _HP_SECONDARY_DEF pmpi_sendrecv_  mpi_sendrecv_
#endif

#elif defined(HAVE_PRAGMA_CRI_DUP)
#if defined(F77_NAME_UPPER)
#pragma _CRI duplicate MPI_SENDRECV as PMPI_SENDRECV
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma _CRI duplicate mpi_sendrecv__ as pmpi_sendrecv__
#elif !defined(F77_NAME_LOWER_USCORE)
#pragma _CRI duplicate mpi_sendrecv as pmpi_sendrecv
#else
#pragma _CRI duplicate mpi_sendrecv_ as pmpi_sendrecv_
#endif
#endif /* HAVE_PRAGMA_WEAK */
#endif /* USE_WEAK_SYMBOLS */
/* End MPI profiling block */


/* These definitions are used only for generating the Fortran wrappers */
#if defined(USE_WEAK_SYMBOLS) && defined(HAVE_MULTIPLE_PRAGMA_WEAK) && \
    defined(USE_ONLY_MPI_NAMES)
extern FORT_DLL_SPEC void FORT_CALL MPI_SENDRECV( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_sendrecv__( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_sendrecv( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_sendrecv_( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#if defined(F77_NAME_UPPER)
#pragma weak mpi_sendrecv__ = MPI_SENDRECV
#pragma weak mpi_sendrecv_ = MPI_SENDRECV
#pragma weak mpi_sendrecv = MPI_SENDRECV
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak MPI_SENDRECV = mpi_sendrecv__
#pragma weak mpi_sendrecv_ = mpi_sendrecv__
#pragma weak mpi_sendrecv = mpi_sendrecv__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak MPI_SENDRECV = mpi_sendrecv_
#pragma weak mpi_sendrecv__ = mpi_sendrecv_
#pragma weak mpi_sendrecv = mpi_sendrecv_
#else
#pragma weak MPI_SENDRECV = mpi_sendrecv
#pragma weak mpi_sendrecv__ = mpi_sendrecv
#pragma weak mpi_sendrecv_ = mpi_sendrecv
#endif

#endif

/* Map the name to the correct form */
#ifndef MPICH_MPI_FROM_PMPI
#if defined(USE_WEAK_SYMBOLS) && defined(HAVE_MULTIPLE_PRAGMA_WEAK)
/* Define the weak versions of the PMPI routine*/
#ifndef F77_NAME_UPPER
extern FORT_DLL_SPEC void FORT_CALL PMPI_SENDRECV( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
#endif
#ifndef F77_NAME_LOWER_2USCORE
extern FORT_DLL_SPEC void FORT_CALL pmpi_sendrecv__( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
#endif
#ifndef F77_NAME_LOWER_USCORE
extern FORT_DLL_SPEC void FORT_CALL pmpi_sendrecv_( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
#endif
#ifndef F77_NAME_LOWER
extern FORT_DLL_SPEC void FORT_CALL pmpi_sendrecv( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#endif

#if defined(F77_NAME_UPPER)
#pragma weak pmpi_sendrecv__ = PMPI_SENDRECV
#pragma weak pmpi_sendrecv_ = PMPI_SENDRECV
#pragma weak pmpi_sendrecv = PMPI_SENDRECV
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak PMPI_SENDRECV = pmpi_sendrecv__
#pragma weak pmpi_sendrecv_ = pmpi_sendrecv__
#pragma weak pmpi_sendrecv = pmpi_sendrecv__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak PMPI_SENDRECV = pmpi_sendrecv_
#pragma weak pmpi_sendrecv__ = pmpi_sendrecv_
#pragma weak pmpi_sendrecv = pmpi_sendrecv_
#else
#pragma weak PMPI_SENDRECV = pmpi_sendrecv
#pragma weak pmpi_sendrecv__ = pmpi_sendrecv
#pragma weak pmpi_sendrecv_ = pmpi_sendrecv
#endif /* Test on name mapping */
#endif /* Use multiple pragma weak */

#ifdef F77_NAME_UPPER
#define mpi_sendrecv_ PMPI_SENDRECV
#elif defined(F77_NAME_LOWER_2USCORE)
#define mpi_sendrecv_ pmpi_sendrecv__
#elif !defined(F77_NAME_LOWER_USCORE)
#define mpi_sendrecv_ pmpi_sendrecv
#else
#define mpi_sendrecv_ pmpi_sendrecv_
#endif /* Test on name mapping */

/* This defines the routine that we call, which must be the PMPI version
   since we're renaming the Fortran entry as the pmpi version.  The MPI name
   must be undefined first to prevent any conflicts with previous renamings. */
#undef MPI_Sendrecv
#define MPI_Sendrecv PMPI_Sendrecv 

#else

#ifdef F77_NAME_UPPER
#define mpi_sendrecv_ MPI_SENDRECV
#elif defined(F77_NAME_LOWER_2USCORE)
#define mpi_sendrecv_ mpi_sendrecv__
#elif !defined(F77_NAME_LOWER_USCORE)
#define mpi_sendrecv_ mpi_sendrecv
/* Else leave name alone */
#endif


#endif /* MPICH_MPI_FROM_PMPI */

/* Prototypes for the Fortran interfaces */
#include "fproto.h"
FORT_DLL_SPEC void FORT_CALL mpi_sendrecv_ ( void*v1, MPI_Fint *v2, MPI_Fint *v3, MPI_Fint *v4, MPI_Fint *v5, void*v6, MPI_Fint *v7, MPI_Fint *v8, MPI_Fint *v9, MPI_Fint *v10, MPI_Fint *v11, MPI_Fint *v12, MPI_Fint *ierr ){

#ifndef HAVE_MPI_F_INIT_WORKS_WITH_C
    if (MPIR_F_NeedInit){ mpirinitf_(); MPIR_F_NeedInit = 0; }
#endif

    if (v12 == MPI_F_STATUS_IGNORE) { v12 = (MPI_Fint*)MPI_STATUS_IGNORE; }
    *ierr = MPI_Sendrecv( v1, (int)*v2, (MPI_Datatype)(*v3), (int)*v4, (int)*v5, v6, (int)*v7, (MPI_Datatype)(*v8), (int)*v9, (int)*v10, (MPI_Comm)(*v11), (MPI_Status *)v12 );
}
