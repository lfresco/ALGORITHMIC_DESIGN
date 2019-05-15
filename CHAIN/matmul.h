#ifndef MATMUL_H__
#define MATMUL_H__

float **allocate_matrix(const int rows,
                        const int cols);

void MatrixChainAux(int*P, float** m, float** s, int i, int j);

float** MatrixChain(int *P, int dim);

void print_matrix(float** m, int n);

void deallocate_matrix(float **A, const size_t rows);

void correctness_test(int * P, int dim);

#endif // MATMUL_H__