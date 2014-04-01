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
extern FORT_DLL_SPEC void FORT_CALL MPI_TYPE_HINDEXED( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_type_hindexed__( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_type_hindexed( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_type_hindexed_( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#if defined(F77_NAME_UPPER)
#pragma weak MPI_TYPE_HINDEXED = PMPI_TYPE_HINDEXED
#pragma weak mpi_type_hindexed__ = PMPI_TYPE_HINDEXED
#pragma weak mpi_type_hindexed_ = PMPI_TYPE_HINDEXED
#pragma weak mpi_type_hindexed = PMPI_TYPE_HINDEXED
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak MPI_TYPE_HINDEXED = pmpi_type_hindexed__
#pragma weak mpi_type_hindexed__ = pmpi_type_hindexed__
#pragma weak mpi_type_hindexed_ = pmpi_type_hindexed__
#pragma weak mpi_type_hindexed = pmpi_type_hindexed__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak MPI_TYPE_HINDEXED = pmpi_type_hindexed_
#pragma weak mpi_type_hindexed__ = pmpi_type_hindexed_
#pragma weak mpi_type_hindexed_ = pmpi_type_hindexed_
#pragma weak mpi_type_hindexed = pmpi_type_hindexed_
#else
#pragma weak MPI_TYPE_HINDEXED = pmpi_type_hindexed
#pragma weak mpi_type_hindexed__ = pmpi_type_hindexed
#pragma weak mpi_type_hindexed_ = pmpi_type_hindexed
#pragma weak mpi_type_hindexed = pmpi_type_hindexed
#endif



#elif defined(HAVE_PRAGMA_WEAK)

#if defined(F77_NAME_UPPER)
extern FORT_DLL_SPEC void FORT_CALL MPI_TYPE_HINDEXED( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak MPI_TYPE_HINDEXED = PMPI_TYPE_HINDEXED
#elif defined(F77_NAME_LOWER_2USCORE)
extern FORT_DLL_SPEC void FORT_CALL mpi_type_hindexed__( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak mpi_type_hindexed__ = pmpi_type_hindexed__
#elif !defined(F77_NAME_LOWER_USCORE)
extern FORT_DLL_SPEC void FORT_CALL mpi_type_hindexed( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak mpi_type_hindexed = pmpi_type_hindexed
#else
extern FORT_DLL_SPEC void FORT_CALL mpi_type_hindexed_( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak mpi_type_hindexed_ = pmpi_type_hindexed_
#endif

#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#if defined(F77_NAME_UPPER)
#pragma _HP_SECONDARY_DEF PMPI_TYPE_HINDEXED  MPI_TYPE_HINDEXED
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma _HP_SECONDARY_DEF pmpi_type_hindexed__  mpi_type_hindexed__
#elif !defined(F77_NAME_LOWER_USCORE)
#pragma _HP_SECONDARY_DEF pmpi_type_hindexed  mpi_type_hindexed
#else
#pragma _HP_SECONDARY_DEF pmpi_type_hindexed_  mpi_type_hindexed_
#endif

#elif defined(HAVE_PRAGMA_CRI_DUP)
#if defined(F77_NAME_UPPER)
#pragma _CRI duplicate MPI_TYPE_HINDEXED as PMPI_TYPE_HINDEXED
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma _CRI duplicate mpi_type_hindexed__ as pmpi_type_hindexed__
#elif !defined(F77_NAME_LOWER_USCORE)
#pragma _CRI duplicate mpi_type_hindexed as pmpi_type_hindexed
#else
#pragma _CRI duplicate mpi_type_hindexed_ as pmpi_type_hindexed_
#endif
#endif /* HAVE_PRAGMA_WEAK */
#endif /* USE_WEAK_SYMBOLS */
/* End MPI profiling block */


/* These definitions are used only for generating the Fortran wrappers */
#if defined(USE_WEAK_SYMBOLS) && defined(HAVE_MULTIPLE_PRAGMA_WEAK) && \
    defined(USE_ONLY_MPI_NAMES)
extern FORT_DLL_SPEC void FORT_CALL MPI_TYPE_HINDEXED( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_type_hindexed__( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_type_hindexed( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_type_hindexed_( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#if defined(F77_NAME_UPPER)
#pragma weak mpi_type_hindexed__ = MPI_TYPE_HINDEXED
#pragma weak mpi_type_hindexed_ = MPI_TYPE_HINDEXED
#pragma weak mpi_type_hindexed = MPI_TYPE_HINDEXED
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak MPI_TYPE_HINDEXED = mpi_type_hindexed__
#pragma weak mpi_type_hindexed_ = mpi_type_hindexed__
#pragma weak mpi_type_hindexed = mpi_type_hindexed__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak MPI_TYPE_HINDEXED = mpi_type_hindexed_
#pragma weak mpi_type_hindexed__ = mpi_type_hindexed_
#pragma weak mpi_type_hindexed = mpi_type_hindexed_
#else
#pragma weak MPI_TYPE_HINDEXED = mpi_type_hindexed
#pragma weak mpi_type_hindexed__ = mpi_type_hindexed
#pragma weak mpi_type_hindexed_ = mpi_type_hindexed
#endif

#endif

/* Map the name to the correct form */
#ifndef MPICH_MPI_FROM_PMPI
#if defined(USE_WEAK_SYMBOLS) && defined(HAVE_MULTIPLE_PRAGMA_WEAK)
/* Define the weak versions of the PMPI routine*/
#ifndef F77_NAME_UPPER
extern FORT_DLL_SPEC void FORT_CALL PMPI_TYPE_HINDEXED( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
#endif
#ifndef F77_NAME_LOWER_2USCORE
extern FORT_DLL_SPEC void FORT_CALL pmpi_type_hindexed__( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
#endif
#ifndef F77_NAME_LOWER_USCORE
extern FORT_DLL_SPEC void FORT_CALL pmpi_type_hindexed_( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
#endif
#ifndef F77_NAME_LOWER
extern FORT_DLL_SPEC void FORT_CALL pmpi_type_hindexed( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#endif

#if defined(F77_NAME_UPPER)
#pragma weak pmpi_type_hindexed__ = PMPI_TYPE_HINDEXED
#pragma weak pmpi_type_hindexed_ = PMPI_TYPE_HINDEXED
#pragma weak pmpi_type_hindexed = PMPI_TYPE_HINDEXED
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak PMPI_TYPE_HINDEXED = pmpi_type_hindexed__
#pragma weak pmpi_type_hindexed_ = pmpi_type_hindexed__
#pragma weak pmpi_type_hindexed = pmpi_type_hindexed__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak PMPI_TYPE_HINDEXED = pmpi_type_hindexed_
#pragma weak pmpi_type_hindexed__ = pmpi_type_hindexed_
#pragma weak pmpi_type_hindexed = pmpi_type_hindexed_
#else
#pragma weak PMPI_TYPE_HINDEXED = pmpi_type_hindexed
#pragma weak pmpi_type_hindexed__ = pmpi_type_hindexed
#pragma weak pmpi_type_hindexed_ = pmpi_type_hindexed
#endif /* Test on name mapping */
#endif /* Use multiple pragma weak */

#ifdef F77_NAME_UPPER
#define mpi_type_hindexed_ PMPI_TYPE_HINDEXED
#elif defined(F77_NAME_LOWER_2USCORE)
#define mpi_type_hindexed_ pmpi_type_hindexed__
#elif !defined(F77_NAME_LOWER_USCORE)
#define mpi_type_hindexed_ pmpi_type_hindexed
#else
#define mpi_type_hindexed_ pmpi_type_hindexed_
#endif /* Test on name mapping */

/* This defines the routine that we call, which must be the PMPI version
   since we're renaming the Fortran entry as the pmpi version.  The MPI name
   must be undefined first to prevent any conflicts with previous renamings. */
#undef MPI_Type_hindexed
#define MPI_Type_hindexed PMPI_Type_hindexed 

#else

#ifdef F77_NAME_UPPER
#define mpi_type_hindexed_ MPI_TYPE_HINDEXED
#elif defined(F77_NAME_LOWER_2USCORE)
#define mpi_type_hindexed_ mpi_type_hindexed__
#elif !defined(F77_NAME_LOWER_USCORE)
#define mpi_type_hindexed_ mpi_type_hindexed
/* Else leave name alone */
#endif


#endif /* MPICH_MPI_FROM_PMPI */

/* Prototypes for the Fortran interfaces */
#include "fproto.h"
FORT_DLL_SPEC void FORT_CALL mpi_type_hindexed_ ( MPI_Fint *v1, MPI_Fint *v2, MPI_Fint * v3, MPI_Fint *v4, MPI_Fint *v5, MPI_Fint *ierr ){
    MPI_Aint *l3;

#ifdef HAVE_AINT_LARGER_THAN_FINT

    if (*v1 > 0) {
        int li;
        l3 = (MPI_Aint *)MPIU_Malloc( *v1 * sizeof(MPI_Aint) );
        for (li=0; li<*v1; li++) 
            l3[li] = v3[li];
    }
    else l3 = 0;
#else 
    l3 = v3;
#endif
    *ierr = MPI_Type_hindexed( (int)*v1, v2, l3, (MPI_Datatype)(*v4), (MPI_Datatype *)(v5) );

#ifdef HAVE_AINT_LARGER_THAN_FINT
    if (l3) { MPIU_Free(l3); }
#endif
}
