    #ifndef SORTING_H__
    #define SORTING_H__
    
    #include <stdlib.h>
    #include "list.h"
    
    void InsertionSortBook(int * A, int n);
    
    void InsertionSortSlides(int *A, size_t n);
    void InsertionSort(int *a, int n);
    
    size_t PartitionBook(int *A, size_t p, size_t n);
    
    void QuickSortBook(int *A,int p, int n);
    
    void CountingSort(int * A, int A_length, int* B, int k);

    void RadixSort(int * A, int size);
    
   int max(int * a, int n) ;


    //int larger_digit(node * head);
    //int digit_finder(int number, int k);
    
   //void Bucket_Sort(float* A, int A_length);
    
    #endif //SORTING_H__