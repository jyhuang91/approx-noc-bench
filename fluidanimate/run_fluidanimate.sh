#!/bin/sh

# medium, 16 threads
./src/fluidanimate 16 5 ./inputs/in_100K.fluid ./inputs/out_medium.fluid

# large, 16 threads
#./src/fluidanimate 16 5 ./inputs/in_300K.fluid ./inputs/out_large.fluid
