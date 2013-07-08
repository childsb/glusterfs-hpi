#!/bin/sh
rm -rf org
mkdir  -p org/gluster/hadoop/
swig -java -package org.gluster.hadoop -outdir org/gluster/hadoop glfs_hpi.i
gcc -c glfs_hpi_wrap.c  -I/usr/java/latest/include -I/usr/java/latest/include/linux -fPIC
ld -G glfs_hpi_wrap.o  -o libglfshpi.so
# ld -G glfs_hpi_wrap.o glfs_hpi.o -o glfs_hpi.so
