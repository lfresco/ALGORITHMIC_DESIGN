#include <stdlib.h>
#include <stdio.h>
void InsertionSortBook (int *A, size_t n)
{
  for (size_t j = 1; j < n; j++)
    {

      int key = A[j];

      size_t i = j - 1;

      while (i > 0 && A[i] > key)
	{

	  A[i + 1] = A[i];
	  i = i - 1;
	}

      A[i + 1] = key;
    }
}

void InsertionSortSlides (int *A, size_t n)
{

  for (size_t i = 2; i < n; i++)
    {

      size_t j = i;

      while (j > 1 && A[j] < A[j - 1])
	  {

	    size_t tmp = A[j - 1];
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

void CountingSort(int * A, int A_length){
    int k = A_length -1;
    int C[k + 1];
    
    int * B = (int*)malloc(sizeof(int)*A_length);
    
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
    
    for(int i = 0; i < A_length; i++){
        A[i] = B[i];
    }
    
    
}

/**
void Bucket_Sort(int* A, int A_length)
{  
    int i, j;  
    int * count = (int *)malloc(sizeof(int) * A_length); 
    for (i = 0; i < A_length; i++)
        count[i] = 0;
 
    for (i = 0; i < A_length; i++)
        (count[A[i]])++;
 
    for (i = 0, j = 0; i < A_length; i++)  
        for(; count[i] > 0; (count[i])--)
            A[j++] = i;
            
    free( count );
} */  

int digit_finder(int number, int k){
    int term, count;
    for(count = 1; count <= k; count++){
        term = number % 10;
        number = number / 10;
    }
    
    return(term);
}
int larger_digit(int * A, int size){
    if(A[0] == -1) return 0;
    int i = 0;
    int tmp = 0;
    int digit = 0;
    
    

    for(int i = 0; i < size; i++){
        if(A[i] > tmp){
            tmp = A[i];
        }
    }

    while(tmp!= 0){
        digit++;
        tmp = tmp/10;
    }

    return(digit);
}
void RadixSort(int * A, int size){
     int count, k, digit, least_significant, most_significant;
     int rear[10], front[10];

     least_significant = 1;
     most_significant = larger_digit(A, size);

     for(k = least_significant; k <= most_significant; k++){
         for(count  = 0; count <= 9; count++){
             rear[count] = -1;
             front[count] = -1;
         }

         for(int i = 0; i < size; i++){
             digit = digit_finder(A[i], k);

             if(front[digit] == -1){
                 front[digit] = A[i];
             } else {
                rear[digit + 1] = A[i];
             }

             rear[digit] = A[i];
         } 

         count = 0;
         while(front[count] == -1){
             count ++;
         }

         A[0] = front[count];

         while(count < 9){
             if(rear[count + 1] != -1 ){
                 rear[count + 1] = front[count + 1];
             } else {
                 rear[count + 1] = rear[count];
             }

             count++;
         }
         
     }
}









int main(int argv, char * argc[]){

    int array[5] = {4,3,2,1,0};

    RadixSort(array, 5);

    for(int i = 0; i < 5; i++){
        printf("A[%d] = %d\n", i, array[i]);
    }

    return 0;
}