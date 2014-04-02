#! /bin/sh
#
# (C) 2006 by Argonne National Laboratory.
#     See COPYRIGHT in top-level directory.
#
# mpif90
# Simple script to compile and/or link MPI programs.
# This script knows the default flags and libraries, and can handle
# alternative C compilers and the associated flags and libraries.
# The important terms are:
#    includedir, libdir - Directories containing an *installed* mpich
#    prefix, execprefix - Often used to define includedir and libdir
#    FC                 - Fortran 90 compiler
#    WRAPPER_FCFLAGS    - Any special flags needed to compile 
#    WRAPPER_LDFLAGS    - Any special flags needed to link
#    WRAPPER_LIBS       - Any special libraries needed in order to link
#    FC_OTHER_LIBS      - Yet more libraries, needed just with FC
#    
# We assume that (a) the C compiler can both compile and link programs
#
# Handling of command-line options:
#   This is a little tricky because some options may contain blanks.
#
# Special issues with shared libraries - todo
#
# --------------------------------------------------------------------------
# Set the default values of all variables.
#
# Directory locations: Fixed for any MPI implementation.
# Set from the directory arguments to configure (e.g., --prefix=/usr/local)
prefix=/home/metman/git-projects/WRF-Libraries/opt/ifort/nc4/../mpich_ifort
exec_prefix=${prefix}
sysconfdir=${prefix}/etc
includedir=${prefix}/include
libdir=${exec_prefix}/lib

# Default settings for compiler, flags, and libraries
# Determined by a combination of environment variables and tests within
# configure (e.g., determining whehter -lsocket is needee)
FC="ifort"
FCCPP=""
#
# Fortran 90 Compiler characteristics
FCINC="-I"
# f90modinc specifies how to add a directory to the search path for modules.
# Some compilers (Intel ifc version 5) do not support this concept, and 
# instead need 
# a specific list of files that contain module names and directories.
# The FCMODINCSPEC is a more general approach that uses <dir> and <file>
# for the directory and file respectively.
FCMODINC="-I"
FCMODINCSPEC=""
FCEXT="f90"
#
FCFLAGS="-fpic -mcmodel=medium "
LDFLAGS="  "
LIBS="-lopa -lmpl  -lrt -lpthread   "
MPICH_VERSION="3.0.1"

enable_wrapper_rpath="no"

# MPICH ADDITION
# Shared library suffix, including any period (normally "so").
shrext=".so"

# How to pass a linker flag through the compiler.
wl="-Wl,"

# Static library suffix (normally "a").
libext="a"

# Shared library suffix (normally "so").
shlibext="so"

# Format of library name prefix.
libname_spec="lib\$name"

# Library names that the linker finds when passed -lNAME.
library_names_spec="\$libname\$shrext"

# Flag to hardcode $libdir into a binary during linking.
# This must work even if $libdir does not exist.
hardcode_libdir_flag_spec="\${wl}-rpath \${wl}\$libdir"

# Whether we need a single -rpath flag with a separated argument.
hardcode_libdir_separator=""

# Set to yes if using DIR/libNAME.so during linking hardcodes DIR into the
# resulting binary.
hardcode_direct="no"

# Set to yes if using the -LDIR flag during linking hardcodes DIR into the
# resulting binary.
hardcode_minus_L="no"


# Internal variables
# Show is set to echo to cause the compilation command to be echoed instead 
# of executed.
Show=eval
#
# End of initialization of variables
#---------------------------------------------------------------------
# Environment Variables.
# The environment variables MPICH_F90 may be used to override the 
# default choices.
# In addition, if there is a file $sysconfdir/mpif90-$FCname.conf, 
# where FCname is the name of the compiler with all spaces replaced by hyphens
# (e.g., "f90 -64" becomes "f90--64", that file is sources, allowing other
# changes to the compilation environment.  See the variables used by the 
# script (defined above)
# Added MPICH_F90_OLD, MPICH_F90 can be used to prefix FC with external utility,
# e.g. setenv MPICH_F90 'eval linkcache $MPICH_F90_OLD'
if [ -n "$MPICH_F90" ] ; then
    MPICH_F90_OLD="$FC"
    FC="$MPICH_F90"
    FCname=`echo $FC | sed 's/ /-/g'`
    if [ -s $sysconfdir/mpif90-$FCname.conf ] ; then
        . $sysconfdir/mpif90-$FCname.conf
    fi
fi
# Allow a profiling option to be selected through an environment variable
if [ -n "$MPIF90_PROFILE" ] ; then
    profConf=$MPIF90_PROFILE
