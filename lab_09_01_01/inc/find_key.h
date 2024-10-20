#ifndef FIND_KEY_H
#define FIND_KEY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "const_struct.h"

//поиск элемента, возвращает индекс или NOT_FOUND
int find_key(struct film *films, size_t n, char *what, char *key, int *res);

#endif // FIND_KEY_H
