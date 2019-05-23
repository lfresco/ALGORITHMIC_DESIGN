#include <stdbool.h>

#ifndef HEAP_H__
#define HEAP_H__



int Left(int i);

int Right(int i);
int is_Valid_Node(int length, int i);
int Is_Root(int i);
int Get_Root();
int Parent(int i);
void Heapify(int* A, int i, int length);
void Build_Heap(int* A, int lenght);

void HeapSort(int* A, int length);
void Build_Max_Heap(int * A, int length);

void Max_Heapify(int *A, int i, int heap_size);
void Heapify_Iterative(int * A, int i, int length);
void HeapSortIterative(int* A, int length);

#endif //HEAP_H__