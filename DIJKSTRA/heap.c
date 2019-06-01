#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "graph.h"
#include <math.h>

void freeHeap(heap * h)
{
    for(int i = 0; i < h -> original_size; i++)
       freeNode(h -> nodes[i]);
       
    free( h );
}

int Left(int i)
{
    return 2 *i + 1;
}

int Right(int i)
{
    return (2 * i) + 2;
}

int Parent(int i)
{
    return floor(i / 2);
}

int IsValidNode(heap * h, int i)
{
    return h -> size >= i;
}

int getRoot()
{
    return 0;
}

void RemoveMinimum(heap * h)
{
    h -> nodes[0] = h -> nodes[h->size - 1];
    
    h -> size--;
    
  
}


node * extract_minimum_heap(heap * h)
{
    node * tmp = h -> nodes[0];
    RemoveMinimum(h);
    
    Heapify(h, 0);
    return tmp;
}





heap * BuildEmptyHeap()
{
    heap * h = (heap*)malloc(sizeof(heap));
    h-> nodes = NULL;
    h -> size = 0;
}


heap * BuildHeap(graph * g)
{
    int size = g -> nodes_len;
    node ** heap_nodes = (node**)malloc(size * sizeof(node*));
    for(int i = 0; i < size; i++)
    {
        heap_nodes[i] = g -> nodes[i];
    }
    
    heap * h = BuildEmptyHeap();
    
    h -> nodes = heap_nodes;
    h -> size = size;
    h -> original_size = size;
    
    Heapify(h, 0);
    
    return h;
}



void hswap(heap * h, int i, int m)
{
    node * tmp = h -> nodes[i];
    h -> nodes[i] = h -> nodes[m];
    h -> nodes[m] = tmp;
}

void Heapify(heap * h, int i)
{
    int smallest = (Left(i) < h -> size && h -> nodes[Left(i)] -> dist < h -> nodes[i] -> dist) ? Left(i) : i;
    
    if(Right(i) < h -> size && h -> nodes[Right(i)] -> dist < h -> nodes[smallest] -> dist)
    {
        smallest = Right(i);
    }
    
    if(smallest != i)
    {
        hswap(h, i, smallest);
        Heapify(h, smallest);
    }
}


