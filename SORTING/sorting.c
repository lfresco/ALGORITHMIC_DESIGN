#include <stdlib.h>
#include <stdio.h>
#include "list.h"
void InsertionSortBook (int *A, size_t n)
{
  for (size_t j = 1; j < n; j++)
    {

      int key = A[j];

      int i = j - 1;

      while (i > 0 && A[i] > key)
	{

	  A[i + 1] = A[i];
	  i = i - 1;
	}

      A[i + 1] = key;
    }
}
void InsertionSort(int *a, int n) {
	
    for(int i = 1; i < n; ++i) {
		
        int tmp = a[i];
		int j = i;
		
        while(j > 0 && tmp < a[j - 1]) {
			a[j] = a[j - 1];
			--j;
		}
		a[j] = tmp;
	}
}
void InsertionSortSlides (int *A, int n)
{

  for (int i = 2; i < n; i++)
    {

      int j = i ;

      while (j > 1 && A[j] < A[j - 1])
	  {

	    int tmp = A[j - 1];
	    A[j - 1] = A[j];
	    A[j] = tmp;

	    j = j - 1;

	  }

    }
}

int PartitionBook(int *A, int indexFirst, int indexLast)
{
    int pivot = A[indexLast];
    int i = indexFirst - 1;
    
    for(int j = indexFirst; j < indexLast; j++)
    {
         
        if( A[j] <= pivot ){
            
            i = i + 1;
            
            float tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    
    int tmp = A[i + 1];
    A[i + 1] = A[indexLast];
    A[indexLast] = tmp;
    
    
    return i + 1;
    
    
}

void QuickSortBook(int *A, int indexFirst, int indexLast)
{
    if(indexFirst < indexLast){
        
        int q = PartitionBook(A, indexFirst, indexLast);
         
        QuickSortBook(A, indexFirst, q - 1);
        QuickSortBook(A, q + 1, indexLast);
    }
}


/*
 * Returns maximum number in an array
 * @a array pointer
 * @n number of elements in the array
 */
int max(int * A, int n) {
	
	int max = A[0];
	for (int i = 1; i < n; i++) {
		if (A[i] > max) {
			max = A[i];
		}
	}
	
	return max;
}

/*
 * Performs Radix Sort on a given array
 * @a array pointer
 * @n number of elements in the array
 */
void RadixSort(int * A, int size) {
	
	int m = max(A, size);
	int * b = (int*)calloc(size , sizeof(int));
	

	for (int expo = 1; m / expo > 0; expo*=10) {
		int * bucket = (int*)calloc(size, sizeof(int));
		

		for (int i = 0; i < size; i++)
			bucket[(A[i] / expo) % 10]++;
		for (int i = 1; i < size; i++)
			bucket[i] += bucket[i - 1];
		for (int i = size - 1; i >= 0; i--)
			b[--bucket[(A[i] / expo) % 10]] = A[i];

		for (int i = 0; i < size; i++)
			A[i] = b[i];
			
		free( bucket );
	}
	
	free( b );
}


void swap(int * A, int i, int j){
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

int SelectPivot(int *v, int n, int k){
     if (n == 1 && k == 0) return v[0];
    int m = (n + 4)/5;
    int * medians = (int*)malloc(m * sizeof(int));
    
    for (int i=0; i<m; i++) {
        if (5*i + 4 < n) {
            int * w = v + 5*i;
            for (int j0=0; j0 < 3; j0++) {
                int jmin = j0;
                for (int j=j0+1; j<5; j++) {
                    if (w[j] < w[jmin]) jmin = j;
                }
                swap(w,j0, jmin);
            }
            medians[i] = w[2];
        } else {
            medians[i] = v[5*i];
        }
    }

    int pivot = SelectPivot(medians, m, m/2);
    return pivot;
    free(medians);
}

int Partition(int *v, int n, int pivot){
    
    for (int i=0; i<n; i++) {
        if (v[i] == pivot) {
            swap(v,i, n-1);
            break;
        }
    }

    int store = 0;
    for (int i=0; i<n-1; i++) {
        if (v[i] < pivot) {
            swap(v,i, store++);
        }
    }
    swap(v,store, n-1);

    return store;
}



int Select(int *v, int n, int k) {
   


    int pivot = SelectPivot(v, n, k);
    int store = Partition(v, n, pivot);

    if (store == k) {
        return pivot;
    } else if (store > k) {
        return Select(v, store, k);
    } else {
        return Select(v+store+1, n-store-1, k-store-1);
    }
}

void CountingSort(int * A, int A_length){
    
    int k = Select(A, A_length, A_length - 1);
    
    int * C = (int *)malloc((k + 1) * sizeof(int) );
    
    
    
    int * B = (int*)malloc(sizeof(int)*(A_length + 1 ));
    
    for(int i = 0; i <= k; i++){
        
        C[i] = 0;
    }
    
    for(int j = 0; j < A_length; j++){
        
        C[A[j]] = C[A[j]] + 1;
    }
    
    for(int i = 1; i <= k ; i++){
        
        C[i] = C[i] + C[i - 1];
    }
    
    
    
    for(int j = (A_length -1); j >= 0; j--){
        
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
    //free( C );
    for(int i = 0; i < A_length +  1; i++){
        A[i] = B[i + 1 ];
    }
    
    free( B );
    

}





