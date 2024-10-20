#ifndef CREATE_MAT_H
#define CREATE_MAT_H

#include <stdlib.h>
#include <stdio.h>

#include "const_struct.h"

// выделяет память под матрицу
int create_mat(struct matrix *mat1, int n_max, int m_max);

#endif // CREATE_MAT_H
