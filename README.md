
This project forks from Harvard's GEOS-Chen-Libraries project.
You can see the wiki page : <http://wiki.seas.harvard.edu/geos-chem/index.php/Installing_libraries_for_GEOS-Chem>


1. Bug #1

 zlib判断是否存在`zlib-1.2.6.install`文件来决定zlib是否已存在或重新编译，但原版本里存在该文件，但zlib实际未编译。

 解决方法：删除该文件，`make distclean`时是否未将其删除？

2. 编译hdf-1.8.8出现`h5diff.c(647): error: expected an expression ; compilation aborted for h5diff.c (code 2)`错误。

 解决方法：可能icc 2013版本与hdf-1.8.8不兼容，换成hdf-1.8.12版本编译成功。

3. src/GNUmakefile中distclean目标规则需要修改







