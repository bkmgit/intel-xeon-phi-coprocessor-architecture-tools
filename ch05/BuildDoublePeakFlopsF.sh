#!/bin/bash

# A Bash script to compile the peakflops program for use on the Xeon 
# chips 
rm -f *.o


# compile helloworld code
ifort -c  -O3 -openmp -opt-threads-per-core=2 -xAVX -align rec16byte  -vec-report3  ./DoublePeakFlops.f -o ./DoublePeakFlops.o

ifort ./DoublePeakFlops.o -openmp -o ./DoublePeakFlops.out
