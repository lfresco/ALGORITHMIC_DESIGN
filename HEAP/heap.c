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

bool Is_Root(int i){

    return i == 0;
}

bool is_Valid_Node(int length, int i){
    return length >= i;
}



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
