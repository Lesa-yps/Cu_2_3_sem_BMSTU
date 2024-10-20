#ifndef ADD_MAT_H
#define ADD_MAT_H

// (для корня n-ой степени)
#include <math.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

#include "const_struct.h"

#include "free_mat.h"

// добавляем строки/столбцы до размерности z по определённым правилам (сначала строки потом столбцы)
// (новые столбцы из максимумов по строкам, новые строки из средних геометрических по столбцам)
int add_mat(struct matrix *mat1, int z);

#endif // ADD_MAT_H
