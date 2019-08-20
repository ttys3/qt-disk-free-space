#!/bin/sh

make clean
make distclean
rm -f *.o
rm -f ./disk-free-space
qmake-qt5 && \
make && \
./disk-free-space
