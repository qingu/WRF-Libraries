#!/bin/sh

# Script for installing necessary software for GISS Model E and GEOS-Chem
# Last updated May 2, 2012
# L. Murray

#exit 0; # Uncomment for safety's sake after install complete

netCDF4="YES" # "YES" = build with netCDF4; "NO" = build with netCDF3

INSTALL_DIR=${PWD}/opt/ifort
SRC_DIR=${PWD}/src

# Completely fresh builds
#cd $SRC_DIR
#if [ 1 -eq 1 ]; then
#rm -rf doxygen-1.8.0
#tar -zxvf doxygen-1.8.0.src.tar.gz
#
#rm -rf zlib-1.2.6
#tar -zxvf zlib-1.2.6.tar.gz
#
#rm -rf hdf5-1.8.8
#tar -zxvf hdf5-1.8.8.tar.gz
#
#rm -rf netcdf-fortran-4.2
#tar -zxvf netcdf-fortran-4.2.tar.gz
#rm -rf netcdf-4.2
#tar -zxvf netcdf-4.2.tar.gz
#fi

#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#
# Install netCDF and its dependencies #
#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#
#if [ 1 -eq 0 ]; then

# Documentation software wanted by netCDF install
#cd $SRC_DIR/doxygen-1.8.0
#sh configure --prefix $INSTALL_DIR
#make
#make install
## In case it wasn't already in the path
#export PATH=$INSTALL_DIR/bin:$PATH

if [ $netCDF4 == "YES" ]; then

    # netCDF 4 dependencies
    cd $SRC_DIR/zlib-1.2.6
    ./configure --prefix=$INSTALL_DIR --static
    make check install
    cd $SRC_DIR/hdf5-1.8.8
    make clean
    ./configure --with-zlib=$INSTALL_DIR --prefix=$INSTALL_DIR \
         --disable-shared
    make
    #make check
    make install
    #make check-install

    # netCDF4 C/C++ API & utilities
    cd $SRC_DIR/netcdf-4.2
    FC=ifort CC=icc CXX=icpc \
	CPPFLAGS="-I${INSTALL_DIR}/include" \
	LDFLAGS="-L${INSTALL_DIR}/lib" \
	./configure --prefix=$INSTALL_DIR --disable-dap --disable-doxygen \
           --disable-shared
    make check install

    # netCDF4 Fortran API
    cd $SRC_DIR/netcdf-fortran-4.2
    FC=ifort CC=icc CXX=icpc CPP="icc -E -c" \
	CPPFLAGS="-I${INSTALL_DIR}/include" \
	LDFLAGS="-L${INSTALL_DIR}/lib" \
	LD_LIBRARY_PATH=${INSTALL_DIR}/lib:${LD_LIBRARY_PATH} \
	./configure --prefix=$INSTALL_DIR --disable-shared
    make check install

else

    # netCDF3 C/C++ API & utilities
    cd $SRC_DIR/netcdf-4.2
    FC=ifort CC=icc CXX=icpc \
	CPPFLAGS="-I${INSTALL_DIR}/include" \
	LDFLAGS="-L${INSTALL_DIR}/lib" \
	./configure --prefix=$INSTALL_DIR --disable-dap --disable-doxygen \
            --disable-shared --disable-netcdf-4
    make check install

    # netCDF3 Fortran API
    cd $SRC_DIR/netcdf-fortran-4.2
    FC=ifort CC=icc CXX=icpc \
	CPPFLAGS="-I${INSTALL_DIR}/include" \
	LDFLAGS="-L${INSTALL_DIR}/lib" \
	./configure --prefix=$INSTALL_DIR --disable-netcdf-4  --disable-shared
    make check install

fi

#fi

exit 0;
