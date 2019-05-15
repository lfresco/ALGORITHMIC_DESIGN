#include <stdlib.h>
#include <stdio.h>
#include <math.h>


float **allocate_matrix(const int rows,
                        const int cols)
{
    float **A = (float **)calloc(sizeof(float *), rows);

    for (size_t i = 0; i < rows; i++)
    {
        A[i] = (float *)calloc(sizeof(float), cols);
    }

    for (int i= 0; i < rows; i++)
    {

        for (int j = 0; j < cols; j++)
        {

            A[i][j] = INFINITY;
        }
    }

    return A;
}

void MatrixChainAux(int*P, float** m, float** s, int i, int j){
    
    float q;
    for(int k = i; k <= j - 1; k++){
       
       q = m[i-1][k-1] + m[k ][j-1] + P[i-1]*P[k]*P[j];

        if(q < m[i - 1][j - 1]){
            m[i - 1][j - 1] = q;
            s[i - 1][j - 1] = k;
        }
    }
}

float** MatrixChain(int *P, int dim){

    float ** m = allocate_matrix(dim, dim);
    float ** s = allocate_matrix(dim, dim);

    for(int i = 0; i < dim; i++){

        m[i][i] = 0;
    }

    for(int l = 1; l <= dim; l++){

        for(int i = 1; i <= dim - l + 1; i++){

            int j = i + l - 1;

            MatrixChainAux(P, m, s, i, j);
        }
    }

    print_matrix(m, dim);
    
    deallocate_matrix(m, dim);

    return s;

}

void print_matrix(float** m, int n){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(m[i][j] == INFINITY){
                printf("0.0000 ");
            } else {
                printf("%06.3f ", m[i][j]);
            }
        }
        printf("\n");
    }

    printf("\n");
}

void deallocate_matrix(float **A, const size_t rows)
{
  for (size_t i=0; i<rows; i++) {
    free(A[i]);
  }

  free(A);
}

void correctness_test(int * P, int dim){
    
    printf("Correctness test, see the slides for comparison\n");
    printf("-----------------------------------------------\n");
    float**s;

    s = allocate_matrix(4,4);

    s = MatrixChain(P, 4);
    
    
    print_matrix(s, 4);
    
    deallocate_matrix(s, 4);
    
    printf("------------------------------------------------\n");
     
}


