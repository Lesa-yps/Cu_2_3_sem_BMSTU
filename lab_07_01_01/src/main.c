#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

//подключение моих модулей-функций
#include "const.h"
#include "count_num.h"
#include "read_arr.h"
#include "key.h"
#include "mysort.h"
#include "print_arr.h"

//компаратор сравнения двух целых чисел
int comparator(const void *a, const void *b);

// контроллер выполняет работу в зависимости от пере данных аргументов
int controller(int argc, FILE *file_out, int *n, int *arr);

// функция читает файл
int read_file(FILE *file_in, int *n, int **arr);

int main(int argc, char **argv)
{
    FILE *file_in;
    FILE *file_out;
    int rc = OK;
    int n;
    int *arr = NULL;
    //проверка аргументов
    if ((argc != COUNT_ARGS_MIN) && (argc != COUNT_ARGS_MAX))
        rc = ERROR;
    else if (argc == COUNT_ARGS_MAX)
        if (strcmp(*(argv + FILTR), "f") != 0)
            rc = ERROR;

    if (rc == OK)
    {
        //открытие файлов и их проверка
        file_in = fopen(*(argv + FILE_IN), "r");
        file_out = fopen(*(argv + FILE_OUT), "w");
        if (file_in == NULL || file_out == NULL)
            rc = ERROR;
        else
        {
            // функция читает файл
            rc = read_file(file_in, &n, &arr);
            if (rc == OK)
                rc = controller(argc, file_out, &n, arr);
            //освобождение памяти
            if (arr != NULL)
                free(arr);
        }
        //закрытие файлов
        if (file_in != NULL)
            fclose(file_in);
        if (file_out != NULL)
            fclose(file_out);
    }
    //возврат кода ошибки
    return rc;
}

// функция читает файл
int read_file(FILE *file_in, int *n, int **arr)
{
    int rc = OK;
    //чтение количества элементов из файла и их самих
    rc = count_num(file_in, n);
    if (rc == OK)
    {
        //выделение памяти
        *arr = calloc((*n), sizeof(int));
        if (*arr != NULL)
        {
            // Возвращаемся в начало файла
            fseek(file_in, 0, SEEK_SET);
            rc = read_arr(file_in, *arr, (*arr) + (*n));
        }
        else
            rc = ERROR;
    }
    return rc;
}

// контроллер выполняет работу в зависимости от пере данных аргументов
int controller(int argc, FILE *file_out, int *n, int *arr)
{
    int *arr_new_begin = NULL;
    int *arr_new_end;
    int rc = OK;
    //фильтрация (при необходимости) сортировка и вывод массива в файл
    if (argc == COUNT_ARGS_MAX)
    {
        if (! (rc = key(arr, arr + (*n), &arr_new_begin, &arr_new_end)))
        {
            mysort(arr_new_begin, arr_new_end - arr_new_begin, sizeof(int), comparator);
            print_arr(file_out, arr_new_begin, arr_new_end);
            free(arr_new_begin);
        }
    }
    // argc == COUNT_ARGS_MIN (нет фильтрации)
    else
    {
        mysort(arr, *n, sizeof(int), comparator);
        print_arr(file_out, arr, arr + *n);
    }
    return rc;
}

// Компаратор сравнения двух целых чисел
int comparator(const void *a, const void *b)
{
    const int *int_a = (const int *)a;
    const int *int_b = (const int *)b;

    return *int_a - *int_b;
}
