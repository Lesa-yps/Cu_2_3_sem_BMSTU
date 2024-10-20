#ifndef WORK_WITH_MEM_H
#define WORK_WITH_MEM_H

#include <stddef.h>
#include <stdlib.h>

#include "const_struct.h"

// создает одну структуру
int create_one(struct film *one, int len_str);
//создает массив структур
int create_arr(struct film **films, size_t n, int len_str);

// освобождает одну структуру
void free_one(struct film *one);
// освобождает массив структур
void free_arr(struct film films[], size_t n);

#endif // WORK_WITH_MEM_H
