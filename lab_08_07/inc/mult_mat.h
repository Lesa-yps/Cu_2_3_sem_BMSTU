#ifndef MULT_MAT_H
#define MULT_MAT_H

#include <stdio.h>
#include <stdlib.h>

#include "const_struct.h"

#include "create_mat.h"
#include "free_mat.h"
#include "print_mat.h"

// перемножает матрицы нужное количество раз на себя и друг с другом
int mult_mat(struct matrix *res, struct matrix *mat1, struct matrix *mat2, int p, int y);

#endif // MULT_MAT_H
