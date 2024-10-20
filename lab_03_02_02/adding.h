#ifndef ADDING_H
#define ADDING_H

#include <stddef.h>

#include "const.h"

/**
 * @brief Функция добавляет строку из -1 перед строкой, в которой есть хотя бы 2 элемента с нечётной суммой цифр
 *
 * @param a Указатель на матрицу
 * @param m Указатель на количество строк
 * @param n Количество столбцов
 */
 
void adding(int a[][N_MAX], size_t *m, size_t n);

#endif // ADDING_H
