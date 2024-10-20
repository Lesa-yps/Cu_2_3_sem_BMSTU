#ifndef CONST_STRUCT_H
#define CONST_STRUCT_H

// код успешного завершения
#define OK 0
// код ошибки
#define ERROR 1

// структура - матрица
struct matrix
{
    // сам массив массивов массивов
    int ***arr;
    // кол-во строк
    int n;
    // кол-во столбцов
    int m;
    //
    int k;
};

// структура - матрица
struct matrix_2D
{
    // сам массив массивов
    int **arr;
    // кол-во строк
    int n;
    // кол-во столбцов
    int m;
};

#endif // CONST_STRUCT_H
