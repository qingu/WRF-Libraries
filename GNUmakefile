#EOC
#------------------------------------------------------------------------------
#          Harvard University Atmospheric Chemistry Modeling Group            !
#------------------------------------------------------------------------------
#BOP
#
# !MODULE: GNUmakefile (in the main directory)
#
# !DESCRIPTION: This is a "router" makefile that calls down to 
#  src/GNUmakefile.  Please see the comments to that makefile for more
#  information about how to build the netCDF4 or netCDF-CLASSIClibraries.
#\\
#\\
# !REVISION HISTORY: 
#  26 Apr 2012 - R. Yantosca - Initial version, based on NASA Baselibs
#  08 May 2012 - R. Yantosca - Updated for consistency w/ src/GNUmakefile
#EOP
#------------------------------------------------------------------------------
#BOC

# Local variables
SHELL := /bin/sh
SRC   := src

all:
	@$(MAKE) -C $(SRC) all 2>&1 |tee make_all.log

mpich:           
	@$(MAKE) -C $(SRC) mpich

zlib:           
	@$(MAKE) -C $(SRC) zlib

jasper:           
	@$(MAKE) -C $(SRC) jasper

libpng:           
	@$(MAKE) -C $(SRC) libpng

hdf5:           
	@$(MAKE) -C $(SRC) hdf5

nc4:             
	@$(MAKE) -C $(SRC) nc4

nc_classic:             
	@$(MAKE) -C $(SRC) nc3

verify:          
	@$(MAKE) -C $(SRC) verify

doc:             
	@$(MAKE) -C $(SRC) doc

clean_doc:
	@$(MAKE) -C $(SRC) clean_doc

clean_mpich:
	@$(MAKE) -C $(SRC) clean_mpich

clean_zlib:
	@$(MAKE) -C $(SRC) clean_zlib

clean_jasper:
	@$(MAKE) -C $(SRC) clean_jasper

clean_libpng:
	@$(MAKE) -C $(SRC) clean_libpng

clean_hdf5:
	@$(MAKE) -C $(SRC) clean_hdf5

clean_netcdf:
	@$(MAKE) -C $(SRC) clean_netcdf

distclean:
	@$(MAKE) -C $(SRC) distclean

help:       
	@$(MAKE) -C $(SRC) help

#EOC
