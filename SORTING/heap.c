#include <stdio.h>
#include <stdlib.h>

#include <math.h>


int Right(int i){
    return 2*i + 1;
}

int Left(int i){
    return 2*i;
}

int Parent(int i){
    return floor(i/2);
}

int Get_Root(){
    
    return 0;
}

int Is_Root(int i){
    
    return i == 0;
}

int is_Valid_Node(int length, int i){
    return length >= i;
}

void Max_Heapify(int *A, int i, int heap_size){
    int right = Right(i);
    int left = Left(i);
    int largest;
    if(left <= heap_size && A[left] > A[i]){
        
       largest = left;
        
    } else {
        
        largest = i;
    }
    
    if(right <= heap_size && A[right] > A[largest]){
        
        largest = right;
    }
    
    if(largest != i){
        
        int tmp = A[i];
        A[i] = A[largest];
        A[largest] = tmp;
        
        Max_Heapify(A, largest, heap_size);
    }
}


void Build_Max_Heap(int * A, int length){
    
    int heap_size = length;
    
    for(int i = floor(length/2); i = 0; i--){
        
        Max_Heapify(A, i, heap_size);
    }
}


void Heapify(int* A, int i, int length){
    
    
    int m = i;
    
    for(int j = Left(i); j < Right(i) + 1; j++){
        if(is_Valid_Node(length, j) && A[j] > A[m]){
            
            m = j;
        }
    }
    
    if(i != m){
        
        
        int tmp = A[i];
        A[i] = A[m];
        A[m] = tmp;
        
        Heapify(A, m, length);
        
    }
    
}

/**
void Remove_Minimum(Heap H, int i){
    
    H.harr[0] = H.harr[H.size];
    
    H.size = H.size - 1;
    
    Heapify(H, 0);
}

void Build_Heap_Aux(Heap H, int i){
    
    if(is_Valid_Node(H, i)){
        
        Build_Heap_Aux(H, Left(i));
        Build_Heap_Aux(H, Right(i));
        
        Heapify(H, i);
        
    }
    
}
*/

void Build_Heap(int* A, int length){
    
    
    
    for(int i = Parent(length); i >= 0; i--){
        
        Heapify(A, i, length);
    }
    
    
}

void HeapSort(int* A, int length){
    
    Build_Heap(A, length);
    
    for(int i = length; i >= 1; i--){
        
        int tmp = A[0];
        A[0] = A[i];
        A[i] = tmp;
        length = length - 1;
        Heapify(A,0, length);
    }
}

void HeapSortIterative(int* A, int length){
    
    Build_Heap(A, length);
    
    for(int i = length; i >= 1; i--){
        
        int tmp = A[0];
        A[0] = A[i];
        A[i] = tmp;
        length = length - 1;
        Heapify_Iterative(A,0, length);
    }
}


void Heapify_Iterative(int * A, int i, int length){
 int largest;
 while ( i <= length) {
    int le = Left(i);
    int ri = Right(i);
    if (le<=length && A[le]>A[i]){
        largest = le;
    }else{
        largest = i;
    } 
    if (ri<=length && A[ri]>A[largest])
        largest = ri;
    if (largest != i)
    {
        int tmp = A[i];
        A[i] = A[largest];
        A[largest] = tmp;
        
        i = largest;
    } else{
        break;
    } 
 }
}
