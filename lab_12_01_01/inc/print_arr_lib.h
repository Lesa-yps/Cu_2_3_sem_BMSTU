#ifndef PRINT_ARR_H
#define PRINT_ARR_H

#include <stdio.h>
#include <stddef.h>

#include "const.h"

// вывод массива в файл
int print_arr(FILE* file, int *arr_beg, int *arr_end);

#endif // PRINT_ARR_H
