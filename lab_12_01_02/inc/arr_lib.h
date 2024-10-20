#ifndef ARR_LIB_H
#define ARR_LIB_H

#include <math.h>
#include <stddef.h>
#include <stdio.h>

#define EPS 1e-8

// сдвигает массив циклически на k единиц влево
void arr_go(int *arr, int n, int *arr_new, int k);

// фильтрует массив, оставляя только полные квадраты
int arr_filtr(int *arr, int n, int *arr_new);

#endif // ARR_LIB_H