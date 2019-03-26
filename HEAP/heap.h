#include <stdbool.h>

#ifndef HEAP_H__
#define HEAP_H__



int Left(int i);

int Right(int i);
bool is_Valid_Node(int length, int i);
bool Is_Root(int i);
int Get_Root();
int Parent(int i);
void Heapify(float* A, int i, int length);
void Build_Heap(float* A, int lenght);

void HeapSort(float* A, int length);
/**
void Build_Max_Heap(float * A, int length);

void Max_Heapify(float *A, int i, int heap_size);
*/
#endif //HEAP_H__
