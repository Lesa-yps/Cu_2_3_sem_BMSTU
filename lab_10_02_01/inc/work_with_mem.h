#ifndef WORK_WITH_MEM_H
#define WORK_WITH_MEM_H

#include <stdlib.h>

#include "const_struct.h"

// создает одну структуру
int create_one(node_t **one_node, int one_coef, int one_deg);

// освобождает одну структуру
void free_one(node_t *one_node);
// освобождает массив структур
void free_all(node_t **head);

// вставляет элемент перед переданным
void insert(node_t **head, node_t *elem, node_t *before);

#endif // WORK_WITH_MEM_H
