#include "free_mat.h"

// освобождает память из-под матрицы
void free_mat(struct matrix *mat1)
{
    free(mat1->arr[0]);
    free(mat1->arr);
}
