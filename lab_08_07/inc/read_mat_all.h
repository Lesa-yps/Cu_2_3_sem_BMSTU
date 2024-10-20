#ifndef READ_MAT_ALL_H
#define READ_MAT_ALL_H

#include <stdio.h>
#include <stdlib.h>

#include "create_mat.h"
#include "free_mat.h"

#include "const_struct.h"

// вызывает функции чтения размерностей, выделения памяти под матрицу и чтения элементов матрицы с проверками
int read_mat_all(FILE *file, struct matrix *mat1);

#endif // READ_MAT_ALL_H
