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
extern FORT_DLL_SPEC void FORT_CALL MPI_PUBLISH_NAME( char * FORT_MIXED_LEN_DECL, MPI_Fint *, char * FORT_MIXED_LEN_DECL, MPI_Fint * FORT_END_LEN_DECL FORT_END_LEN_DECL );
extern FORT_DLL_SPEC void FORT_CALL mpi_publish_name__( char * FORT_MIXED_LEN_DECL, MPI_Fint *, char * FORT_MIXED_LEN_DECL, MPI_Fint * FORT_END_LEN_DECL FORT_END_LEN_DECL );
extern FORT_DLL_SPEC void FORT_CALL mpi_publish_name( char * FORT_MIXED_LEN_DECL, MPI_Fint *, char * FORT_MIXED_LEN_DECL, MPI_Fint * FORT_END_LEN_DECL FORT_END_LEN_DECL );
extern FORT_DLL_SPEC void FORT_CALL mpi_publish_name_( char * FORT_MIXED_LEN_DECL, MPI_Fint *, char * FORT_MIXED_LEN_DECL, MPI_Fint * FORT_END_LEN_DECL FORT_END_LEN_DECL );

#if defined(F77_NAME_UPPER)
#pragma weak MPI_PUBLISH_NAME = PMPI_PUBLISH_NAME
#pragma weak mpi_publish_name__ = PMPI_PUBLISH_NAME
#pragma weak mpi_publish_name_ = PMPI_PUBLISH_NAME
#pragma weak mpi_publish_name = PMPI_PUBLISH_NAME
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak MPI_PUBLISH_NAME = pmpi_publish_name__
#pragma weak mpi_publish_name__ = pmpi_publish_name__
#pragma weak mpi_publish_name_ = pmpi_publish_name__
#pragma weak mpi_publish_name = pmpi_publish_name__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak MPI_PUBLISH_NAME = pmpi_publish_name_
#pragma weak mpi_publish_name__ = pmpi_publish_name_
#pragma weak mpi_publish_name_ = pmpi_publish_name_
#pragma weak mpi_publish_name = pmpi_publish_name_
#else
#pragma weak MPI_PUBLISH_NAME = pmpi_publish_name
#pragma weak mpi_publish_name__ = pmpi_publish_name
#pragma weak mpi_publish_name_ = pmpi_publish_name
#pragma weak mpi_publish_name = pmpi_publish_name
#endif



#elif defined(HAVE_PRAGMA_WEAK)

#if defined(F77_NAME_UPPER)
extern FORT_DLL_SPEC void FORT_CALL MPI_PUBLISH_NAME( char * FORT_MIXED_LEN_DECL, MPI_Fint *, char * FORT_MIXED_LEN_DECL, MPI_Fint * FORT_END_LEN_DECL FORT_END_LEN_DECL );

#pragma weak MPI_PUBLISH_NAME = PMPI_PUBLISH_NAME
#elif defined(F77_NAME_LOWER_2USCORE)
extern FORT_DLL_SPEC void FORT_CALL mpi_publish_name__( char * FORT_MIXED_LEN_DECL, MPI_Fint *, char * FORT_MIXED_LEN_DECL, MPI_Fint * FORT_END_LEN_DECL FORT_END_LEN_DECL );

#pragma weak mpi_publish_name__ = pmpi_publish_name__
#elif !defined(F77_NAME_LOWER_USCORE)
extern FORT_DLL_SPEC void FORT_CALL mpi_publish_name( char * FORT_MIXED_LEN_DECL, MPI_Fint *, char * FORT_MIXED_LEN_DECL, MPI_Fint * FORT_END_LEN_DECL FORT_END_LEN_DECL );

#pragma weak mpi_publish_name = pmpi_publish_name
#else
extern FORT_DLL_SPEC void FORT_CALL mpi_publish_name_( char * FORT_MIXED_LEN_DECL, MPI_Fint *, char * FORT_MIXED_LEN_DECL, MPI_Fint * FORT_END_LEN_DECL FORT_END_LEN_DECL );

#pragma weak mpi_publish_name_ = pmpi_publish_name_
#endif

