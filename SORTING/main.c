/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "list.h"
#include <math.h>
#define _POSIX_C_SOURCE 199309L

#include <time.h>
#include "sorting.h"


#define MAX_ELEM_VALUE 50

void randomly_fill_array(int * A, const size_t n)
{
    for(size_t i = 0; i < n; i++){
        A[i] =abs((int)((rand()%(2*MAX_ELEM_VALUE)) - MAX_ELEM_VALUE));
    }
}
void print_array_float(float * A, int A_length){
    
    for(int i = 0; i < A_length; i++){
        
        printf("%f \n", A[i]);
    }
}

void print_array_int(int A[], int A_length){
    
    for(int i = 0; i < A_length; i++){
        
        printf("%d ", A[i]);
    }
}

double get_execution_time(const struct timespec b_time,
                          const struct timespec e_time)
{
  return (e_time.tv_sec-b_time.tv_sec) +
                   (e_time.tv_nsec-b_time.tv_nsec)/1E9;
}


int** allocate_corr_matrix(int n_elements, int n_test){
    /** 
     * I have to test the correctnesss and evaluate the execution time of all the algorithms 
     * 
     * 1) Insertion Sort
     * 2) QuickSort
     * 3) HeapSort
     * 4) CountingSort
     * 5) RadixSort
     * 6) BucketSort
     * 
     */

    int ** test_matrix = (int**)malloc(sizeof(int*) * n_test);
        
            test_matrix[0] = (int*)malloc(n_elements * sizeof(int));
            randomly_fill_array(test_matrix[0], n_elements);
        if(n_test > 1){
            for(int i = 1; i < n_test; i++){
                test_matrix[i] = (int*)malloc(n_elements * sizeof(int));
                for(int j = 0; j < n_elements; j++){
                    test_matrix[i][j] = test_matrix[0][j];
                }
            }
        }
        return test_matrix;



}


int ** worst_case_m_all(int n_elements){
    int ** matrix = (int**)malloc(2 * sizeof(int*));

    for(int i = 0; i < 2; i++){
        matrix[i] = (int*)malloc(n_elements * sizeof(int)); 
        for(int j = 0; j < n_elements; j++){
            matrix[i][j] = n_elements - j;
        }
    }

    return matrix;
}


int ** best_case_m_all(int n_elements){
    int ** matrix = (int**)malloc( n_elements* sizeof(int*));

    for(int i = 0; i < 2; i++){
        matrix[i] = (int*)malloc(n_elements * sizeof(int)); 
        for(int j = 0; j < n_elements; j++){
            matrix[i][j] = j;
        }
    }

    return matrix;
}

void deallocate_worst_case_m(int ** matrix, int n_test){
    for(int i = 0; i < n_test; i++){
        free(matrix[i]);
    }

    free( matrix );
}

int same_array(const int *A, const int * B, const int size){
    
    for(int i = 0; i < size; i++){
        if(A[i] != B[i]) return 0;
    }
    return 1;

}

int same_arrays(int** matrix, const int n_test, const int n_elements){
    
    for(int i  = 0; i < (n_test - 1); i++ ){
        if(same_array(matrix[i], matrix[i+1], n_elements)){
            return 1;
        } else {
            return 0;
        }
    }

    
}

void deallocate_matrices(int ** test_matrix, int n_test)
{
    for(int i = 0; i < n_test; i++){
        free( test_matrix[i] );
    }
    
    free(test_matrix);
}
void correctness_and_time(){
    
    struct timespec b_time, e_time;
    int n_test = 3;
    printf("############# PERFORMANCE AND CORRECTNESS TEST #########\n");
    printf("Size \tInsertionSort \tQuickSort \t HeapSort \tCorrectness\n");
    for (size_t i=10; i<=100000; i*=2){
        printf("%ld", i);
        
        int ** test_matrix = allocate_corr_matrix(i, n_test);
       
        clock_gettime( CLOCK_REALTIME, &b_time);
        InsertionSort(test_matrix[0], i);
        clock_gettime(CLOCK_REALTIME, &e_time);

        printf("\t%lf", get_execution_time(b_time, e_time));
    
        clock_gettime(CLOCK_REALTIME, &b_time);
        QuickSortBook(test_matrix[1], 0, i - 1);
        clock_gettime(CLOCK_REALTIME, &e_time);

        printf("\t%lf", get_execution_time(b_time, e_time));
        
        clock_gettime(CLOCK_REALTIME, &b_time);
        HeapSort(test_matrix[2], i );
        clock_gettime(CLOCK_REALTIME, &e_time);

        printf("\t%lf", get_execution_time(b_time, e_time));


        
        
        
        printf("\t%d\n", same_arrays(test_matrix, n_test, i));

        deallocate_worst_case_m(test_matrix, n_test);



    } 

    printf("########### END OF THE TEST ##########\n");
    
    

    

    
}

