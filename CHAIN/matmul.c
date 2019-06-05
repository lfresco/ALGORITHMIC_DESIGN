#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>







int **allocate_matrix(const int rows,
                        const int cols)
{
    int **A = (int **)calloc(sizeof(int *), rows);

    for (size_t i = 0; i < rows; i++)
    {
        A[i] = (int *)calloc(sizeof(int), cols);
    }

    for (int i= 0; i < rows; i++)
    {

        for (int j = 0; j < cols; j++)
        {

            A[i][j] = INT_MAX;
        }
    }

    return A;
}


int **copy_matrix(int **orig, const size_t rows,
                    const size_t cols)
{
  int **C=allocate_matrix(rows, cols);

  for (size_t i=0; i<rows; i++) {
    for (size_t j=0; j<cols; j++) {
      C[i][j]=orig[i][j];
    }
  }

  return C;
}


void print_matrix(int** m, int n){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(m[i][j] == INT_MAX){
                printf("0 ");
            } else {
                printf("%d ", m[i][j]);
            }
        }
        printf("\n");
    }

    printf("\n");
}

void deallocate_matrix(int **A, const int rows)
{
  for (int i=0; i<rows; i++) {
    free(A[i]);
  }

  free(A);
}

void MatrixChainAux(int*P, int** m, int** s, int i, int j){
    
    int q;
    for(int k = i; k <= j - 1; k++){
       
       q = m[i-1][k-1] + m[k ][j-1] + P[i-1]*P[k]*P[j];

        if(q < m[i - 1][j - 1]){
            m[i - 1][j - 1] = q;
            s[i - 1][j - 1] = k;
        }
    }
}

int** MatrixChain(int *P, int dim){

    int ** S = allocate_matrix(dim, dim);
    int ** M = allocate_matrix(dim, dim);
    
    for(int i = 0; i < dim; i++){

        M[i][i] = 0;
    }

    for(int l = 1; l <= dim; l++){

        for(int i = 1; i <= dim - l + 1; i++){

            int j = i + l - 1;

            MatrixChainAux(P, M, S, i, j);
        }
    }
    print_matrix(M, dim);
    deallocate_matrix(M, dim);
    
    return S;

}




