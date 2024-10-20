#include "count_num_lib.h"

//считает количество чисел в файле
int count_num(FILE* file, int *n)
{
    // код возврата
    int rc = OK;
    // что вернёт fscanf
    int ret;
    // количество чисел в файле
    *n = 0;
    // вспомогательная переменная для чтения чисел из файла
    int x;
    // пока числа читаются читаем и считаем их
    while ((ret = fscanf(file, "%d", &x)) == 1)
        (*n)++;
    // если не прочитали ни одного числа или файл не закончился
    // вместе с выходом из цикла - ошибка
    if ((*n == 0) || (ret != EOF))
        rc = ERROR;
    // вернули код ошибки
    return rc;
}
