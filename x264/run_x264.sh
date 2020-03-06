#!/bin/sh

# 8 threads, medium
#./src/x264 --qp 20 --partitions b8x8,i4x4 --ref 5 --direct auto --b-pyramid --weightb --mixed-refs --no-fast-pskip --me umh --subme 7 --analyse b8x8,i4x4 --threads 8 -o ./inputs/eledream.264 ./inputs/eledream_640x360_32.y4m
# 16 threads, large
./src/x264 --qp 20 --partitions b8x8,i4x4 --ref 5 --direct auto --b-pyramid --weightb --mixed-refs --no-fast-pskip --me umh --subme 7 --analyse b8x8,i4x4 --threads 16 -o ./inputs/eledream_large.264 ./inputs/eledream_640x360_128.y4m
