#ifndef READ_ARR_H
#define READ_ARR_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>

#include "const_struct.h"

//функция читает и сортирует массив
int read_arr(FILE *file, struct film **films, size_t *n, char *what);

#endif // READ_ARR_H
