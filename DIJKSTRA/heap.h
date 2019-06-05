#include <stdbool.h>
#include "graph.h"

#ifndef HEAP_H__
#define HEAP_H__

typedef struct {
    
    node ** nodes;
    int size;
    int original_size;
} heap;

int Left(int i);

int Right(int i);
int isValidNode(heap * H, int i);
int isRoot(int i);
int GetRoot(heap* H);
int Parent(int i);

void Heapify(heap * h, int i);
heap * BuildHeap(graph * g);
heap * BuildEmptyHeap();


//void hswap(heap * h, int i, int m);

void hswap(node** n1, node** n2);
node * extract_minimum_heap(heap * h);
void RemoveMinimum(heap * h);

void freeHeap(heap * h);

//void Heapify_Iterative(float * A, int i, int length);
//void HeapSortIterative(float* A, int length);
/**
void Build_Max_Heap(float * A, int length);

void Max_Heapify(float *A, int i, int heap_size);
*/
#endif //HEAP_H__