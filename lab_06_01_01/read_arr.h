#ifndef READ_ARR_H
#define READ_ARR_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

#include "const_struct.h"

//функция читает и сортирует массив
int read_arr(FILE *file, struct film *films, int *n, char *what);

#endif // READ_ARR_H
