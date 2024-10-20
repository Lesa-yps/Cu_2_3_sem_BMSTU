#ifndef READ_H
#define READ_H

#include "const.h"

#include <stddef.h>
#include <stdio.h>


/**

* @brief Функция считывает матрицу a[M_MAX][N_MAX] с помощью scanf
* @param[out] a - матрица считанных значений
* @param[out] m - количество строк матрицы
* @param[out] n - количество столбцов матрицы
* @return код ошибки или OK
*/

int read(int a[][N_MAX], size_t *m, size_t *n);

#endif // READ_H
