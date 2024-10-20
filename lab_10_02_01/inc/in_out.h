#ifndef IN_OUT_H
#define IN_OUT_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#include "work_with_mem.h"

// чтение полинома
int read_polyn(FILE *file, node_t **head);
// вывод членов многочлена
void print_polyn(node_t *head);

#endif // IN_OUT_H
