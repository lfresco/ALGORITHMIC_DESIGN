#include "functions.h"
#include <stdlib.h>
float **allocate_matrix(const size_t rows,
                        const size_t cols)
{
	float **A = (float **)malloc(sizeof(float)*rows);   // alloca un array uguale al numero di righe
	
	for (size_t i = 0 ; i < rows; i ++){
		A[i] = (float *)malloc(sizeof(float) * cols);  // per ogni colonna alloca un array di lunghezza pari al numero di colonne
	}

	return A;
}

