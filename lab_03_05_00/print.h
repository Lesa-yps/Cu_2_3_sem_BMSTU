#ifndef PRINT_H
#define PRINT_H

#include <stdio.h>
#include <stddef.h>

#include "const.h"

/**
 * @brief Функция выводит матрицу в стандартный вывод
 *
 * @param a Указатель на матрицу
 * @param m Количество строк
 * @param n Количество столбцов
 */
 
void print(int a[][N_MAX], size_t m, size_t n);

#endif // PRINT_H
