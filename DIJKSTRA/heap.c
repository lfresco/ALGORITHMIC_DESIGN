#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "graph.h"
#include <math.h>


#define MIN_HEAP_ORDERING <=

void freeHeap(heap * h)
{
    for(int i = 0; i < h -> original_size; i++)
       freeNode(h -> nodes[i]);
       
    free( h );
}

int Left(int i)
{
    return (2 * i) + 1 ;
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
/**
void RemoveMinimum(heap * h)
{
    hswap(h, 0, h -> size - 1);
    
    h -> size--;
    Heapify(h, 0);
    
  
}
*/
node * extract_minimum_heap(heap * h)
{
    node * tmp = h -> nodes[0];
    //printf(" node min dist %d\n", tmp -> dist);
    hswap(&(h->nodes[0]), &(h->nodes[h -> size - 1]) );
    h -> size --;
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
/**
void hswap(heap* h, const int i, const int m) {
  const int size = h -> size;
  if (i <= size - 1 && m <= size - 1) {
    node * tmp1 = h -> nodes[i];
    node * tmp2 = h -> nodes[m];

    h -> nodes[i] = tmp2;
    h -> nodes[m] = tmp1;
  }
}


void hswap(heap * h, int i, int m)
{
    node * tmp = (h -> nodes[i]);
    (h -> nodes[i]) = (h -> nodes[m]);
    (h -> nodes[m]) = tmp;
}

/**
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


void Heapify(heap * h, int i)
{
    int m = i;
    
    for(int j = Left(i); j < Right(i); j++)
    {
        if(IsValidNode(h, j) && (h -> nodes[i]-> dist) < (h -> nodes[m] -> dist))
        {
            m = j;
        }
    }
    
    if(m != i)
    {
        hswap(h, i, m);
        Heapify(h, m);
    }
}

/**
void Heapify(heap* h,  int i) {
  int size = h -> size;

  int l = Left(i);
  int r = Right(i);
  int largest;

  if ( l <= size - 1 && ((h -> nodes[l])-> dist) MIN_HEAP_ORDERING ((h -> nodes[i])->dist) ) {
    largest = l;
  } else {
    largest = i;
  }

  if ( r <= size-1 && ((h -> nodes[r])->dist) MIN_HEAP_ORDERING ((h -> nodes[largest])->dist) ) {
    largest = r;
  }

  if ( largest != i ) {
    hswap(h, i, largest);
    Heapify(h, largest);
  }

}
*/

/**
node * extract_minimum_heap(heap* h) {
  if (h -> size == 0) {
    printf("Error, heap underflow");
  }
  node * minimum = h -> nodes[0];
  h -> nodes[0] = h -> nodes[h -> size -1];
  h -> size -= 1;
  if (h -> size > 0) Heapify(h, 0);
  return minimum;
}


*/


void hswap(node** n1, node** n2)
{
    node *tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

void Heapify(heap * h, int i)
{
    int left = 2 *i + 1;
    int right = 2 * i + 2;
    
    int smallest;
    
    if(left < h -> size && h -> nodes[left]-> dist < h -> nodes[i]-> dist)
    {
        smallest = left;
    } else {
        smallest = i;
    }
    
    if(right < h -> size && h -> nodes[right]-> dist < h -> nodes[smallest]-> dist)
    {
        smallest = right;
    }
    
    if( smallest != i)
    {
        hswap(&(h-> nodes[i]), &(h-> nodes[smallest]));
        Heapify(h, smallest);
    }
}







