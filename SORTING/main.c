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

#define _POSIX_C_SOURCE 199309L

#include <time.h>
#include "sorting.h"


#define MAX_ELEM_VALUE 21 

void randomly_fill_array(int * A, const size_t n)
{
    for(size_t i = 0; i < n; i++){
        A[i] = (rand()%(2*MAX_ELEM_VALUE)) - MAX_ELEM_VALUE;
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

void correctness_and_time(){
    
    struct timespec b_time, e_time;
    int n_test = 4;
    printf("############# PERFORMANCE AND CORRECTNESS TEST #########\n");
    for (size_t i=10; i<=10000; i*=2){
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

        printf("\t%lf\n", get_execution_time(b_time, e_time));

        clock_gettime(CLOCK_REALTIME, &b_time);
        bucketsort(test_matrix[3], i, 10 );
        clock_gettime(CLOCK_REALTIME, &e_time);

        printf("\t%lf\n", get_execution_time(b_time, e_time));
        
        
        printf("\t%d\n", same_arrays(test_matrix, n_test, i));

        //deallocate_worst_case_m(test_matrix, n_test);



    } 

    printf("########### END OF THE TEST ##########\n");
    
    

    

    
}




void best_case(){
    
    const size_t n=1<<11;  

    struct timespec b_time, e_time;
    printf("############# BEST CASE TEST #############\n");
    for (size_t i=10; i<=10000; i*=2) {
        
        printf("%ld", i);

        int** test_matrix  = best_case_m_all(i);
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

void worst_case(){
    
    const size_t n=1<<11;  

    struct timespec b_time, e_time;
    printf("############# WORST CASE TEST #############\n");
    for (size_t i=10; i<=10000; i*=2) {
        
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
    
    return 0;
  
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /**
    float vet[10];
    
    randomly_fill_array(vet, 10);
    
    for(size_t i = 0; i < 10; i++){
        
        printf("%f \n", vet[i]);
    }
    
    InsertionSortBook(vet, 10);
    
    printf("--------------------AFTER SORTING BOOK-------\n");
    
    for(size_t i = 0; i < 10; i++){
        
        printf("%f \n", vet[i]);
    }
    
    printf("--------------------AFTER SORTING SLIDES-------\n");
    
    randomly_fill_array(vet, 10);
    
    InsertionSortSlides(vet, 10);
    
    for(size_t i = 0; i < 10; i++){
        
        printf("%f \n", vet[i]);
    }
    
    printf("--------------------AFTER QUICKSORTING BOOK--------------\n");
    
    randomly_fill_array(vet, 10);
    
    QuickSortBook(vet, 0, 9);
    
    for(size_t i = 0; i < 10; i++){
        
        printf("%f \n", vet[i]);
    }
    
    
    int vector[10];
    for(int i = 0; i < 10; i++){
        
        vector[i] = 10 - (i+1);
    }
   
    /**
    int sorted_vector[10];
    for(int i = 0; i < 10; i++){
        
        sorted_vector[i] = 0;
    }
    
    printf("--------------------BEFORE COUNTINGSORT--------------\n");
    
    for(size_t i = 0; i < 10; i++){
        
        printf("%i \n", vector[i]);
    }
    
    printf("--------------------AFTER COUNTINGSORT--------------\n");
    
    
    CountingSort(vector, 10, sorted_vector, 9);
    
    for(int i = 0; i <= 10; i++){
        
        printf("%i \n", sorted_vector[i]);
    }
    
    
    
    printf("------------------BEFORE BUCKET SORT--------------------\n");
    
    int vettore[20];
    for(int i  = 0; i < 20; i++){
        
        vettore[i] = 20 - (i + 1);
    }
    
    print_array_int(vettore, 20);
    printf("----------------AFTER BUCKET SORT-----------------------\n");
    bucketsort(vettore, 20,3);
    print_array_int(vettore,20);
    */
 