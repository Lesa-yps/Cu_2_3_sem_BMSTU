#include "read_arr_lib.h"

//чтение массива из файла
int read_arr(FILE* file, int *arr_beg, int *arr_end)
{
    int rc = OK;
    while ((arr_beg < arr_end) && (rc == OK))
    {
        // если что-то во время чтения элемента пошло не так - ошибка
        if (fscanf(file, "%d", arr_beg) != 1)
            rc = ERROR;
        arr_beg++;
    }
    return rc;
}