fi
#
# ------------------------------------------------------------------------
# Argument processing.
# This is somewhat awkward because of the handling of arguments within
# the shell.  We want to handle arguments that include spaces without 
# loosing the spacing (an alternative would be to use a more powerful
# scripting language that would allow us to retain the array of values, 
# which the basic (rather than enhanced) Bourne shell does not.  
#
# Look through the arguments for arguments that indicate compile only.
# If these are *not* found, add the library options
#
linking=yes
allargs=""
for arg in "$@" ; do
    # Set addarg to no if this arg should be ignored by the C compiler
    addarg=yes
    qarg=$arg
    case $arg in 
 	# ----------------------------------------------------------------
	# Compiler options that affect whether we are linking or no
    -c|-S|-E|-M|-MM)
    # The compiler links by default
    linking=no
    ;;
	# ----------------------------------------------------------------
	# Options that control how we use mpif90 (e.g., -show, 
	# -f90=* -config=*
    -echo)
    addarg=no
    set -x
    ;;
    -f90=*)
    FC=`echo A$arg | sed -e 's/A-f90=//g'`
    addarg=no
    ;;
    -fc=*)
    FC=`echo A$arg | sed -e 's/A-fc=//g'`
    addarg=no
    ;;
    -show)
    addarg=no
    Show=echo
    ;;
    -config=*)
    addarg=no
    FCname=`echo A$arg | sed -e 's/A-config=//g'`
    if [ -s "$sysconfdir/mpif90-$FCname.conf" ] ; then
        . "$sysconfdir/mpif90-$FCname.conf"
    else
	echo "Configuration file mpif90-$FCname.conf not found"
    fi
    ;;
    -compile-info|-compile_info)
    # -compile_info included for backward compatibility
    Show=echo
    addarg=no
    ;;
    -link-info|-link_info)
    # -link_info included for backward compatibility
    Show=echo
    addarg=no
    ;;
    -v)
    # Pass this argument to the compiler as well.
    echo "mpif90 for MPICH version $MPICH_VERSION"
    # if there is only 1 argument, it must be -v.
    if [ "$#" -eq "1" ] ; then
        linking=no
    fi
    ;;
    -profile=*)
    # Pass the name of a profiling configuration.  As
    # a special case, lib<name>.so or lib<name>.la may be used
    # if the library is in $libdir
    profConf=`echo A$arg | sed -e 's/A-profile=//g'`
    addarg=no
    # Loading the profConf file is handled below
    ;;
    -nativelinking)
    # Internal option to use native compiler for linking without MPI libraries
    nativelinking=yes
    addarg=no
    ;;
    -help)
    NC=`echo "$FC" | sed 's%\/% %g' | awk '{print $NF}' -`
    if [ -f "$sysconfdir/mpixxx_opts.conf" ] ; then
        . $sysconfdir/mpixxx_opts.conf
        echo "    -f90=xxx      - Reset the native compiler to xxx."
        echo "    -fc=xxx       - Reset the native compiler to xxx."
    else
        if [ -f "./mpixxx_opts.conf" ] ; then
            . ./mpixxx_opts.conf
            echo "    -f90=xxx      - Reset the native compiler to xxx."
            echo "    -fc=xxx       - Reset the native compiler to xxx."
        fi
    fi
    exit 0
    ;;
        # -----------------------------------------------------------------
	# Other arguments.  We are careful to handle arguments with 
	# quotes (we try to quote all arguments in case they include 
	# any spaces)
    *\"*) 
    qarg="'"$arg"'"
    case $arg in 
       -D*)
       cppflags="$cppflags $qarg"
       ;;
    esac
    ;;
    *\'*) 
    qarg='\"'"$arg"'\"'
    case $arg in 
       -D*)
       cppflags="$cppflags $qarg"
       ;;
    esac
    ;;
    # The following are special args used to handle .F files when the
    # Fortran compiler itself does not handle these options
    -I*)
    cppflags="$cppflags $arg"
    ;;
    -D*)
    cppflags="$cppflags $arg"
    ;;
    *.F|*.F90|.fpp|.FPP)
# If FCCPP is not empty, then we need to do the following:
#    If any input files have the .F or .F90 extension, then    
#        If FCCPP = false, then
#            generate an error message and exit
#        Use FCCPP to convert the file from .F to .f, using 
#            $TMPDIR/f$$-$count.f as the output file name
#            Replace the input file with this name in the args
# This is needed only for very broken systems
#     
    if [ -n "$FCCPP" ] ; then
        if [ "$FCCPP" = "false" ] ; then
            echo "This Fortran compiler does not accept .F or .F90 files"
	    exit 1
        fi
        addarg=no
	# Remove and directory names and extension
	$ext=`expr "$arg" : '.*\(\..*\)'`
        bfile=`basename $arg $ext`
	#
	TMPDIR=${TMPDIR:-/tmp}
	# Make sure that we use a valid extension for the temp file.
        tmpfile=$TMPDIR/f$$-$bfile.$FCEXT
        if $FCCPP $cppflags $arg > $tmpfile ; then
            # Add this file to the commandline list
	    count=`expr $count + 1`
	    allargs="$allargs $tmpfile"
	    rmfiles="$rmfiles $tmpfile"
        else
	    echo "Aborting compilation because of failure in preprocessing step"
	    echo "for file $arg ."
	    exit 1
        fi
    fi
    # Otherwise, just accept the argument
    ;;
    # - end of special handling for .F files

    *)
    qarg="'$arg'"
    ;;

    esac
    if [ $addarg = yes ] ; then
        allargs="$allargs $qarg"
    fi
