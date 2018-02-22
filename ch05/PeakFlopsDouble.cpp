#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

unsigned int const SIZE=16;
unsigned int const ITER=48000000;
extern double elapsedTime (void);

int main()
{
     double startTime, duration;
     int i;

    __declspec(aligned(64)) double a[SIZE],b[SIZE],c[SIZE];


    //intialize
    for (i=0; i<SIZE;i++)
     {
         c[i]=b[i]=a[i]=(double)rand();
    }
//warm up cache
     #pragma omp parallel for
     for(i=0; i<ITER;i++) {
     #pragma vector aligned (a,b,c)
      a[0:SIZE]=b[0:SIZE]*c[0:SIZE]+a[0:SIZE];
    }

    startTime = elapsedTime();
     #pragma omp parallel for
    for(i=0; i<ITER;i++) {
    #pragma vector aligned (a,b,c)
    a[0:SIZE]=b[0:SIZE]*c[0:SIZE]+a[0:SIZE];
    }

    duration = elapsedTime() - startTime;

     double Gflop = 2*SIZE*ITER/1e+9;
     double Gflops = Gflop/duration;

     printf("Running %d openmp threads\n", omp_get_max_threads());
     printf("DP GFlops = %f\n", Gflops);
 return 0;
}
