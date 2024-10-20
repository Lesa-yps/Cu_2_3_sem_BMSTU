#ifndef PRINT_H
#define PRINT_H

#include <stdio.h>
#include <stddef.h>

#include "const.h"

/**

* @brief Функция выводит результаты проверки столбцов матрицы
* @param[in] k - массив результатов проверки столбцов матрицы
* @param[in] n - количество столбцов матрицы
*/

void print(int k[], size_t n);

#endif // PRINT_H