void linear_sorting()
{
    struct timespec b_time, e_time;
    int n_test = 3;
    printf("############# LINEAR SORTING #########\n");
    printf("Size \tRadixSort \tCountingSort \tBucketSort \tCorrectness\n");
    for (size_t i=10; i<=100000; i*=2){
        printf("%ld", i);
        
        int ** test_matrix = allocate_corr_matrix(i, n_test);
       
        clock_gettime( CLOCK_REALTIME, &b_time);
        RadixSort(test_matrix[0], i);
        clock_gettime(CLOCK_REALTIME, &e_time);

        printf("\t%lf", get_execution_time(b_time, e_time));
    
        clock_gettime(CLOCK_REALTIME, &b_time);
        CountingSort(test_matrix[1], i);
        clock_gettime(CLOCK_REALTIME, &e_time);

        printf("\t%lf", get_execution_time(b_time, e_time));
        
        
        clock_gettime(CLOCK_REALTIME, &b_time);
        BucketSort(test_matrix[2], i, i/5 );
        clock_gettime(CLOCK_REALTIME, &e_time);

        printf("\t%lf", get_execution_time(b_time, e_time));
        
       
        
        
        printf("\t%d\n", same_arrays(test_matrix, n_test, i));

        


    } 

    printf("########### END OF THE TEST ##########\n");
}



void best_case(){
    
    const size_t n=1<<11;  

    struct timespec b_time, e_time;
    printf("############# BEST CASE TEST #############\n");
    printf("Size \tInsertionSort \tQuickSort \tCorrectness\n");
    for (size_t i=10; i<=40000; i*=2) {
        
        printf("%ld", i);

        int** test_matrix  = best_case_m_all(i);
        clock_gettime( CLOCK_REALTIME, &b_time);
        InsertionSort(test_matrix[0], i);
        clock_gettime(CLOCK_REALTIME, &e_time);

        printf("\t%lf", get_execution_time(b_time, e_time));
    
        clock_gettime(CLOCK_REALTIME, &b_time);
        QuickSortBook(test_matrix[1], 0, i/2);
        clock_gettime(CLOCK_REALTIME, &e_time);

        printf("\t%lf", get_execution_time(b_time, e_time));

        printf("\t%d\n", same_array(test_matrix[0], test_matrix[1], i));

    
        deallocate_worst_case_m(test_matrix, 2);

    }

        printf("############# END TEST #############\n");

}

void worst_case(){
    
    const size_t n=1<<11;  

    struct timespec b_time, e_time;
    printf("############# WORST CASE TEST #############\n");
    printf("Size \tInsertionSort \tQuickSort \tCorrectness\n");
    for (size_t i=10; i<=40000; i*=2) {
        
        printf("%ld", i);

        int** test_matrix  = worst_case_m_all(i);
        clock_gettime( CLOCK_REALTIME, &b_time);
        InsertionSort(test_matrix[0], i);
        clock_gettime(CLOCK_REALTIME, &e_time);

        printf("\t%lf", get_execution_time(b_time, e_time));
    
        clock_gettime(CLOCK_REALTIME, &b_time);
        QuickSortBook(test_matrix[1], 0, i - 1);
        clock_gettime(CLOCK_REALTIME, &e_time);

        printf("\t%lf", get_execution_time(b_time, e_time));


        printf("\t%d\n", same_array(test_matrix[0], test_matrix[1], i));

    
        deallocate_worst_case_m(test_matrix, 2);

    }

        printf("############# END TEST #############\n");

}

int main(int argv, char * argc[])
{


    best_case();
    worst_case();

    correctness_and_time();
    linear_sorting();
    return 0;
  
}
 