#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#if defined(F77_NAME_UPPER)
#pragma _HP_SECONDARY_DEF PMPI_PUBLISH_NAME  MPI_PUBLISH_NAME
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma _HP_SECONDARY_DEF pmpi_publish_name__  mpi_publish_name__
#elif !defined(F77_NAME_LOWER_USCORE)
#pragma _HP_SECONDARY_DEF pmpi_publish_name  mpi_publish_name
#else
#pragma _HP_SECONDARY_DEF pmpi_publish_name_  mpi_publish_name_
#endif

#elif defined(HAVE_PRAGMA_CRI_DUP)
#if defined(F77_NAME_UPPER)
#pragma _CRI duplicate MPI_PUBLISH_NAME as PMPI_PUBLISH_NAME
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma _CRI duplicate mpi_publish_name__ as pmpi_publish_name__
#elif !defined(F77_NAME_LOWER_USCORE)
#pragma _CRI duplicate mpi_publish_name as pmpi_publish_name
#else
#pragma _CRI duplicate mpi_publish_name_ as pmpi_publish_name_
#endif
#endif /* HAVE_PRAGMA_WEAK */
#endif /* USE_WEAK_SYMBOLS */
/* End MPI profiling block */


/* These definitions are used only for generating the Fortran wrappers */
#if defined(USE_WEAK_SYMBOLS) && defined(HAVE_MULTIPLE_PRAGMA_WEAK) && \
    defined(USE_ONLY_MPI_NAMES)
extern FORT_DLL_SPEC void FORT_CALL MPI_PUBLISH_NAME( char * FORT_MIXED_LEN_DECL, MPI_Fint *, char * FORT_MIXED_LEN_DECL, MPI_Fint * FORT_END_LEN_DECL FORT_END_LEN_DECL );
extern FORT_DLL_SPEC void FORT_CALL mpi_publish_name__( char * FORT_MIXED_LEN_DECL, MPI_Fint *, char * FORT_MIXED_LEN_DECL, MPI_Fint * FORT_END_LEN_DECL FORT_END_LEN_DECL );
extern FORT_DLL_SPEC void FORT_CALL mpi_publish_name( char * FORT_MIXED_LEN_DECL, MPI_Fint *, char * FORT_MIXED_LEN_DECL, MPI_Fint * FORT_END_LEN_DECL FORT_END_LEN_DECL );
extern FORT_DLL_SPEC void FORT_CALL mpi_publish_name_( char * FORT_MIXED_LEN_DECL, MPI_Fint *, char * FORT_MIXED_LEN_DECL, MPI_Fint * FORT_END_LEN_DECL FORT_END_LEN_DECL );

#if defined(F77_NAME_UPPER)
#pragma weak mpi_publish_name__ = MPI_PUBLISH_NAME
#pragma weak mpi_publish_name_ = MPI_PUBLISH_NAME
#pragma weak mpi_publish_name = MPI_PUBLISH_NAME
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak MPI_PUBLISH_NAME = mpi_publish_name__
#pragma weak mpi_publish_name_ = mpi_publish_name__
#pragma weak mpi_publish_name = mpi_publish_name__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak MPI_PUBLISH_NAME = mpi_publish_name_
#pragma weak mpi_publish_name__ = mpi_publish_name_
#pragma weak mpi_publish_name = mpi_publish_name_
#else
#pragma weak MPI_PUBLISH_NAME = mpi_publish_name
#pragma weak mpi_publish_name__ = mpi_publish_name
#pragma weak mpi_publish_name_ = mpi_publish_name
#endif

#endif

/* Map the name to the correct form */
#ifndef MPICH_MPI_FROM_PMPI
#if defined(USE_WEAK_SYMBOLS) && defined(HAVE_MULTIPLE_PRAGMA_WEAK)
/* Define the weak versions of the PMPI routine*/
#ifndef F77_NAME_UPPER
extern FORT_DLL_SPEC void FORT_CALL PMPI_PUBLISH_NAME( char * FORT_MIXED_LEN_DECL, MPI_Fint *, char * FORT_MIXED_LEN_DECL, MPI_Fint * FORT_END_LEN_DECL FORT_END_LEN_DECL );
#endif
#ifndef F77_NAME_LOWER_2USCORE
extern FORT_DLL_SPEC void FORT_CALL pmpi_publish_name__( char * FORT_MIXED_LEN_DECL, MPI_Fint *, char * FORT_MIXED_LEN_DECL, MPI_Fint * FORT_END_LEN_DECL FORT_END_LEN_DECL );
#endif
#ifndef F77_NAME_LOWER_USCORE
extern FORT_DLL_SPEC void FORT_CALL pmpi_publish_name_( char * FORT_MIXED_LEN_DECL, MPI_Fint *, char * FORT_MIXED_LEN_DECL, MPI_Fint * FORT_END_LEN_DECL FORT_END_LEN_DECL );
#endif
#ifndef F77_NAME_LOWER
extern FORT_DLL_SPEC void FORT_CALL pmpi_publish_name( char * FORT_MIXED_LEN_DECL, MPI_Fint *, char * FORT_MIXED_LEN_DECL, MPI_Fint * FORT_END_LEN_DECL FORT_END_LEN_DECL );

