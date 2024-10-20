#include <stdlib.h>

#include "const_struct.h"
#include "del_mat.h"
#include "add_mat.h"
#include "read_counts_mult.h"
#include "mult_mat.h"
#include "print_mat.h"
#include "read_mat_all.h"
#include "free_mat.h"

// главная функция
int main(void)
{
    // код возврата
    int rc = OK;
    // итоговая размерность
    int z;
    // количество перемножений А и В соответственно
    int p, y;
    // структуры - матрицы
    struct matrix mat1;
    struct matrix mat2;
    struct matrix res;
    // если удалось без ошибок прочитать матрицу А
    if ((rc = read_mat_all(stdin, &mat1)) == OK)
    {
        // если удалось без ошибок прочитать матрицу В
        if ((rc = read_mat_all(stdin, &mat2)) == OK)
        {
            // удаление строк/столбцов до квадратности
            if ((rc = del_mat(&mat1)) == OK)
            {
                if ((rc = del_mat(&mat2)) == OK)
                {
                    //нашли максимальную получившуюся размерность
                    if (mat1.n > mat2.n)
                        z = mat1.n;
                    else
                        z = mat2.n;
                    // перевыделяем память и дозаполняем матрицы
                    if ((rc = add_mat(&mat1, z)) == OK)
                    {
                        if ((rc = add_mat(&mat2, z)) == OK)
                        {
                            // прочитали количество перемножений А и В соответственно
                            if ((rc = read_counts_mult(stdin, &p, &y)) == OK)
                            {
                                // выделили память под итоговую матрицу и проверили выделение
                                if ((rc = create_mat(&res, z, z)) == OK)
                                {
                                    // перемножили матрицы сколько раз надо
                                    if ((rc = mult_mat(&res, &mat1, &mat2, p, y)) == OK)
                                    {
                                        // вывели итоговую матрицу
                                        print_mat(stdout, &res);
                                    }
                                    // освободили память из-под итоговой матрицы
                                    free_mat(&res);
                                }
                            }
                        }
                    }
                }
            }
            // освободили память из-под матрицы В
            free_mat(&mat2);
        }
        // освободили память из-под матрицы А
        free_mat(&mat1);
    }
    // вернули код ошибки
    return rc;
}
