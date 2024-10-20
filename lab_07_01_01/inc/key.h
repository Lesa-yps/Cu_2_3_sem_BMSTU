#ifndef KEY_H
#define KEY_H

#include <stdlib.h>
#include <stdio.h>

#include "const.h"
#include "mysort.h"

//фильтр оставляет числа только между минимальным и максимальным (не вкл)
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

#endif // KEY_H
