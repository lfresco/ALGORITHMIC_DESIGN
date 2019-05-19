#include <math.h>
#include <stdbool.h>
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
/**
void Max_Heapify(float *A, int i, int heap_size){
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
        
        float tmp = A[i];
        A[i] = A[largest];
        A[largest] = tmp;
        
        Max_Heapify(A, largest, heap_size);
    }
}


void Build_Max_Heap(float * A, int length){
    
    int heap_size = length;
    
    for(int i = floor(length/2); i = 0; i--){
        
        Max_Heapify(A, i, heap_size);
    }
}
*/

void Heapify(float* A, int i, int length){
    
    
    int m = i;
    
    for(int j = Left(i); j < Right(i) + 1; j++){
        if(is_Valid_Node(length, j) && A[j] > A[m]){
            
            m = j;
        }
    }
    
    if(i != m){
        
        
        float tmp = A[i];
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

void Build_Heap(float* A, int length){
    
    
    
    for(int i = Parent(length); i >= 0; i--){
        
        Heapify(A, i, length);
    }
    
    
}

void HeapSort(float* A, int length){
    
    Build_Heap(A, length);
    
    for(int i = length; i >= 1; i--){
        
        float tmp = A[0];
        A[0] = A[i];
        A[i] = tmp;
        length = length - 1;
        Heapify(A,0, length);
    }
}