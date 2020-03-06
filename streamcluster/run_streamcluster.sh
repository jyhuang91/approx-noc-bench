#!/bin/sh

# medium, 16 threads
#./src/streamcluster 10 20 64 8192 8192 1000 none output.txt 16
# large, 16 threads
./src/streamcluster 10 20 128 16384 16384 1000 none output.txt 16
