CC          = icc
AR          = ar
LIBNAME     = /home/metman/git-projects/WRF-Libraries/src/mpich-3.0.1/lib/libmpich.a
RANLIB      = ranlib
srcdir      = /home/metman/git-projects/WRF-Libraries/src/mpich-3.0.1/src/mpi/romio/mpi2-other/info
CC_SHL      = 
SHLIBNAME   = /home/metman/git-projects/WRF-Libraries/src/mpich-3.0.1/lib/libmpich

INCLUDE_DIR = -I. -I../../include -I${srcdir}/../../mpi-io -I${srcdir}/../../adio/include -I../../adio/include
CFLAGS      = -DHAVE_MPI_INFO_SRC -fpic -mcmodel=medium   -O2  -DFORTRANUNDERSCORE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DHAVE_ROMIOCONF_H -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 $(MPIOPROFILE) $(INCLUDE_DIR)

top_builddir  = /home/metman/git-projects/WRF-Libraries/src/mpich-3.0.1
LIBTOOL       = $(SHELL) $(top_builddir)/libtool
C_COMPILE_SHL = $(CC_SHL)

VPATH=.:${srcdir}

MPIO_OBJECTS = info_create.o info_dup.o info_get.o info_getnth.o \
      info_set.o info_delete.o info_free.o info_getnks.o info_getvln.o \
      info_c2f.o info_f2c.o

MPIO_TMP_POBJECTS = info_create.p info_dup.p info_get.p info_getnth.p \
      info_set.p info_delete.p info_free.p info_getnks.p info_getvln.p \
      info_c2f.p info_f2c.p

MPIO_REAL_POBJECTS = _info_create.o _info_dup.o _info_get.o _info_getnth.o \
      _info_set.o _info_delete.o _info_free.o _info_getnks.o _info_getvln.o \
      _info_c2f.o _info_f2c.o

all: $(LIBNAME)
	@if [ "none" != "none" ] ; then \
	    $(MAKE) $(SHLIBNAME).la ;\
	fi

.SUFFIXES: $(SUFFIXES) .p .sp .lo

.c.o:
	$(CC) $(CFLAGS) -c $<

.c.lo:
	$(C_COMPILE_SHL) $(CFLAGS) -c $< -o _s$*.o
	@mv -f _s$*.o $*.lo

.c.p:
	@cp $(srcdir)/$*.c _$*.c
	$(CC) $(CFLAGS) -c _$*.c
	@rm -f _$*.c

.c.sp:
	$(C_COMPILE_SHL) $(CFLAGS) -c $< -o _$*.lo

profile: $(MPIO_REAL_POBJECTS)
	$(AR) $(LIBNAME) $(MPIO_REAL_POBJECTS)
	$(RANLIB) $(LIBNAME) 
	@if [ "none" != "none" ] ; then \
	    $(MAKE) P$(SHLIBNAME).la ;\
	fi
	@rm -f _*.o

$(LIBNAME): $(MPIO_OBJECTS)
	$(AR) $(LIBNAME) $(MPIO_OBJECTS)
	$(RANLIB) $(LIBNAME) 

MPIO_LOOBJECTS = $(MPIO_OBJECTS:.o=.lo)
$(SHLIBNAME).la: $(MPIO_LOOBJECTS) 
	$(AR) $(SHLIBNAME).la $(MPIO_LOOBJECTS)

# --------------------------------------------------------------------------
# We use P$(SHLBNAME) simply to distinguish the regular lib build from the
# profiling library build
MPIO_LOPOBJECTS = $(MPIO_REAL_POBJECTS:.o=.lo)
MPIO_TMP_LOPOBJECTS = ${MPIO_TMP_POBJECTS:.p=.sp}
P$(SHLIBNAME).la: $(MPIO_TMP_LOPOBJECTS)
	$(AR) $(SHLIBNAME).la $(MPIO_LOPOBJECTS)
# --------------------------------------------------------------------------

clean:
	@rm -f *.o *.lo *.gcno *.gcda *.bb *.bbg
	@rm -f ${srcdir}/*.gcno ${srcdir}/*.gcda 
	@rm -f ${srcdir}/*.bb ${srcdir}/*.bbg


# Rules for the profiling objects
info_create.o: infocreate.c
	$(CC) $(CFLAGS) -c $(srcdir)/infocreate.c -o _info_create.o
info_dup.o: infodup.c
	$(CC) $(CFLAGS) -c $(srcdir)/infodup.c -o _info_dup.o
info_get.o: infoget.c
	$(CC) $(CFLAGS) -c $(srcdir)/infoget.c -o _info_get.o
info_getnth.o: infogetnth.c
	$(CC) $(CFLAGS) -c $(srcdir)/infogetnth.c -o _info_getnth.o
info_set.o: infoset.c
	$(CC) $(CFLAGS) -c $(srcdir)/infoset.c -o _info_set.o
info_delete.o: infodelete.c
	$(CC) $(CFLAGS) -c $(srcdir)/infodelete.c -o _info_delete.o
info_free.o: infofree.c
	$(CC) $(CFLAGS) -c $(srcdir)/infofree.c -o _info_free.o
info_getnks.o: infogetnks.c
	$(CC) $(CFLAGS) -c $(srcdir)/infogetnks.c -o _info_getnks.o
info_getvln.o: infogetvln.c
	$(CC) $(CFLAGS) -c $(srcdir)/infogetvln.c -o _info_getvln.o
info_c2f.o: infoc2f.c
	$(CC) $(CFLAGS) -c $(srcdir)/infoc2f.c -o _info_c2f.o
info_f2c.o: infof2c.c
	$(CC) $(CFLAGS) -c $(srcdir)/infof2c.c -o _info_f2c.o
