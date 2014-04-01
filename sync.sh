#/bin/bash

TIME=`date "+%Y-%m-%d %H:%M:%S"`

make distclean

git add .
git commit -a -m "$1-$TIME"
git push -u origin master
