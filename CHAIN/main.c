#include <stdlib.h>
#include <stdio.h>
#include "matmul.h"

#define MAX_ELEM_VALUE 25

void randomly_fill_matrix(float **A, const size_t A_rows, const size_t A_cols)
{
  for (size_t i = 0; i < A_rows; i++)
  {
    for (size_t j = 0; j < A_cols; j++)
    {
      A[i][j] = rand() % (2 * MAX_ELEM_VALUE) - MAX_ELEM_VALUE;
    }
  }
}


int main(int argv, char * argc[]){
    
     

    // Correctness test, i use as benchmark the example shown in class
    
    int P[5] = {3, 5, 10, 2, 3};

   
 
    correctness_test(P, 4);

    
    
    
    
    return 0;


}