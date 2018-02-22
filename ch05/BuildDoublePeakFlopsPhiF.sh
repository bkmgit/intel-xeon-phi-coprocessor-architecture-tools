#!/bin/bash

# A Bash script to compile the peakflops program for use on the Xeon 
# Phi chips
rm -f *.o


# compile code
ifort -c -offload-attribute-target=mic -O3 -opt-threads-per-core=2  -openmp -xAVX -align rec16byte  -vec-report3  ./DoublePeakFlopsPhi.f -o ./PeakFlopsPhi.o

ifort ./DoublePeakFlopsPhi.o -openmp -o ./DoublePeakFlopsPhi.out
