#include <stdlib.h>
#include <stdio.h>
#include "matmul.h"
#include <time.h>

#define MAX_ELEM_VALUE 25
#define REPETITIONS 3
#define BILLION 1E9


  

int main(int argv, char * argc[]){
  
  int row1 = 3, col1 = 5;
  //A[1] = allocate_matrix(row1, col1);

  int row2 = 5, col2 = 10;
  //A[2] = allocate_matrix(row2, col2);

  int row3 = 10, col3 = 2;
  // A[3] = allocate_matrix(row3, col3);

  int row4 = 2, col4 = 3;
  //A[4] = allocate_matrix(row4, col4);

  int P[5];

  //P[0] = row1; P[1] = col1; P[2] = row2; P[3] = col2; P[4] = row3; P[5] = col3; P[6] = row4; P[7] = col4;

  P[0] = row1;
  P[1] = col1;
  P[2] = col2;
  P[3] = col3;
  P[4] = col4;

  int **s;

  s = allocate_matrix(4, 4);

  s = MatrixChain(P, 4);

  print_matrix(s, 4);

  return 0;
}


