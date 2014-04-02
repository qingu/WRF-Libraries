WRF-Libraries
=============

Based on Harvard's GEOS-Chem-Libraries project, fix some bugs and add jasper and  libpng needed by WRF.
You can see the GEOS-Chen_Libraries's wiki page : <http://wiki.seas.harvard.edu/geos-chem/index.php/Installing_libraries_for_GEOS-Chem>


##New Features

1. Add jasper and libpng libraries needed by WRF.

2. Add mpich installation.


##Installation

安装成功会提示：

```
-------+---------+-------------------------------------
Config | Install |             Package
-------+---------+-------------------------------------
  ok   |   ok    | zlib-1.2.6 
  ok   |   ok    | jasper-1.900.1 
  ok   |   ok    | libpng-1.6.9 
  ok   |   ok    | hdf5-1.8.12 
  ok   |   ok    | netcdf-4.2 
  ok   |   ok    | netcdf-fortran-4.2 
-------+---------+-------------------------------------
```

##Fixed Bugs

###Bug 1

 zlib判断是否存在`zlib-1.2.6.install`文件来决定zlib是否已存在或重新编译，但原版本里存在该文件，但zlib实际未编译。

 解决方法：删除该文件，`make distclean`时是否未将其删除？

###Bug 2

 编译hdf-1.8.8出现`h5diff.c(647): error: expected an expression ; compilation aborted for h5diff.c (code 2)`错误。

 解决方法：可能icc 2013版本与hdf-1.8.8不兼容，换成hdf-1.8.12版本编译成功。

###Bug 3
src/GNUmakefile中distclean目标规则需要修改

