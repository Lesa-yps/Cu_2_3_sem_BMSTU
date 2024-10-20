#ifndef CALC_H
#define CALC_H

#include <stdio.h>
#include <math.h>

#include "const.h"

/**
    * @brief Функция расчета среднего и количества чисел в файле.
    * @param file Указатель на файл.
    * @param mean Указатель на переменную, куда будет записано среднее значение.
    * @param n Указатель на переменную, куда будет записано количество чисел в файле.
    * @return Код возврата функции.
    */
int calc_mean_n(FILE *file, double *mean, long int *n);

/**
    * @brief Функция расчета стандартного отклонения.
    * @param file Указатель на файл.
    * @param mean Среднее значение чисел в файле.
    * @param n Количество чисел в файле.
    * @param rc Код возврата функции.
    * @return Значение стандартного отклонения.
    */
double calc_stdev(FILE *file, double mean, long int n, int *err);

/**
    * @brief Функция расчета результата.
    * @param file Указатель на файл.
    * @param mean Среднее значение чисел в файле.
    * @param stdev Стандартное отклонение чисел в файле.
    * @param n Количество чисел в файле.
    * @return Результат расчета.
    */
int calc_res(FILE *file, double mean, double stdev, long int n);

#endif // CALC_H
