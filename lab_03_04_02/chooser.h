#ifndef CHOOSER_H
#define CHOOSER_H

#include <stddef.h>

#include "const.h"

/**
 * @brief Функция выбирает из матрицы элемент, который оканчивается на 5 и находится под побочной диагональю
 *
 * @param a Указатель на матрицу
 * @param m Количество строк
 * @return int Выбранный элемент
 */
 
int chooser(int a[][M_MAX], size_t m);

#endif // CHOOSER_H
