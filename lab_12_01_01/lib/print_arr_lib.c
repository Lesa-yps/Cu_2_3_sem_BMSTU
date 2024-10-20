#include "print_arr_lib.h"

// вывод массива в файл
int print_arr(FILE* file, int *arr_beg, int *arr_end)
{
    int rc = OK;
    int res;
    while ((arr_beg < arr_end) && (rc == OK))
    {
        // если что-то во время вывода элемента пошло не так - ошибка
        if ((res = fprintf(file, "%d ", *arr_beg)) < 0)
            rc = ERROR;
        arr_beg++;
    }
    fprintf(file, "\n");
    return rc;
}
