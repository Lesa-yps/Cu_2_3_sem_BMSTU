#ifndef MYSORT_H
#define MYSORT_H

#include <stdio.h>
#include <stddef.h>

//сортирует элементы массива выбором
void mysort(void *arr, size_t n, size_t size, int (*compare)(const void *, const void *));

//обмен двух элементов массива
void swap(void *left, void *right, size_t size);

#endif // MYSORT_H
