#ifndef ALL_FOR_3D_H
#define ALL_FOR_3D_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "const_struct.h"

int create_mat(struct matrix *mat1, int n_max, int m_max, int k_max);
void free_mat(struct matrix *mat1);
int read_mat_all(FILE *file, struct matrix *mat1);
// вывод матрицы
void print_mat(FILE *file, struct matrix mat);

#endif // ALL_FOR_3D_H
