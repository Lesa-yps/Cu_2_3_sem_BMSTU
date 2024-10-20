#include "add_mat.h"
#include "const_struct.h"
#include "create_mat.h"
#include "free_mat.h"
#include <check.h>

// добавляем строки/столбцы до размерности z по определённым правилам (сначала строки потом столбцы)
// (новые столбцы из максимумов по строкам, новые строки из средних геометрических по столбцам)
// int add_mat(struct matrix *mat1, int z)

// pos tests

START_TEST(test_add_mat_1col)
{
    int rc;
    int mat_start[][3] = {{2, 3, 4},
                           {6, -7, 8},
                           {61, 17, -2},
                           {12, 11, 10}}; // надо добавить 1 столбец
    int mat_final[][4] = {{2, 3, 4, 4},
                           {6, -7, 8, 8},
                           {61, 17, -2, 61},
                           {12, 11, 10, 12}};
    struct matrix mat;
    int n1 = 4;
    int m1 = 3;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // добавляем строки/столбцы до размерности z по определённым правилам (сначала строки потом столбцы)
    // (новые столбцы из максимумов по строкам, новые строки из средних геометрических по столбцам)
    rc = add_mat(&mat, 4);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(mat.n, 4);
    ck_assert_int_eq(mat.m, 4);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_add_mat_2col)
{
    int rc;
    int mat_start[][3] = {{2, 3, 4},
                           {6, -7, 8},
                           {61, 17, -2},
                           {-61, -17, 2},
                           {12, 11, 10}}; // надо добавить 2 столбеца
    int mat_final[][5] = {{2, 3, 4, 4, 4},
                           {6, -7, 8, 8, 8},
                           {61, 17, -2, 61, 61},
                           {-61, -17, 2, 2, 2},
                           {12, 11, 10, 12, 12}};
    struct matrix mat;
    int n1 = 5;
    int m1 = 3;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // добавляем строки/столбцы до размерности z по определённым правилам (сначала строки потом столбцы)
    // (новые столбцы из максимумов по строкам, новые строки из средних геометрических по столбцам)
    rc = add_mat(&mat, 5);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(mat.n, 5);
    ck_assert_int_eq(mat.m, 5);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_add_mat_1str)
{
    int rc;
    int mat_start[][3] = {{2, 3, 4},
                           {6, -7, 8}}; // надо добавить 1 строку
    int mat_final[][3] = {{2, 3, 4},
                           {6, -7, 8},
                           {3, 4, 5}};
    struct matrix mat;
    int n1 = 2;
    int m1 = 3;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // добавляем строки/столбцы до размерности z по определённым правилам (сначала строки потом столбцы)
    // (новые столбцы из максимумов по строкам, новые строки из средних геометрических по столбцам)
    rc = add_mat(&mat, 3);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(mat.n, 3);
    ck_assert_int_eq(mat.m, 3);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_add_mat_2str)
{
    int rc;
    int mat_start[][4] = {{2, 3, 4, 1},
                           {6, -7, 8, -2}}; // надо добавить 2 строки
    int mat_final[][4] = {{2, 3, 4, 1},
                           {6, -7, 8, -2},
                           {3, 4, 5, 1},
                           {3, 4, 5, 1}};
    struct matrix mat;
    int n1 = 2;
    int m1 = 4;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // добавляем строки/столбцы до размерности z по определённым правилам (сначала строки потом столбцы)
    // (новые столбцы из максимумов по строкам, новые строки из средних геометрических по столбцам)
    rc = add_mat(&mat, 4);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(mat.n, 4);
    ck_assert_int_eq(mat.m, 4);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_add_mat_1str_1col)
{
    int rc;
    int mat_start[][2] = {{2, 3},
                           {6, -7}}; // надо добавить 1 строку и 1 столбец
    int mat_final[][3] = {{2, 3, 3},
                           {6, -7, 6},
                           {3, 4, 4}};
    struct matrix mat;
    int n1 = 2;
    int m1 = 2;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // добавляем строки/столбцы до размерности z по определённым правилам (сначала строки потом столбцы)
    // (новые столбцы из максимумов по строкам, новые строки из средних геометрических по столбцам)
    rc = add_mat(&mat, 3);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(mat.n, 3);
    ck_assert_int_eq(mat.m, 3);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_add_mat_2str_2col)
{
    int rc;
    int mat_start[][2] = {{2, 3},
                           {6, -7}}; // надо добавить 2 строки и 2 столбца
    int mat_final[][4] = {{2, 3, 3, 3},
                           {6, -7, 6, 6},
                           {3, 4, 4, 4},
                           {3, 4, 4, 4}};
    struct matrix mat;
    int n1 = 2;
    int m1 = 2;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // добавляем строки/столбцы до размерности z по определённым правилам (сначала строки потом столбцы)
    // (новые столбцы из максимумов по строкам, новые строки из средних геометрических по столбцам)
    rc = add_mat(&mat, 4);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(mat.n, 4);
    ck_assert_int_eq(mat.m, 4);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_add_mat_1col_start)
{
    int rc;
    int mat_start[][1] = {{2},
                           {6}}; // надо добавить 1 столбец
    int mat_final[][2] = {{2, 2},
                           {6, 6}};
    struct matrix mat;
    int n1 = 2;
    int m1 = 1;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // добавляем строки/столбцы до размерности z по определённым правилам (сначала строки потом столбцы)
    // (новые столбцы из максимумов по строкам, новые строки из средних геометрических по столбцам)
    rc = add_mat(&mat, 2);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(mat.n, 2);
    ck_assert_int_eq(mat.m, 2);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_add_mat_1str_start)
{
    int rc;
    int mat_start[][2] = {{2, 3}}; // надо добавить 1 строку
    int mat_final[][2] = {{2, 3},
                           {2, 3}};
    struct matrix mat;
    int n1 = 1;
    int m1 = 2;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // добавляем строки/столбцы до размерности z по определённым правилам (сначала строки потом столбцы)
    // (новые столбцы из максимумов по строкам, новые строки из средних геометрических по столбцам)
    rc = add_mat(&mat, 2);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(mat.n, 2);
    ck_assert_int_eq(mat.m, 2);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_add_mat_1elem_start)
{
    int rc;
    int mat_start[][1] = {{2}}; // надо добавить 1 строку и 1 столбец (вначале 1 строка)
    int mat_final[][2] = {{2, 2},
                           {2, 2}};
    struct matrix mat;
    int n1 = 1;
    int m1 = 1;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // добавляем строки/столбцы до размерности z по определённым правилам (сначала строки потом столбцы)
    // (новые столбцы из максимумов по строкам, новые строки из средних геометрических по столбцам)
    rc = add_mat(&mat, 2);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(mat.n, 2);
    ck_assert_int_eq(mat.m, 2);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

START_TEST(test_add_mat_do_nothing)
{
    int rc;
    int mat_start[][2] = {{2, 3},
                           {6, -7}}; // ничего не надо делать
    int mat_final[][2] = {{2, 3},
                           {6, -7}};
    struct matrix mat;
    int n1 = 2;
    int m1 = 2;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = mat_start[i][j];
    // добавляем строки/столбцы до размерности z по определённым правилам (сначала строки потом столбцы)
    // (новые столбцы из максимумов по строкам, новые строки из средних геометрических по столбцам)
    rc = add_mat(&mat, 2);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(mat.n, 2);
    ck_assert_int_eq(mat.m, 2);
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_final[i][j]);
    free_mat(&mat);
}
END_TEST

// Функции-тесты группируются в тестовые случаи (test case, TCase), а несколько
// тестовых случаев образуют тестовый набор (test suite, Suite).
Suite* add_mat_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    // Создадим тестовый набор для тестирования функции key
    s = suite_create("add_mat");

    // Создадим тестовый случай из функций-тестов, которые проверяют разного
    // рода ошибочные ситуации при вызове key
    tc_pos = tcase_create("positives");

    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_pos, test_add_mat_1col);
    tcase_add_test(tc_pos, test_add_mat_2col);
    tcase_add_test(tc_pos, test_add_mat_1str);
    tcase_add_test(tc_pos, test_add_mat_2str);
    tcase_add_test(tc_pos, test_add_mat_1str_1col);
    tcase_add_test(tc_pos, test_add_mat_2str_2col);
    tcase_add_test(tc_pos, test_add_mat_1col_start);
    tcase_add_test(tc_pos, test_add_mat_1str_start);
    tcase_add_test(tc_pos, test_add_mat_1elem_start);
    tcase_add_test(tc_pos, test_add_mat_do_nothing);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);

    return s;
}
