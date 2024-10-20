#include <stdio.h>

#include "all_for_2D.h"
#include "all_for_3D.h"

#include "sort_diag.h"

// мои модули
#include "const_struct.h"

// главная функция
int main(void)
{
    // код возврата
    int rc = OK;

    // структурa - матрицa
    struct matrix mat;
    struct matrix_2D mat_2D;

    // если удалось без ошибок прочитать матрицу
    if ((rc = read_mat_all(stdin, &mat)) == OK)
    {
        print_mat(stdout, mat);
        if ((rc = made_2Dmat(&mat_2D, mat)) == OK)
        {
            print_2Dmat(stdout, mat_2D);
            // работает, но на паре сделать не успела, поэтому закомментированно
            //sort_diag(&mat_2D);
            //print_2Dmat(stdout, mat_2D);
            // освободили память из-под матрицы
            free_2Dmat(&mat_2D);
        }
        // освободили память из-под матрицы
        free_mat(&mat);
    }

    // вернули код ошибки
    return rc;
}
