
#ifndef FUNCTIONS__


float **allocate_matrix(const size_t rows,
                        const size_t cols);

void MatrixChainAux(int*P, float** m, float** s, size_t i, size_t j);

float** matrix_chain(int *P, size_t dim);



#endif  // FUNCTIONS__