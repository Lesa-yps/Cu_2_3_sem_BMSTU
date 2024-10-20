#ifndef CHECK_H
#define CHECK_H

#include <stdio.h>
#include <stddef.h>

#include "const.h"

/**

* @brief Функция проверяет чередование знака элементов в столбце матрицы
* @param[in] a - матрица, которую нужно проверить
* @param[in] m - количество строк матрицы
* @param[in] j - номер столбца, который нужно проверить
* @return 1, если в столбце есть отрицательные элементы, и 0 в противном случае
*/

int check(int a[][N_MAX], size_t m, size_t i);

#endif // CHECK_H
