#ifndef FIND_KEY_H
#define FIND_KEY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "const_struct.h"

//поиск элемента, возвращает индекс или -5
int find_key(struct film *films, int n, char *what, char *key, int *res);

#endif // FIND_KEY_H
