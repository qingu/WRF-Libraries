/* -*- Mode: C++; c-basic-offset:4 ; -*- */
/* 
 *  (C) 2003 by Argonne National Laboratory.
 *     See COPYRIGHT in top-level directory.
 *
 * DO NOT EDIT THIS FILE.  CREATED AUTOMATICALLY WITH TESTMERGE.
 */
#include "mpi.h"
// We place stdio.h *after* mpi.h to avoid conflicts with SEEK_SET et al
// (the name is #defined in stdio.h and used as an MPI constant
// MPI::SEEK_SET in the C++ binding for MPI)
#include <stdio.h>
#include "mpitestconf.h"
#ifdef HAVE_IOSTREAM
// Not all C++ compilers have iostream instead of iostream.h
#include <iostream>
#ifdef HAVE_NAMESPACE_STD
// Those that do need the std namespace; otherwise, a bare "cout"
// is likely to fail to compile
using namespace std;
#endif
#else
#include <iostream.h>
#endif
#include <string.h>
#include "mpitestcxx.h"
#define MAX_FPARM 5
#define MAX_BUFFER 65536
#define MAX_FTYPE 3
// We print no more than 10 errors.  To ensure a clean exit,
// we normally continue until the end of the job (so that 
// we can write out the standard No Errors or Found %d Errors message)
#define MAX_ERRORS 10
// This structure is used to determine how data is placed across the file
typedef struct { int n, b; } fileparm;
int main( int argc, char *argv[] )
{
    int errs = 0;
    MPI::Intracomm comm;
    MPI::File fh;
    int ftype;
    int itmp, fparm, n, b, i, k, r, s;
    int wrank, wsize;
    fileparm fparms[MAX_FPARM] = { 
	1,4000,  4000,8,  4096,8,  64000,8,  65536,8 };
    char filename[1024];
    
    int buf[MAX_BUFFER], ans;
    MPI::Datatype filetype;
    MPI::Offset offset;
    MTest_Init();
    wrank = MPI::COMM_WORLD.Get_rank();
    wsize = MPI::COMM_WORLD.Get_size();
    for (ftype=0; ftype<MAX_FTYPE; ftype++) {
	strcpy( filename, "iotest.txt" );
	switch (ftype) {
	case 0:
	    comm = MPI::COMM_WORLD;
	    break;
	case 1:
	    comm = MPI::COMM_WORLD.Split( 0, wsize - wrank );
	    break;
	default:
	    itmp = (wrank == 0) ? 0 : 1;
	    comm = MPI::COMM_WORLD.Split( itmp, wrank );
            if (wrank == 0) {
		comm.Free();
		continue;
            }
        }
	s = comm.Get_size();
	r = comm.Get_rank();
	for (fparm=0; fparm<MAX_FPARM; fparm++) {
	    n = fparms[fparm].n;
	    b = fparms[fparm].b;
	    // Try writing the file, then check it
            try {
            fh = MPI::File::Open( comm, filename, MPI::MODE_RDWR + MPI::MODE_CREATE, MPI::INFO_NULL );
            } catch ( MPI::Exception e ) {
                errs++;
                if (errs <= MAX_ERRORS) {
                    MTestPrintError( e.Get_error_code() );
                }
            }
            // If the file open failed, skip the rest of this test
            if (fh == MPI::FILE_NULL) { continue; }
            filetype = MPI::INT.Create_vector( b, n, n*s );
            filetype.Commit();
            offset = r * n * sizeof(int);
            fh.Set_view( offset, MPI::INT, filetype, "native", MPI::INFO_NULL );
            filetype.Free();
            for (k=0; k<b; k++) {
                 for (i=0; i<n; i++) {
                     buf[i] = r*n + k*n*s + i;
                 }
                 try {
                 fh.Write_all_begin( buf, n, MPI::INT );
                 } catch ( MPI::Exception e ) {
                     errs++;
                     if (errs <= MAX_ERRORS) {
                         MTestPrintError( e.Get_error_code() );
                     }
                 }
                 try {
                 fh.Write_all_end( buf );
                 } catch ( MPI::Exception e ) {
                     errs++;
                     if (errs <= MAX_ERRORS) {
                         MTestPrintError( e.Get_error_code() );
                     }
                 }
            }
            try {
            fh.Close();
            } catch ( MPI::Exception e ) {
                errs++;
                if (errs <= MAX_ERRORS) {
                    MTestPrintError( e.Get_error_code() );
                }
            }
	    // Now, open the same file for reading
            try {
            fh = MPI::File::Open( comm, filename, MPI::MODE_RDWR + MPI::MODE_CREATE, MPI::INFO_NULL );
            } catch ( MPI::Exception e ) {
                errs++;
                if (errs <= MAX_ERRORS) {
                    MTestPrintError( e.Get_error_code() );
                }
            }
            // If the file open failed, skip the rest of this test
            if (fh == MPI::FILE_NULL) { continue; }
            filetype = MPI::INT.Create_vector( b, n, n*s );
            filetype.Commit();
            offset = r * n * sizeof(int);
            fh.Set_view( offset, MPI::INT, filetype, "native", MPI::INFO_NULL );
            filetype.Free();
            for (k=0; k<b; k++) {
                for (i=0; i<n; i++) {
                    buf[i] = - (r*n + k*n*s + i + 1);
                }
                try {
                fh.Read_all_begin( buf, n, MPI::INT);
                } catch ( MPI::Exception e ) {
                    errs++;
                    if (errs <= MAX_ERRORS) {
                        MTestPrintError( e.Get_error_code() );
                    }
                }
                try {
                fh.Read_all_end( buf );
                } catch ( MPI::Exception e ) {
                    errs++;
                    if (errs <= MAX_ERRORS) {
                        MTestPrintError( e.Get_error_code() );
                    }
                }
                for (i=0; i<n; i++) {
                    ans = r*n + k*n*s + i;
                    if (buf[i] !=  ans) {
                        errs++;
                        if (errs <= MAX_ERRORS) {
                	    cout << r << " buf[" << i << "] = " << buf[i] << " expected " <<
                			ans << "\n";
                        }
                    }
                }
            }
            try {
            fh.Close();
            } catch ( MPI::Exception e ) {
                errs++;
                if (errs <= MAX_ERRORS) {
                    MTestPrintError( e.Get_error_code() );
                }
            }
            comm.Barrier();
            if (comm.Get_rank() == 0) {
                try {
                MPI::File::Delete( filename, MPI::INFO_NULL );
                } catch ( MPI::Exception e ) {
                    errs++;
                    if (errs <= MAX_ERRORS) {
                        MTestPrintError( e.Get_error_code() );
                    }
                }
            }
            comm.Barrier();
        }
        if (comm != MPI::COMM_WORLD) {
	    comm.Free();
	}
    }
    MTest_Finalize( errs );
    MPI::Finalize( );
    return 0;
}
