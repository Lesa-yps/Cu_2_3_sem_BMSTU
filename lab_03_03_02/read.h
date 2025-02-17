#ifndef READ_H
#define READ_H

#include <stdio.h>
#include <stddef.h>

#include "const.h"

/**
 * @brief Функция считывает матрицу из стандартного ввода
 *
 * @param a Указатель на матрицу
 * @param m Указатель на количество строк
 * @param n Указатель на количество столбцов
 * @return int Код ошибки
 */
 
int read(int a[][N_MAX], size_t *m, size_t *n);

#endif // READ_H
