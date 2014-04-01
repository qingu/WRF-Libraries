/* -*- Mode: C; c-basic-offset:4 ; -*- */
/*  
 *  (C) 2007 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

/* This file creates strings for the most important configuration options.
   These are then used in the file src/mpi/init/initthread.c to initialize
   global variables that will then be included in both the library and 
   executables, providing a way to determine what version and features of
   MPICH were used with a particular library or executable. 
*/
#ifndef MPICHINFO_H_INCLUDED
#define MPICHINFO_H_INCLUDED

#define MPICH_CONFIGURE_ARGS_CLEAN "--prefix=/home/metman/git-projects/WRF_Libraries/opt/ifort/nc4/../mpich_ifort FC=ifort FCFLAGS=-fpic -mcmodel=medium CC=icc CFLAGS=-fpic -mcmodel=medium"
#define MPICH_VERSION_DATE "Thu Dec 20 14:27:22 CST 2012"
#define MPICH_DEVICE "ch3:nemesis"
#define MPICH_COMPILER_CC "icc -fpic -mcmodel=medium   -O2"
#define MPICH_COMPILER_CXX "c++   -O2"
#define MPICH_COMPILER_F77 "ifort   -O2"
#define MPICH_COMPILER_FC "ifort -fpic -mcmodel=medium  -O2"

#endif
