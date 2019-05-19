    #ifndef SORTING_H__
    #define SORTING_H__
    
    #include <stdlib.h>
    
    void InsertionSortBook(int * A, size_t n);
    
    void InsertionSortSlides(int *A, size_t n);
    
    size_t PartitionBook(int *A, size_t p, size_t n);
    
    void QuickSortBook(int *A,size_t p, size_t n);
    
    float* CountingSort(int * A, int A_length, int* B, int k);

    void RadixSort(int * A, int size);

    int larger_digit(node * head);
    int digit_finder(int number, int k);
    
   //void Bucket_Sort(float* A, int A_length);
    
    #endif //SORTING_H__