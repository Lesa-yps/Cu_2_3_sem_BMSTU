#ifndef ALL_FOR_2D_H
#define ALL_FOR_2D_H

#include <stdlib.h>
#include <stdio.h>

#include "const_struct.h"

int create_2Dmat(struct matrix_2D *mat1, int n_max, int m_max);
void free_2Dmat(struct matrix_2D *mat1);
int made_2Dmat(struct matrix_2D *mat_2D, struct matrix mat);
// вывод матрицы
void print_2Dmat(FILE *file, struct matrix_2D mat);

#endif // ALL_FOR_2D_H
