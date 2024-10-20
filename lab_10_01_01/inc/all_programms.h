#ifndef ALL_PROGRAMMS_H
#define ALL_PROGRAMMS_H

#include <stdlib.h>
#include <stddef.h>

#include "const_struct.h"

// 1 работа с 1 элементом в односвязном списке

// вставка элемента перед данным
void insert(node_t **head, node_t *elem, node_t *before);
// достаётся и удаляется из списка перый элемент
void *pop_front(node_t **head);

// 2 работа с односвязным списком целиком

// разворот односвязного спискка (возвращается «новая» голова)
node_t *reverse(node_t *head);

// 3 сортировка & односвязный список целиком

// вставка элемента в нужное место в отсортированном односвязном списке
void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *));
// сортировка односвязного списка вставками с помощью функции sorted_insert
node_t *sort(node_t *head, int (*comparator)(const void *, const void *));

#endif // ALL_PROGRAMMS_H