done

if [ $# -eq 0 ] ; then
    echo "Error: Command line argument is needed!"
    "$0" -help
    exit 1
fi


# -----------------------------------------------------------------------
# Derived variables.  These are assembled from variables set from the
# default, environment, configuration file (if any) and command-line
# options (if any)
mpilibs=" -lmpich"

# Handle the case of a profile switch
if [ -n "$profConf" ] ; then
    profConffile=
    if [ -s "$libdir/lib$profConf.a" -o -s "$libdir/lib$profConf.so" ] ; then
	mpilibs="-l$profConf $mpilibs"
    elif [ -s "$sysconfdir/$profConf.conf" ] ; then
	profConffile="$sysconfdir/$profConf.conf"
    elif [ -s "$profConf.conf" ] ; then
        profConffile="$profConf.conf"
    else
        echo "Profiling configuration file $profConf.conf not found in $sysconfdir"
    fi
    if [ -n "$profConffile" -a -s "$profConffile" ] ; then
	. $profConffile
	if [ -n "$PROFILE_INCPATHS" ] ; then
	    FCFLAGS="$PROFILE_INCPATHS $FCFLAGS"
        fi
        if [ -n "$PROFILE_PRELIB" ] ; then
	    mpilibs="$PROFILE_PRELIB $mpilibs"
        fi
        if [ -n "$PROFILE_POSTLIB" ] ; then
	    mpilibs="$mpilibs $PROFILE_POSTLIB"
        fi
    fi
fi

# Construct the line to add the include directory (not all compilers 
# use -I, unfortunately)
if [ -z "${FCINC}" ] ; then
    # If there is no path, add a link to the mpif.h file.
    # There *must* be a way to provide the path the any modules (there
    # may be too many to link)
    if [ ! -r mpif.h ] ; then
        #echo "Adding a symbolic link for mpif.h"
	trap "$Show rm -f mpif.h" 0
	# This should really be the (related) f77includedir (see mpif77).
	$Show ln -s ${includedir}/mpif.h mpif.h
	# Remember to remove this file
	rmfiles="$rmfiles mpif.h"
    fi
    FCINCDIRS=
else
    # Normally, FCINC is just -I, but some compilers have used different
    # command line arguments
    FCINCDIRS=${FCINC}${includedir}
fi

# Handle the specification of the directory containing the modules
# For now, these are in the includedir (no choice argument supported)
modulelib="mpichf90"
if [ -n "$FCMODINCSPEC" ] ; then
    newarg=`echo A"$FCMODINCSPEC" | \
	sed -e 's/^A//' -e 's%<dir>%'"$includedir%g" -e 's/<file>/mpi/g'`
    FCMODDIRS="$newarg"
    FCMODLIBS="-l$modulelib"
elif [ -n "$FCMODINC" ] ; then
    FCMODDIRS="${FCMODINC}$includedir"
    FCMODLIBS="-l$modulelib"
fi

#
# A temporary statement to invoke the compiler
# Place the -L before any args incase there are any mpi libraries in there.
# Eventually, we'll want to move this after any non-MPI implementation 
# libraries

if [ "$linking" = yes ] ; then
    # Attempt to encode rpath info into the executable if the user has not
    # disabled rpath usage and some flavor of rpath makes sense on this
    # platform.
    # TODO configure and config.rpath are computing more sophisticated rpath
    # schemes than this simple one.  Consider updating this logic accordingly.
    if test "X$enable_wrapper_rpath" = "Xyes" ; then
        eval mpilibs=\"${hardcode_libdir_flag_spec} \$mpilibs\"
    fi

    path_list=""
    for path in "-L$libdir" ; do
	found_path=0
	for p in $path_list ; do
	    if [ "$path" = "$p" ] ; then found_path=1 ; break ; fi
	done
	if [ "$found_path" = "0" ] ; then path_list="$path_list $path" ; fi
    done

    if [ "$nativelinking" = yes ] ; then
        $Show $FC $FCFLAGS $LDFLAGS $allargs
        rc=$?
    else
        $Show $FC $FCFLAGS $LDFLAGS $allargs $FCINCDIRS $FCMODDIRS ${path_list} $FCMODLIBS $mpilibs $LIBS
        rc=$?
    fi
else
    $Show $FC $FCFLAGS $allargs $FCINCDIRS $FCMODDIRS
    rc=$?
fi
if [ -n "$rmfiles" ] ; then
    for file in $rmfiles ; do
        objfile=`basename $file .f`
	if [ -s "${objfile}.o" ] ; then
	    # Rename 
	    destfile=`echo $objfile | sed -e "s/.*$$-//"`
	    mv -f ${objfile}.o ${destfile}.o
	fi
        rm -f $file
    done
    rm -f $rmfiles
fi
exit $rc