#endif

#if defined(F77_NAME_UPPER)
#pragma weak pmpi_publish_name__ = PMPI_PUBLISH_NAME
#pragma weak pmpi_publish_name_ = PMPI_PUBLISH_NAME
#pragma weak pmpi_publish_name = PMPI_PUBLISH_NAME
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak PMPI_PUBLISH_NAME = pmpi_publish_name__
#pragma weak pmpi_publish_name_ = pmpi_publish_name__
#pragma weak pmpi_publish_name = pmpi_publish_name__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak PMPI_PUBLISH_NAME = pmpi_publish_name_
#pragma weak pmpi_publish_name__ = pmpi_publish_name_
#pragma weak pmpi_publish_name = pmpi_publish_name_
#else
#pragma weak PMPI_PUBLISH_NAME = pmpi_publish_name
#pragma weak pmpi_publish_name__ = pmpi_publish_name
#pragma weak pmpi_publish_name_ = pmpi_publish_name
#endif /* Test on name mapping */
#endif /* Use multiple pragma weak */

#ifdef F77_NAME_UPPER
#define mpi_publish_name_ PMPI_PUBLISH_NAME
#elif defined(F77_NAME_LOWER_2USCORE)
#define mpi_publish_name_ pmpi_publish_name__
#elif !defined(F77_NAME_LOWER_USCORE)
#define mpi_publish_name_ pmpi_publish_name
#else
#define mpi_publish_name_ pmpi_publish_name_
#endif /* Test on name mapping */

/* This defines the routine that we call, which must be the PMPI version
   since we're renaming the Fortran entry as the pmpi version.  The MPI name
   must be undefined first to prevent any conflicts with previous renamings. */
#undef MPI_Publish_name
#define MPI_Publish_name PMPI_Publish_name 

#else

#ifdef F77_NAME_UPPER
#define mpi_publish_name_ MPI_PUBLISH_NAME
#elif defined(F77_NAME_LOWER_2USCORE)
#define mpi_publish_name_ mpi_publish_name__
#elif !defined(F77_NAME_LOWER_USCORE)
#define mpi_publish_name_ mpi_publish_name
/* Else leave name alone */
#endif


#endif /* MPICH_MPI_FROM_PMPI */

/* Prototypes for the Fortran interfaces */
#include "fproto.h"
FORT_DLL_SPEC void FORT_CALL mpi_publish_name_ ( char *v1 FORT_MIXED_LEN(d1), MPI_Fint *v2, char *v3 FORT_MIXED_LEN(d3), MPI_Fint *ierr FORT_END_LEN(d1) FORT_END_LEN(d3) ){
    char *p1;
    char *p3;

    {char *p = v1 + d1 - 1;
     int  li;
        while (*p == ' ' && p > v1) p--;
        p++;
        p1 = (char *)MPIU_Malloc( p-v1 + 1 );
        for (li=0; li<(p-v1); li++) { p1[li] = v1[li]; }
        p1[li] = 0; 
    }

    {char *p = v3 + d3 - 1;
     int  li;
        while (*p == ' ' && p > v3) p--;
        p++;
        p3 = (char *)MPIU_Malloc( p-v3 + 1 );
        for (li=0; li<(p-v3); li++) { p3[li] = v3[li]; }
        p3[li] = 0; 
    }
    *ierr = MPI_Publish_name( p1, (MPI_Info)(*v2), p3 );
    MPIU_Free( p1 );
    MPIU_Free( p3 );
}
