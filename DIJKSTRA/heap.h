#include <stdbool.h>
#include "graph.h"

#ifndef HEAP_H__
#define HEAP_H__

typedef struct {
    
    node ** nodes;
    int size;
    int original_size;
} heap;

/**
 * @brief return the index of the left child of a given node
 * 
 * @param i, the index of the node
 */
int Left(int i);

/**
 * @brief return the index of the right child of a given node
 * 
 * @param i, the index of the node
 */
int Right(int i);

/**
 * @brief Given an heap and and index value the function returns 1 if the index passed is accettable
 * 
 * @param H, the heap 
 * @param i, the index whose validity we want to check
 */
int isValidNode(heap * H, int i);

/**
 * @brief tells if the index passed identifies the root node
 * 
 * @param i, the index
 */
int isRoot(int i);

/**
 * @brief returns the index of the root of the heap
 * 
 * @param H, the heap whose root we are interested in
 */
int GetRoot(heap* H);

/**
 * @brief given an index i the function returns the index of its parent
 * 
 * @param i, the index of the node
 */
int Parent(int i);

/**
 * @brief a recursive function that makes sure that the min-heap property is respected. the first time it must called
 *        starting from the first element of the array implementation of our heap
 * 
 * @param H, the heap
 * @param i, the index of the node from which we want to make sure the property is respected.
 */
void Heapify(heap * h, int i);

/**
 * @breif this function is used to create the Queue used inside the dijkstra routine
 * 
 * @param g, the graph from which we want to create the Queue
 */
heap * BuildHeap(graph * g);

/**
 * @brief creates an empty heap
 * 
 */
heap * BuildEmptyHeap();

/**
 * @brief auxiliary function that allows us to swap to nodes of an heap
 * 
 * @param h, the heap
 * @param i, the index of the first node
 * @param m, the index of the second node
 * 
 */
void hswap(heap * h, int i, int m);

/**
 * @breif given an heap this function is able to extract the minimum element.
 * 
 */
node * extract_minimum_heap(heap * h);

/**
 * @brief removes the smallest element from the heap
 * 
 * @param h, the heap
 */
void RemoveMinimum(heap * h);


/**
 * @brief deconstructor for the heap function
 * 
 */
void freeHeap(heap * h);

#endif //HEAP_H__