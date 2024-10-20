#include "del_mat.h"
#include "const_struct.h"
#include "create_mat.h"
#include "free_mat.h"
#include <check.h>
#include <stdlib.h>

// удаляет строки/столбцы с минимальным первым элементом при обходе по столбцам пока матрица не квадратная
// int del_mat(struct matrix *mat1)

// tests

// удаление столбцов

START_TEST(test_del_mat_min_first_col)
{
    int mat_start[][4] = {{1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {9, 10, 11, 12}}; // надо удалить 1 первый столбец
    int mat_final[][3] = {{2, 3, 4},
                        {6, 7, 8},
                        {10, 11, 12}};
    struct matrix mat;
    int n1 = 3;
    int m1 = 4;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // удаляет строки/столбцы с минимальным первым элементом при обходе по столбцам пока матрица не квадратная
    ck_assert_int_eq(del_mat(&mat), OK);
    ck_assert_int_eq(mat.n, 3);
    ck_assert_int_eq(mat.m, 3);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_del_mat_min_last_col)
{
    int mat_start[][4] = {{4, 2, 3, 8},
                        {5, 6, 7, 12},
                        {9, 10, 11, 1}}; // надо удалить 1 последний столбец
    int mat_final[][3] = {{4, 2, 3},
                           {5, 6, 7},
                           {9, 10, 11}};
    struct matrix mat;
    int n1 = 3;
    int m1 = 4;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // удаляет строки/столбцы с минимальным первым элементом при обходе по столбцам пока матрица не квадратная
    ck_assert_int_eq(del_mat(&mat), OK);
    ck_assert_int_eq(mat.n, 3);
    ck_assert_int_eq(mat.m, 3);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_del_mat_min_middle_col)
{
    int mat_start[][4] = {{6, 2, 3, 4},
                        {5, 1, 7, 8},
                        {9, 10, 11, 12}}; // надо удалить 1 столбец из середины
    int mat_final[][3] = {{6, 3, 4},
                        {5, 7, 8},
                        {9, 11, 12}};
    struct matrix mat;
    int n1 = 3;
    int m1 = 4;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // удаляет строки/столбцы с минимальным первым элементом при обходе по столбцам пока матрица не квадратная
    ck_assert_int_eq(del_mat(&mat), OK);
    ck_assert_int_eq(mat.n, 3);
    ck_assert_int_eq(mat.m, 3);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_del_mat_min_first2_col)
{
    int mat_start[][5] = {{1, 2, 3, 4, 16},
                        {5, 6, 7, 8, 17},
                        {9, 10, 11, 12, 18}}; // надо удалить 2 первых столбца
    int mat_final[][3] = {{3, 4, 16},
                           {7, 8, 17},
                           {11, 12, 18}};
    struct matrix mat;
    int n1 = 3;
    int m1 = 5;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // удаляет строки/столбцы с минимальным первым элементом при обходе по столбцам пока матрица не квадратная
    ck_assert_int_eq(del_mat(&mat), OK);
    ck_assert_int_eq(mat.n, 3);
    ck_assert_int_eq(mat.m, 3);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_del_mat_min_last2_col)
{
    int mat_start[][5] = {{4, 12, 3, 8, 1},
                        {5, 6, 7, 12, 15},
                        {9, 10, 11, 2, 18}}; // надо удалить 2 последних столбца
    int mat_final[][3] = {{4, 12, 3},
                           {5, 6, 7},
                           {9, 10, 11}};
    struct matrix mat;
    int n1 = 3;
    int m1 = 5;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // удаляет строки/столбцы с минимальным первым элементом при обходе по столбцам пока матрица не квадратная
    ck_assert_int_eq(del_mat(&mat), OK);
    ck_assert_int_eq(mat.n, 3);
    ck_assert_int_eq(mat.m, 3);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_del_mat_min_middle2_col)
{
    int mat_start[][5] = {{6, 2, 3, 5, 4},
                        {5, 1, 7, 0, 8},
                        {9, 10, 11, 56, 12}}; // надо удалить 2 столбеца из середины
    int mat_final[][3] = {{6, 3, 4},
                        {5, 7, 8},
                        {9, 11, 12}};
    struct matrix mat;
    int n1 = 3;
    int m1 = 5;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // удаляет строки/столбцы с минимальным первым элементом при обходе по столбцам пока матрица не квадратная
    ck_assert_int_eq(del_mat(&mat), OK);
    ck_assert_int_eq(mat.n, 3);
    ck_assert_int_eq(mat.m, 3);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_del_mat_min_first_last_col)
{
    int mat_start[][5] = {{1, 12, 3, 8, 2},
                        {5, 6, 7, 12, 15},
                        {9, 10, 11, 4, 18}}; // надо удалить 2 столбца с разных сторон (первый потом последний)
    int mat_final[][3] = {{12, 3, 8},
                           {6, 7, 12},
                           {10, 11, 4}};
    struct matrix mat;
    int n1 = 3;
    int m1 = 5;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // удаляет строки/столбцы с минимальным первым элементом при обходе по столбцам пока матрица не квадратная
    ck_assert_int_eq(del_mat(&mat), OK);
    ck_assert_int_eq(mat.n, 3);
    ck_assert_int_eq(mat.m, 3);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_del_mat_min_last_first_col)
{
    int mat_start[][5] = {{2, 12, 3, 8, 18},
                        {5, 6, 7, 12, 15},
                        {9, 10, 11, 4, -1}}; // надо удалить 2 столбца с разных сторон (последний потом первый)
    int mat_final[][3] = {{12, 3, 8},
                           {6, 7, 12},
                           {10, 11, 4}};
    struct matrix mat;
    int n1 = 3;
    int m1 = 5;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // удаляет строки/столбцы с минимальным первым элементом при обходе по столбцам пока матрица не квадратная
    ck_assert_int_eq(del_mat(&mat), OK);
    ck_assert_int_eq(mat.n, 3);
    ck_assert_int_eq(mat.m, 3);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_del_mat_min_many_col)
{
    int mat_start[][5] = {{2, 12, 2, 8},
                        {5, 6, 2, 12},
                        {9, 10, 11, 2}}; // несколько минимальных
    int mat_final[][3] = {{12, 2, 8},
                           {6, 2, 12},
                           {10, 11, 2}};
    struct matrix mat;
    int n1 = 3;
    int m1 = 4;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // удаляет строки/столбцы с минимальным первым элементом при обходе по столбцам пока матрица не квадратная
    ck_assert_int_eq(del_mat(&mat), OK);
    ck_assert_int_eq(mat.n, 3);
    ck_assert_int_eq(mat.m, 3);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_del_mat_stay_one_col)
{
    int mat_start[][4] = {{3, 12, -1, 2}}; // в итоге останется 1 элемент
    int mat_final[][1] = {{12}};
    struct matrix mat;
    int n1 = 1;
    int m1 = 4;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // удаляет строки/столбцы с минимальным первым элементом при обходе по столбцам пока матрица не квадратная
    ck_assert_int_eq(del_mat(&mat), OK);
    ck_assert_int_eq(mat.n, 1);
    ck_assert_int_eq(mat.m, 1);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_del_mat_min_similar_col_col)
{
    int mat_start[][5] = {{1, 3, 4, 2, 16},
                        {1, 3, 4, 2, 16},
                        {1, 3, 4, 2, 16}}; // одинаковые строки
    int mat_final[][3] = {{3, 4, 16},
                           {3, 4, 16},
                           {3, 4, 16}};
    struct matrix mat;
    int n1 = 3;
    int m1 = 5;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // удаляет строки/столбцы с минимальным первым элементом при обходе по столбцам пока матрица не квадратная
    ck_assert_int_eq(del_mat(&mat), OK);
    ck_assert_int_eq(mat.n, 3);
    ck_assert_int_eq(mat.m, 3);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_del_mat_min_similar_elems_col)
{
    int mat_start[][5] = {{1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1}}; // одиинаковые элементы (все)
    int mat_final[][3] = {{1, 1, 1},
                           {1, 1, 1},
                           {1, 1, 1}};
    struct matrix mat;
    int n1 = 3;
    int m1 = 5;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // удаляет строки/столбцы с минимальным первым элементом при обходе по столбцам пока матрица не квадратная
    ck_assert_int_eq(del_mat(&mat), OK);
    ck_assert_int_eq(mat.n, 3);
    ck_assert_int_eq(mat.m, 3);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

// удаление строк

START_TEST(test_del_mat_min_first_str)
{
    int mat_start[][3] = {{1, 2, 3},
                        {5, 6, 7},
                        {9, 10, 11},
                        {92, 14, 131}}; // надо удалить 1 первую строку
    int mat_final[][3] = {{5, 6, 7},
                           {9, 10, 11},
                           {92, 14, 131}};
    struct matrix mat;
    int n1 = 4;
    int m1 = 3;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // удаляет строки/столбцы с минимальным первым элементом при обходе по столбцам пока матрица не квадратная
    ck_assert_int_eq(del_mat(&mat), OK);
    ck_assert_int_eq(mat.n, 3);
    ck_assert_int_eq(mat.m, 3);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_del_mat_min_last_str)
{
    int mat_start[][3] = {{4, 2, 3},
                        {5, 6, 7},
                        {9, 10, 11},
                        {923, 1, 31}}; // надо удалить 1 последнюю строку
    int mat_final[][3] = {{4, 2, 3},
                           {5, 6, 7},
                           {9, 10, 11}};
    struct matrix mat;
    int n1 = 4;
    int m1 = 3;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // удаляет строки/столбцы с минимальным первым элементом при обходе по столбцам пока матрица не квадратная
    ck_assert_int_eq(del_mat(&mat), OK);
    ck_assert_int_eq(mat.n, 3);
    ck_assert_int_eq(mat.m, 3);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_del_mat_min_middle_str)
{
    int mat_start[][3] = {{6, 3, 4},
                           {5, 7, 8},
                           {4, 1, -2},
                           {9, 11, 12}}; // надо удалить 1 строку из середины
    int mat_final[][3] = {{6, 3, 4},
                        {5, 7, 8},
                        {9, 11, 12}};
    struct matrix mat;
    int n1 = 4;
    int m1 = 3;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // удаляет строки/столбцы с минимальным первым элементом при обходе по столбцам пока матрица не квадратная
    ck_assert_int_eq(del_mat(&mat), OK);
    ck_assert_int_eq(mat.n, 3);
    ck_assert_int_eq(mat.m, 3);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_del_mat_min_first2_str)
{
    int mat_start[][3] = {{6, 3, 1},
                           {5, 0, 8},
                           {4, 14, 23},
                           {5, 7, 8},
                           {9, 11, 12}}; // надо удалить 2 первых строки
    int mat_final[][3] = {{4, 14, 23},
                           {5, 7, 8},
                           {9, 11, 12}};
    struct matrix mat;
    int n1 = 5;
    int m1 = 3;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // удаляет строки/столбцы с минимальным первым элементом при обходе по столбцам пока матрица не квадратная
    ck_assert_int_eq(del_mat(&mat), OK);
    ck_assert_int_eq(mat.n, 3);
    ck_assert_int_eq(mat.m, 3);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_del_mat_min_last2_str)
{
    int mat_start[][3] = {{4, 2, 3},
                           {5, 6, 7},
                           {9, 10, 11},
                           {35, -6, 79},
                           {54, 600, 1}}; // надо удалить 2 последних строки
    int mat_final[][3] = {{4, 2, 3},
                           {5, 6, 7},
                           {9, 10, 11}};
    struct matrix mat;
    int n1 = 5;
    int m1 = 3;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // удаляет строки/столбцы с минимальным первым элементом при обходе по столбцам пока матрица не квадратная
    ck_assert_int_eq(del_mat(&mat), OK);
    ck_assert_int_eq(mat.n, 3);
    ck_assert_int_eq(mat.m, 3);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_del_mat_min_middle2_str)
{
    int mat_start[][3] = {{6, 3, 4},
                           {5, 0, 8},
                           {53, -7, 18},
                           {-95, -4, 8},
                           {9, 11, 12}}; // надо удалить 2 строки из середины
    int mat_final[][3] = {{6, 3, 4},
                        {5, 0, 8},
                        {9, 11, 12}};
    struct matrix mat;
    int n1 = 5;
    int m1 = 3;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // удаляет строки/столбцы с минимальным первым элементом при обходе по столбцам пока матрица не квадратная
    ck_assert_int_eq(del_mat(&mat), OK);
    ck_assert_int_eq(mat.n, 3);
    ck_assert_int_eq(mat.m, 3);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_del_mat_min_first_last_str)
{
    int mat_start[][3] = {{132, -3, 16},
                           {12, 3, 8},
                           {6, 7, 12},
                           {10, 11, 4},
                           {1, 131, 45}}; // надо удалить 2 строки с разных сторон (первую потом последнюю)
    int mat_final[][3] = {{12, 3, 8},
                           {6, 7, 12},
                           {10, 11, 4}};
    struct matrix mat;
    int n1 = 5;
    int m1 = 3;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // удаляет строки/столбцы с минимальным первым элементом при обходе по столбцам пока матрица не квадратная
    ck_assert_int_eq(del_mat(&mat), OK);
    ck_assert_int_eq(mat.n, 3);
    ck_assert_int_eq(mat.m, 3);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_del_mat_min_last_first_str)
{
    int mat_start[][3] = {{132, -3, 16},
                           {12, 3, 8},
                           {6, 7, 12},
                           {10, 11, 4},
                           {-5, 131, 45}};  // надо удалить 2 строки с разных сторон (последний потом первый)
    int mat_final[][3] = {{12, 3, 8},
                           {6, 7, 12},
                           {10, 11, 4}};
    struct matrix mat;
    int n1 = 5;
    int m1 = 3;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // удаляет строки/столбцы с минимальным первым элементом при обходе по столбцам пока матрица не квадратная
    ck_assert_int_eq(del_mat(&mat), OK);
    ck_assert_int_eq(mat.n, 3);
    ck_assert_int_eq(mat.m, 3);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_del_mat_min_many_str)
{
    int mat_start[][3] = {{132, 4, 279},
                           {12, 2, 8},
                           {6, 2, 12},
                           {10, 11, 2}}; // несколько минимальных
    int mat_final[][3] = {{132, 4, 279},
                           {6, 2, 12},
                           {10, 11, 2}};
    struct matrix mat;
    int n1 = 4;
    int m1 = 3;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // удаляет строки/столбцы с минимальным первым элементом при обходе по столбцам пока матрица не квадратная
    ck_assert_int_eq(del_mat(&mat), OK);
    ck_assert_int_eq(mat.n, 3);
    ck_assert_int_eq(mat.m, 3);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_del_mat_stay_one_str)
{
    int mat_start[][1] = {{3},
                           {12},
                           {-1},
                           {2}}; // в итоге останется 1 элемент
    int mat_final[][1] = {{12}};
    struct matrix mat;
    int n1 = 4;
    int m1 = 1;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // удаляет строки/столбцы с минимальным первым элементом при обходе по столбцам пока матрица не квадратная
    ck_assert_int_eq(del_mat(&mat), OK);
    ck_assert_int_eq(mat.n, 1);
    ck_assert_int_eq(mat.m, 1);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_del_mat_min_similar_str_str)
{
    int mat_start[][3] = {{1, 1, 1},
                           {-2, -2, -2},
                           {-1, -1, -1},
                           {3, 3, 3}}; // одинаковые столбцы
    int mat_final[][3] = {{1, 1, 1},
                           {-1, -1, -1},
                           {3, 3, 3}};
    struct matrix mat;
    int n1 = 4;
    int m1 = 3;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // удаляет строки/столбцы с минимальным первым элементом при обходе по столбцам пока матрица не квадратная
    ck_assert_int_eq(del_mat(&mat), OK);
    ck_assert_int_eq(mat.n, 3);
    ck_assert_int_eq(mat.m, 3);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_del_mat_min_similar_elems_str)
{
    int mat_start[][3] = {{1, 1, 1},
                           {1, 1, 1},
                           {1, 1, 1},
                           {1, 1, 1},
                           {1, 1, 1}}; // одиинаковые элементы (все)
    int mat_final[][3] = {{1, 1, 1},
                           {1, 1, 1},
                           {1, 1, 1}};
    struct matrix mat;
    int n1 = 5;
    int m1 = 3;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // удаляет строки/столбцы с минимальным первым элементом при обходе по столбцам пока матрица не квадратная
    ck_assert_int_eq(del_mat(&mat), OK);
    ck_assert_int_eq(mat.n, 3);
    ck_assert_int_eq(mat.m, 3);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

// ничего не удаляем

START_TEST(test_del_mat_do_nothing)
{
    int mat_start[][3] = {{12, 2, 8},
                           {6, 2, 12},
                           {10, 11, 2}}; // матрица уже квадратная (такая и должна остаться)
       int mat_final[][3] = {{12, 2, 8},
                              {6, 2, 12},
                              {10, 11, 2}};
    struct matrix mat;
    int n1 = 3;
    int m1 = 3;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // удаляет строки/столбцы с минимальным первым элементом при обходе по столбцам пока матрица не квадратная
    ck_assert_int_eq(del_mat(&mat), OK);
    ck_assert_int_eq(mat.n, 3);
    ck_assert_int_eq(mat.m, 3);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST


// Функции-тесты группируются в тестовые случаи (test case, TCase), а несколько
// тестовых случаев образуют тестовый набор (test suite, Suite).
Suite* del_mat_suite(void)
{
    Suite *s;
    TCase *tc_all;

    // Создадим тестовый набор для тестирования функции del_mat
    s = suite_create("del_mat");

    // Создадим тестовый случай из функций-тестов, которые проверяют работу
    // del_mat для корректных параметров
    tc_all = tcase_create("all_tests");
    // Добавим в tc_all соответствующие функции-тесты
    tcase_add_test(tc_all, test_del_mat_min_first_col);
    tcase_add_test(tc_all, test_del_mat_min_last_col);
    tcase_add_test(tc_all, test_del_mat_min_middle_col);
    tcase_add_test(tc_all, test_del_mat_min_first2_col);
    tcase_add_test(tc_all, test_del_mat_min_last2_col);
    tcase_add_test(tc_all, test_del_mat_min_middle2_col);
    tcase_add_test(tc_all, test_del_mat_min_first_last_col);
    tcase_add_test(tc_all, test_del_mat_min_last_first_col);
    tcase_add_test(tc_all, test_del_mat_min_many_col);
    tcase_add_test(tc_all, test_del_mat_stay_one_col);
    tcase_add_test(tc_all, test_del_mat_min_similar_col_col);
    tcase_add_test(tc_all, test_del_mat_min_similar_elems_col);

    tcase_add_test(tc_all, test_del_mat_min_first_str);
    tcase_add_test(tc_all, test_del_mat_min_last_str);
    tcase_add_test(tc_all, test_del_mat_min_middle_str);
    tcase_add_test(tc_all, test_del_mat_min_first2_str);
    tcase_add_test(tc_all, test_del_mat_min_last2_str);
    tcase_add_test(tc_all, test_del_mat_min_middle2_str);
    tcase_add_test(tc_all, test_del_mat_min_first_last_str);
    tcase_add_test(tc_all, test_del_mat_min_last_first_str);
    tcase_add_test(tc_all, test_del_mat_min_many_str);
    tcase_add_test(tc_all, test_del_mat_stay_one_str);
    tcase_add_test(tc_all, test_del_mat_min_similar_str_str);
    tcase_add_test(tc_all, test_del_mat_min_similar_elems_str);

    tcase_add_test(tc_all, test_del_mat_do_nothing);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_all);

    return s;
}
