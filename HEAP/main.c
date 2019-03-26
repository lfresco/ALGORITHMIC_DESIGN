
#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/timeb.h>
#include <math.h>
#include "heap.h"

double Log2 (double n){

  return log(n)/log(2);
}

#define MAX_ELEM_VALUE 21

void randomly_fill_array(float * A, const size_t n)
{
    for(size_t i = 0; i < n; i++){
        A[i] = (rand()%(2*MAX_ELEM_VALUE)) - MAX_ELEM_VALUE;
    }
}

double get_execution_time(const struct timespec b_time,
                          const struct timespec e_time);

int main()
{
    struct timespec b_time;
    struct timespec e_time;

    for(size_t i = 4; i < 1000000; i*=2){

        float *A=(float *)malloc(sizeof(float )*i);
        randomly_fill_array(A, i);
        printf("%ld", i);

        clock_gettime(CLOCK_REALTIME, &b_time);
        HeapSort(A, i);
        clock_gettime(CLOCK_REALTIME, &e_time);

        printf("\t%lf", get_execution_time(b_time, e_time));
        double di = (double)i;
        printf("\t%f \n",di * Log2(di));
    }

    printf("\n \n ");


    return 0;

}


double get_execution_time(const struct timespec b_time,
                          const struct timespec e_time)
{
  return (e_time.tv_sec-b_time.tv_sec) +
                   (e_time.tv_nsec-b_time.tv_nsec)/1E9;
}
