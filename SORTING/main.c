/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>


#include <time.h>
#include "sorting.h"
#include "heap.h"
#include "list.h"

#define MAX_ELEM_VALUE 21 

void randomly_fill_array(float * A, const size_t n)
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
        
        printf("%d \n", A[i]);
    }
}

double get_execution_time(const struct timespec b_time,
                          const struct timespec e_time)
{
  return (e_time.tv_sec-b_time.tv_sec) +
                   (e_time.tv_nsec-b_time.tv_nsec)/1E9;
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
    int ** matrix = (int**)malloc(2 * sizeof(int*));

    for(int i = 0; i < 2; i++){
        matrix[i] = (int*)malloc(n_elements * sizeof(int)); 
        for(int j = 0; j < n_elements; j++){
            matrix[i][j] = j;
        }
    }

    return matrix;
}

void deallocate_worst_case_m(int ** matrix){
    for(int i = 0; i < 2; i++){
        free(matrix[i]);
    }

    free( matrix );
}
int main()
{
    const size_t n=1<<11;   
    // 1) Testing that Insertion Sort and Quicksort both take 
    // O(n^2) in the worst case

    /**
     * La domanda ora è qual è il worst case ?
     * Per insertion Sort il worst case è l'array al contrario
     * in teoria dovrebbe essere simile per quicksort
     * 
     * Devo quindi allocare una matrice 
     * 
     * 
     * 
     */


    struct timespec b_time, e_time;

    for (size_t i=10; i<=1000000; i*=2) {
        
        printf("%ld", i);

        int** test_matrix  = best_case_m_all(i);
        clock_gettime( CLOCK_REALTIME, &b_time);
        InsertionSortBook(test_matrix[0], i);
        clock_gettime(CLOCK_REALTIME, &e_time);

        printf("\t%lf", get_execution_time(b_time, e_time));
    
        clock_gettime(CLOCK_REALTIME, &b_time);
        QuickSortBook(test_matrix[1], 0, i);
        clock_gettime(CLOCK_REALTIME, &e_time);

        printf("\t%lf\n", get_execution_time(b_time, e_time));

        //printf("\t%d\n", i*i);

    
        deallocate_worst_case_m(test_matrix);

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
    return 0;

    
}
