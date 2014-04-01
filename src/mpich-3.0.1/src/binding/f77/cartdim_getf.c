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
extern FORT_DLL_SPEC void FORT_CALL MPI_CARTDIM_GET( MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_cartdim_get__( MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_cartdim_get( MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_cartdim_get_( MPI_Fint *, MPI_Fint *, MPI_Fint * );

#if defined(F77_NAME_UPPER)
#pragma weak MPI_CARTDIM_GET = PMPI_CARTDIM_GET
#pragma weak mpi_cartdim_get__ = PMPI_CARTDIM_GET
#pragma weak mpi_cartdim_get_ = PMPI_CARTDIM_GET
#pragma weak mpi_cartdim_get = PMPI_CARTDIM_GET
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak MPI_CARTDIM_GET = pmpi_cartdim_get__
#pragma weak mpi_cartdim_get__ = pmpi_cartdim_get__
#pragma weak mpi_cartdim_get_ = pmpi_cartdim_get__
#pragma weak mpi_cartdim_get = pmpi_cartdim_get__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak MPI_CARTDIM_GET = pmpi_cartdim_get_
#pragma weak mpi_cartdim_get__ = pmpi_cartdim_get_
#pragma weak mpi_cartdim_get_ = pmpi_cartdim_get_
#pragma weak mpi_cartdim_get = pmpi_cartdim_get_
#else
#pragma weak MPI_CARTDIM_GET = pmpi_cartdim_get
#pragma weak mpi_cartdim_get__ = pmpi_cartdim_get
#pragma weak mpi_cartdim_get_ = pmpi_cartdim_get
#pragma weak mpi_cartdim_get = pmpi_cartdim_get
#endif



#elif defined(HAVE_PRAGMA_WEAK)

#if defined(F77_NAME_UPPER)
extern FORT_DLL_SPEC void FORT_CALL MPI_CARTDIM_GET( MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak MPI_CARTDIM_GET = PMPI_CARTDIM_GET
#elif defined(F77_NAME_LOWER_2USCORE)
extern FORT_DLL_SPEC void FORT_CALL mpi_cartdim_get__( MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak mpi_cartdim_get__ = pmpi_cartdim_get__
#elif !defined(F77_NAME_LOWER_USCORE)
extern FORT_DLL_SPEC void FORT_CALL mpi_cartdim_get( MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak mpi_cartdim_get = pmpi_cartdim_get
#else
extern FORT_DLL_SPEC void FORT_CALL mpi_cartdim_get_( MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak mpi_cartdim_get_ = pmpi_cartdim_get_
#endif

#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#if defined(F77_NAME_UPPER)
#pragma _HP_SECONDARY_DEF PMPI_CARTDIM_GET  MPI_CARTDIM_GET
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma _HP_SECONDARY_DEF pmpi_cartdim_get__  mpi_cartdim_get__
#elif !defined(F77_NAME_LOWER_USCORE)
#pragma _HP_SECONDARY_DEF pmpi_cartdim_get  mpi_cartdim_get
#else
#pragma _HP_SECONDARY_DEF pmpi_cartdim_get_  mpi_cartdim_get_
#endif

#elif defined(HAVE_PRAGMA_CRI_DUP)
#if defined(F77_NAME_UPPER)
#pragma _CRI duplicate MPI_CARTDIM_GET as PMPI_CARTDIM_GET
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma _CRI duplicate mpi_cartdim_get__ as pmpi_cartdim_get__
#elif !defined(F77_NAME_LOWER_USCORE)
#pragma _CRI duplicate mpi_cartdim_get as pmpi_cartdim_get
#else
#pragma _CRI duplicate mpi_cartdim_get_ as pmpi_cartdim_get_
#endif
#endif /* HAVE_PRAGMA_WEAK */
#endif /* USE_WEAK_SYMBOLS */
/* End MPI profiling block */


/* These definitions are used only for generating the Fortran wrappers */
#if defined(USE_WEAK_SYMBOLS) && defined(HAVE_MULTIPLE_PRAGMA_WEAK) && \
    defined(USE_ONLY_MPI_NAMES)
extern FORT_DLL_SPEC void FORT_CALL MPI_CARTDIM_GET( MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_cartdim_get__( MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_cartdim_get( MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_cartdim_get_( MPI_Fint *, MPI_Fint *, MPI_Fint * );

#if defined(F77_NAME_UPPER)
#pragma weak mpi_cartdim_get__ = MPI_CARTDIM_GET
#pragma weak mpi_cartdim_get_ = MPI_CARTDIM_GET
#pragma weak mpi_cartdim_get = MPI_CARTDIM_GET
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak MPI_CARTDIM_GET = mpi_cartdim_get__
#pragma weak mpi_cartdim_get_ = mpi_cartdim_get__
#pragma weak mpi_cartdim_get = mpi_cartdim_get__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak MPI_CARTDIM_GET = mpi_cartdim_get_
#pragma weak mpi_cartdim_get__ = mpi_cartdim_get_
#pragma weak mpi_cartdim_get = mpi_cartdim_get_
#else
#pragma weak MPI_CARTDIM_GET = mpi_cartdim_get
#pragma weak mpi_cartdim_get__ = mpi_cartdim_get
#pragma weak mpi_cartdim_get_ = mpi_cartdim_get
#endif

#endif

/* Map the name to the correct form */
#ifndef MPICH_MPI_FROM_PMPI
#if defined(USE_WEAK_SYMBOLS) && defined(HAVE_MULTIPLE_PRAGMA_WEAK)
/* Define the weak versions of the PMPI routine*/
#ifndef F77_NAME_UPPER
extern FORT_DLL_SPEC void FORT_CALL PMPI_CARTDIM_GET( MPI_Fint *, MPI_Fint *, MPI_Fint * );
#endif
#ifndef F77_NAME_LOWER_2USCORE
extern FORT_DLL_SPEC void FORT_CALL pmpi_cartdim_get__( MPI_Fint *, MPI_Fint *, MPI_Fint * );
#endif
#ifndef F77_NAME_LOWER_USCORE
extern FORT_DLL_SPEC void FORT_CALL pmpi_cartdim_get_( MPI_Fint *, MPI_Fint *, MPI_Fint * );
#endif
#ifndef F77_NAME_LOWER
extern FORT_DLL_SPEC void FORT_CALL pmpi_cartdim_get( MPI_Fint *, MPI_Fint *, MPI_Fint * );

#endif

#if defined(F77_NAME_UPPER)
#pragma weak pmpi_cartdim_get__ = PMPI_CARTDIM_GET
#pragma weak pmpi_cartdim_get_ = PMPI_CARTDIM_GET
#pragma weak pmpi_cartdim_get = PMPI_CARTDIM_GET
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak PMPI_CARTDIM_GET = pmpi_cartdim_get__
#pragma weak pmpi_cartdim_get_ = pmpi_cartdim_get__
#pragma weak pmpi_cartdim_get = pmpi_cartdim_get__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak PMPI_CARTDIM_GET = pmpi_cartdim_get_
#pragma weak pmpi_cartdim_get__ = pmpi_cartdim_get_
#pragma weak pmpi_cartdim_get = pmpi_cartdim_get_
#else
#pragma weak PMPI_CARTDIM_GET = pmpi_cartdim_get
#pragma weak pmpi_cartdim_get__ = pmpi_cartdim_get
#pragma weak pmpi_cartdim_get_ = pmpi_cartdim_get
#endif /* Test on name mapping */
#endif /* Use multiple pragma weak */

#ifdef F77_NAME_UPPER
#define mpi_cartdim_get_ PMPI_CARTDIM_GET
#elif defined(F77_NAME_LOWER_2USCORE)
#define mpi_cartdim_get_ pmpi_cartdim_get__
#elif !defined(F77_NAME_LOWER_USCORE)
#define mpi_cartdim_get_ pmpi_cartdim_get
#else
#define mpi_cartdim_get_ pmpi_cartdim_get_
#endif /* Test on name mapping */

/* This defines the routine that we call, which must be the PMPI version
   since we're renaming the Fortran entry as the pmpi version.  The MPI name
   must be undefined first to prevent any conflicts with previous renamings. */
#undef MPI_Cartdim_get
#define MPI_Cartdim_get PMPI_Cartdim_get 

#else

#ifdef F77_NAME_UPPER
#define mpi_cartdim_get_ MPI_CARTDIM_GET
#elif defined(F77_NAME_LOWER_2USCORE)
#define mpi_cartdim_get_ mpi_cartdim_get__
#elif !defined(F77_NAME_LOWER_USCORE)
#define mpi_cartdim_get_ mpi_cartdim_get
/* Else leave name alone */
#endif


#endif /* MPICH_MPI_FROM_PMPI */

/* Prototypes for the Fortran interfaces */
#include "fproto.h"
FORT_DLL_SPEC void FORT_CALL mpi_cartdim_get_ ( MPI_Fint *v1, MPI_Fint *v2, MPI_Fint *ierr ){
    *ierr = MPI_Cartdim_get( (MPI_Comm)(*v1), v2 );
}