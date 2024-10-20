#include "key.h"

//поставит на место ind_min минимальный индекс и на место ind_max максимальный индекс
void check(int *ind_min, int *ind_max);

// находит граничные индексы
void find_ind(int *ind_min, int *ind_max, const int *pb_src, const int *pe_src);

//фильтр оставляет числа только между минимальным и максимальным (не вкл)
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int rc = OK;
    int ind_min = 0;
    int ind_max = 0;
    int m;
    // находит граничные индексы
    find_ind(&ind_min, &ind_max, pb_src, pe_src);
    m = ind_max - ind_min - 1;
    // если в итоговый массив должен быть не пустой
    if (m > 0)
    {
        //выделение памяти
        *pb_dst = calloc(m, sizeof(int));
        if (*pb_dst != NULL)
        {
            //заполнение нового массива и присвоение его старому
            for (int i = ind_min + 1; i < ind_max; i++)
                *(*pb_dst + i - (ind_min + 1)) = *(pb_src + i);
            //высчитали адрес конца массива
            *pe_dst = *pb_dst + m;
        }
        else
            rc = ERROR;
    }
    else
        rc = ERROR;
    //возврат кода ошибок
    return rc;
}

// находит граничные индексы
void find_ind(int *ind_min, int *ind_max, const int *pb_src, const int *pe_src)
{
    //нахождение индексов максимального и минимального элементов
    for (int i = 0; (pb_src + i) < pe_src; i++)
    {
        if (*(pb_src + i) > *(pb_src + (*ind_max)))
            (*ind_max) = i;
        if (*(pb_src + i) < *(pb_src + (*ind_min)))
            (*ind_min) = i;
    }
    //сделали так, что индекс минимального меньше индекса максимального
    //(при этом сами элементы не меняли)
    check(ind_min, ind_max);
}

//поставит на место ind_min минимальный индекс и на место ind_max максимальный индекс
void check(int *ind_min, int *ind_max)
{
    if (*ind_min > *ind_max)
        swap(ind_min, ind_max, sizeof(int));
}
