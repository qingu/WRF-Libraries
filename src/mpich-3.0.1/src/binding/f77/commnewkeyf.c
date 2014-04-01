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
extern FORT_DLL_SPEC void FORT_CALL MPI_COMM_CREATE_KEYVAL( MPI_Comm_copy_attr_function*, MPI_Comm_delete_attr_function*, MPI_Fint *, void*, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_comm_create_keyval__( MPI_Comm_copy_attr_function*, MPI_Comm_delete_attr_function*, MPI_Fint *, void*, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_comm_create_keyval( MPI_Comm_copy_attr_function*, MPI_Comm_delete_attr_function*, MPI_Fint *, void*, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_comm_create_keyval_( MPI_Comm_copy_attr_function*, MPI_Comm_delete_attr_function*, MPI_Fint *, void*, MPI_Fint * );

#if defined(F77_NAME_UPPER)
#pragma weak MPI_COMM_CREATE_KEYVAL = PMPI_COMM_CREATE_KEYVAL
#pragma weak mpi_comm_create_keyval__ = PMPI_COMM_CREATE_KEYVAL
#pragma weak mpi_comm_create_keyval_ = PMPI_COMM_CREATE_KEYVAL
#pragma weak mpi_comm_create_keyval = PMPI_COMM_CREATE_KEYVAL
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak MPI_COMM_CREATE_KEYVAL = pmpi_comm_create_keyval__
#pragma weak mpi_comm_create_keyval__ = pmpi_comm_create_keyval__
#pragma weak mpi_comm_create_keyval_ = pmpi_comm_create_keyval__
#pragma weak mpi_comm_create_keyval = pmpi_comm_create_keyval__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak MPI_COMM_CREATE_KEYVAL = pmpi_comm_create_keyval_
#pragma weak mpi_comm_create_keyval__ = pmpi_comm_create_keyval_
#pragma weak mpi_comm_create_keyval_ = pmpi_comm_create_keyval_
#pragma weak mpi_comm_create_keyval = pmpi_comm_create_keyval_
#else
#pragma weak MPI_COMM_CREATE_KEYVAL = pmpi_comm_create_keyval
#pragma weak mpi_comm_create_keyval__ = pmpi_comm_create_keyval
#pragma weak mpi_comm_create_keyval_ = pmpi_comm_create_keyval
#pragma weak mpi_comm_create_keyval = pmpi_comm_create_keyval
#endif



#elif defined(HAVE_PRAGMA_WEAK)

#if defined(F77_NAME_UPPER)
extern FORT_DLL_SPEC void FORT_CALL MPI_COMM_CREATE_KEYVAL( MPI_Comm_copy_attr_function*, MPI_Comm_delete_attr_function*, MPI_Fint *, void*, MPI_Fint * );

#pragma weak MPI_COMM_CREATE_KEYVAL = PMPI_COMM_CREATE_KEYVAL
#elif defined(F77_NAME_LOWER_2USCORE)
extern FORT_DLL_SPEC void FORT_CALL mpi_comm_create_keyval__( MPI_Comm_copy_attr_function*, MPI_Comm_delete_attr_function*, MPI_Fint *, void*, MPI_Fint * );

#pragma weak mpi_comm_create_keyval__ = pmpi_comm_create_keyval__
#elif !defined(F77_NAME_LOWER_USCORE)
extern FORT_DLL_SPEC void FORT_CALL mpi_comm_create_keyval( MPI_Comm_copy_attr_function*, MPI_Comm_delete_attr_function*, MPI_Fint *, void*, MPI_Fint * );

#pragma weak mpi_comm_create_keyval = pmpi_comm_create_keyval
#else
extern FORT_DLL_SPEC void FORT_CALL mpi_comm_create_keyval_( MPI_Comm_copy_attr_function*, MPI_Comm_delete_attr_function*, MPI_Fint *, void*, MPI_Fint * );

#pragma weak mpi_comm_create_keyval_ = pmpi_comm_create_keyval_
#endif

#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#if defined(F77_NAME_UPPER)
#pragma _HP_SECONDARY_DEF PMPI_COMM_CREATE_KEYVAL  MPI_COMM_CREATE_KEYVAL
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma _HP_SECONDARY_DEF pmpi_comm_create_keyval__  mpi_comm_create_keyval__
#elif !defined(F77_NAME_LOWER_USCORE)
#pragma _HP_SECONDARY_DEF pmpi_comm_create_keyval  mpi_comm_create_keyval
#else
#pragma _HP_SECONDARY_DEF pmpi_comm_create_keyval_  mpi_comm_create_keyval_
#endif

#elif defined(HAVE_PRAGMA_CRI_DUP)
#if defined(F77_NAME_UPPER)
#pragma _CRI duplicate MPI_COMM_CREATE_KEYVAL as PMPI_COMM_CREATE_KEYVAL
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma _CRI duplicate mpi_comm_create_keyval__ as pmpi_comm_create_keyval__
#elif !defined(F77_NAME_LOWER_USCORE)
#pragma _CRI duplicate mpi_comm_create_keyval as pmpi_comm_create_keyval
#else
#pragma _CRI duplicate mpi_comm_create_keyval_ as pmpi_comm_create_keyval_
#endif
#endif /* HAVE_PRAGMA_WEAK */
#endif /* USE_WEAK_SYMBOLS */
/* End MPI profiling block */


/* These definitions are used only for generating the Fortran wrappers */
#if defined(USE_WEAK_SYMBOLS) && defined(HAVE_MULTIPLE_PRAGMA_WEAK) && \
    defined(USE_ONLY_MPI_NAMES)
extern FORT_DLL_SPEC void FORT_CALL MPI_COMM_CREATE_KEYVAL( MPI_Comm_copy_attr_function*, MPI_Comm_delete_attr_function*, MPI_Fint *, void*, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_comm_create_keyval__( MPI_Comm_copy_attr_function*, MPI_Comm_delete_attr_function*, MPI_Fint *, void*, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_comm_create_keyval( MPI_Comm_copy_attr_function*, MPI_Comm_delete_attr_function*, MPI_Fint *, void*, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_comm_create_keyval_( MPI_Comm_copy_attr_function*, MPI_Comm_delete_attr_function*, MPI_Fint *, void*, MPI_Fint * );

#if defined(F77_NAME_UPPER)
#pragma weak mpi_comm_create_keyval__ = MPI_COMM_CREATE_KEYVAL
#pragma weak mpi_comm_create_keyval_ = MPI_COMM_CREATE_KEYVAL
#pragma weak mpi_comm_create_keyval = MPI_COMM_CREATE_KEYVAL
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak MPI_COMM_CREATE_KEYVAL = mpi_comm_create_keyval__
#pragma weak mpi_comm_create_keyval_ = mpi_comm_create_keyval__
#pragma weak mpi_comm_create_keyval = mpi_comm_create_keyval__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak MPI_COMM_CREATE_KEYVAL = mpi_comm_create_keyval_
#pragma weak mpi_comm_create_keyval__ = mpi_comm_create_keyval_
#pragma weak mpi_comm_create_keyval = mpi_comm_create_keyval_
#else
#pragma weak MPI_COMM_CREATE_KEYVAL = mpi_comm_create_keyval
#pragma weak mpi_comm_create_keyval__ = mpi_comm_create_keyval
#pragma weak mpi_comm_create_keyval_ = mpi_comm_create_keyval
#endif

#endif

/* Map the name to the correct form */
#ifndef MPICH_MPI_FROM_PMPI
#if defined(USE_WEAK_SYMBOLS) && defined(HAVE_MULTIPLE_PRAGMA_WEAK)
/* Define the weak versions of the PMPI routine*/
#ifndef F77_NAME_UPPER
extern FORT_DLL_SPEC void FORT_CALL PMPI_COMM_CREATE_KEYVAL( MPI_Comm_copy_attr_function*, MPI_Comm_delete_attr_function*, MPI_Fint *, void*, MPI_Fint * );
#endif
#ifndef F77_NAME_LOWER_2USCORE
extern FORT_DLL_SPEC void FORT_CALL pmpi_comm_create_keyval__( MPI_Comm_copy_attr_function*, MPI_Comm_delete_attr_function*, MPI_Fint *, void*, MPI_Fint * );
#endif
#ifndef F77_NAME_LOWER_USCORE
extern FORT_DLL_SPEC void FORT_CALL pmpi_comm_create_keyval_( MPI_Comm_copy_attr_function*, MPI_Comm_delete_attr_function*, MPI_Fint *, void*, MPI_Fint * );
#endif
#ifndef F77_NAME_LOWER
extern FORT_DLL_SPEC void FORT_CALL pmpi_comm_create_keyval( MPI_Comm_copy_attr_function*, MPI_Comm_delete_attr_function*, MPI_Fint *, void*, MPI_Fint * );

#endif

#if defined(F77_NAME_UPPER)
#pragma weak pmpi_comm_create_keyval__ = PMPI_COMM_CREATE_KEYVAL
#pragma weak pmpi_comm_create_keyval_ = PMPI_COMM_CREATE_KEYVAL
#pragma weak pmpi_comm_create_keyval = PMPI_COMM_CREATE_KEYVAL
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma weak PMPI_COMM_CREATE_KEYVAL = pmpi_comm_create_keyval__
#pragma weak pmpi_comm_create_keyval_ = pmpi_comm_create_keyval__
#pragma weak pmpi_comm_create_keyval = pmpi_comm_create_keyval__
#elif defined(F77_NAME_LOWER_USCORE)
#pragma weak PMPI_COMM_CREATE_KEYVAL = pmpi_comm_create_keyval_
#pragma weak pmpi_comm_create_keyval__ = pmpi_comm_create_keyval_
#pragma weak pmpi_comm_create_keyval = pmpi_comm_create_keyval_
#else
#pragma weak PMPI_COMM_CREATE_KEYVAL = pmpi_comm_create_keyval
#pragma weak pmpi_comm_create_keyval__ = pmpi_comm_create_keyval
#pragma weak pmpi_comm_create_keyval_ = pmpi_comm_create_keyval
#endif /* Test on name mapping */
#endif /* Use multiple pragma weak */

#ifdef F77_NAME_UPPER
#define mpi_comm_create_keyval_ PMPI_COMM_CREATE_KEYVAL
#elif defined(F77_NAME_LOWER_2USCORE)
#define mpi_comm_create_keyval_ pmpi_comm_create_keyval__
#elif !defined(F77_NAME_LOWER_USCORE)
#define mpi_comm_create_keyval_ pmpi_comm_create_keyval
#else
#define mpi_comm_create_keyval_ pmpi_comm_create_keyval_
#endif /* Test on name mapping */

/* This defines the routine that we call, which must be the PMPI version
   since we're renaming the Fortran entry as the pmpi version.  The MPI name
   must be undefined first to prevent any conflicts with previous renamings. */
#undef MPI_Comm_create_keyval
#define MPI_Comm_create_keyval PMPI_Comm_create_keyval 

#else

#ifdef F77_NAME_UPPER
#define mpi_comm_create_keyval_ MPI_COMM_CREATE_KEYVAL
#elif defined(F77_NAME_LOWER_2USCORE)
#define mpi_comm_create_keyval_ mpi_comm_create_keyval__
#elif !defined(F77_NAME_LOWER_USCORE)
#define mpi_comm_create_keyval_ mpi_comm_create_keyval
/* Else leave name alone */
#endif


#endif /* MPICH_MPI_FROM_PMPI */

/* Prototypes for the Fortran interfaces */
#include "fproto.h"


/* The F90 attr copy function prototype and calling convention */
typedef void (FORT_CALL F90_CopyFunction) (MPI_Fint *, MPI_Fint *, MPI_Aint *, MPI_Aint *,MPI_Aint *, MPI_Fint *, MPI_Fint *);

/* Helper proxy function to thunk the attr copy function call into F90 calling convention */
static
int
MPIR_Comm_copy_attr_f90_proxy(
    MPI_Comm_copy_attr_function* user_function,
    MPI_Comm comm,
    int keyval,
    void* extra_state,
    MPIR_AttrType value_type,
    void* value,
    void** new_value,
    int* flag
    )
{
    MPI_Fint ierr = 0;
    MPI_Fint fhandle = (MPI_Fint)comm;
    MPI_Fint fkeyval = (MPI_Fint)keyval;
    MPI_Aint fvalue = MPI_VOID_PTR_CAST_TO_MPI_AINT (value);
    MPI_Aint* fextra  = (MPI_Aint*)extra_state;
    MPI_Aint fnew = 0;
    MPI_Fint fflag = 0;

    ((F90_CopyFunction*)user_function)( &fhandle, &fkeyval, fextra, &fvalue, &fnew, &fflag, &ierr );

    *flag = MPIR_FROM_FLOG(fflag);
    *new_value = MPI_AINT_CAST_TO_VOID_PTR (fnew);
    return (int)ierr;
}


/* The F90 attr delete function prototype and calling convention */
typedef void (FORT_CALL F90_DeleteFunction) (MPI_Fint *, MPI_Fint *, MPI_Aint *, MPI_Aint *, MPI_Fint *);

/* Helper proxy function to thunk the attr delete function call into F77 calling convention */
static
int
MPIR_Comm_delete_attr_f90_proxy(
    MPI_Comm_delete_attr_function* user_function,
    MPI_Comm comm,
    int keyval,
    MPIR_AttrType value_type,
    void* value,
    void* extra_state
    )
{
    MPI_Fint ierr = 0;
    MPI_Fint fhandle = (MPI_Fint)comm;
    MPI_Fint fkeyval = (MPI_Fint)keyval;
    MPI_Aint fvalue = MPI_VOID_PTR_CAST_TO_MPI_AINT (value);
    MPI_Aint* fextra  = (MPI_Aint*)extra_state;

    ((F90_DeleteFunction*)user_function)( &fhandle, &fkeyval, &fvalue, fextra, &ierr );
    return (int)ierr;
}
FORT_DLL_SPEC void FORT_CALL mpi_comm_create_keyval_ ( MPI_Comm_copy_attr_function*v1, MPI_Comm_delete_attr_function*v2, MPI_Fint *v3, void*v4, MPI_Fint *ierr ){
    *ierr = MPI_Comm_create_keyval( v1, v2, v3, v4 );

    if (*ierr == MPI_SUCCESS) {
         MPIR_Keyval_set_proxy( (int)*v3, MPIR_Comm_copy_attr_f90_proxy, MPIR_Comm_delete_attr_f90_proxy );
    }
}
