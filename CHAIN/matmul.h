#ifndef MATMUL_H__
#define MATMUL_H__

int **allocate_matrix(const int rows,
                        const int cols);



void MatrixChainAux(int*P, int** m, int** s, int i, int j);

int** MatrixChain(int *P, int dim);

void print_matrix(int** m, int n);

void deallocate_matrix(int **A, const size_t rows);

void correctness_test(int * P, int dim);

void execution_time();

int **evaluate_CMM_aux(int ***As, size_t *dims, const size_t n, int **S,
                         size_t i, size_t j);

int **evaluate_CMM(int ***As, size_t *dims, const size_t n, int **S);

int **evaluate_naive_CMM(int ***As, size_t *dims, const size_t n);

int **copy_matrix(int **orig, const size_t rows,
                    const size_t cols);

void print_out_parenthesis_aux(int **S, size_t i, size_t j);

void print_out_parenthesis(int **S, size_t n); 

#endif // MATMUL_H__