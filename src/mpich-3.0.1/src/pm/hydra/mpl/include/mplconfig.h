#ifndef _INCLUDE_MPLCONFIG_H
#define _INCLUDE_MPLCONFIG_H 1
 
/* include/mplconfig.h. Generated automatically at end of configure. */
/* include/config.h.  Generated from config.h.in by configure.  */
/* include/config.h.in.  Generated from configure.ac by autoheader.  */

/* define if valgrind is old and/or broken compared to what we are expecting
   */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define to 1 if you have the <ctype.h> header file. */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define to 1 if you have the <dlfcn.h> header file. */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define to 1 if you have the <drd.h> header file. */
/* #undef HAVE_DRD_H */

/* Define if GNU __attribute__ is supported */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define to 1 if you have the <helgrind.h> header file. */
/* #undef HAVE_HELGRIND_H */

/* Define to 1 if you have the <inttypes.h> header file. */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define if C99-style variable argument list macro functionality */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define to 1 if you have the <memcheck.h> header file. */
/* #undef HAVE_MEMCHECK_H */

/* Define to 1 if you have the <memory.h> header file. */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define to 1 if you have the `putenv' function. */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define to 1 if you have the <search.h> header file. */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define to 1 if you have the `snprintf' function. */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define to 1 if you have the <stdarg.h> header file. */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define to 1 if you have the <stdint.h> header file. */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define to 1 if you have the <stdio.h> header file. */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define to 1 if you have the <stdlib.h> header file. */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define to 1 if you have the `strdup' function. */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define to 1 if you have the <strings.h> header file. */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define to 1 if you have the <string.h> header file. */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define to 1 if you have the `strncmp' function. */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define to 1 if you have the <sys/stat.h> header file. */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define to 1 if you have the <sys/types.h> header file. */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define to 1 if you have the <unistd.h> header file. */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define to 1 if you have the `usleep' function. */
/* #undef HAVE_USLEEP */

/* Define to 1 if you have the <valgrind/drd.h> header file. */
/* #undef HAVE_VALGRIND_DRD_H */

/* Define to 1 if you have the <valgrind.h> header file. */
/* #undef HAVE_VALGRIND_H */

/* Define to 1 if you have the <valgrind/helgrind.h> header file. */
/* #undef HAVE_VALGRIND_HELGRIND_H */

/* Define to 1 if you have the <valgrind/memcheck.h> header file. */
/* #undef HAVE_VALGRIND_MEMCHECK_H */

/* Define to 1 if you have the <valgrind/valgrind.h> header file. */
/* #undef HAVE_VALGRIND_VALGRIND_H */

/* defined if the C compiler supports __typeof(variable) */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define if putenv needs a declaration */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define if snprintf needs a declaration */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define if strdup needs a declaration */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define if strncmp needs a declaration */
#ifndef MPL_ 
#define MPL_  
#endif

/* Name of package */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define to the address where bug reports for this package should be sent. */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define to the full name of this package. */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define to the full name and version of this package. */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define to the one symbol short name of this package. */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define to the home page for this package. */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define to the version of this package. */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define to 1 if you have the ANSI C header files. */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define if performing coverage tests */
/* #undef USE_COVERAGE */

/* Version number of package */
#ifndef MPL_ 
#define MPL_  
#endif

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* Define to the equivalent of the C99 'restrict' keyword, or to
   nothing if this is not supported.  Do not define if restrict is
   supported directly.  */
#ifndef _mpl_ 
#define _mpl_  
#endif
/* Work around a bug in Sun C++: it does not support _Restrict or
   __restrict__, even though the corresponding Sun C compiler ends up with
   "#define restrict _Restrict" or "#define restrict __restrict__" in the
   previous line.  Perhaps some future version of Sun C++ will work with
   restrict; if so, hopefully it defines __RESTRICT like Sun C does.  */
#if defined __SUNPRO_CC && !defined __RESTRICT
# define _Restrict
# define __restrict__
#endif
 
/* once: _INCLUDE_MPLCONFIG_H */
#endif
