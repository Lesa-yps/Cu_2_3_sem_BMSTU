#include "mult_mat.h"
#include "const_struct.h"
#include <check.h>
#include <stdlib.h>

// перемножает матрицы нужное количество раз на себя и друг с другом
// int mult_mat(struct matrix *res, struct matrix *mat1, struct matrix *mat2, int p, int y)

#define SIZE_MAT 3

int init_struct(struct matrix *mat1, int mat_start1[][SIZE_MAT], int n1, int m1)
{
    if (create_mat(mat1, n1, m1) == ERROR)
        return ERROR;
    mat1->n = n1;
    mat1->m = m1;
    for (int i = 0; i < mat1->n; i++)
        for (int j = 0; j < mat1->m; j++)
            mat1->arr[i][j] = mat_start1[i][j];
    return OK;
}

// tests

START_TEST(test_mult_mat_p1_y1)
{
    int p = 1;
    int y = 1;
    int mat_start1[][SIZE_MAT] = {{1, 2, 3},
                                   {0, -1, 2},
                                   {3, 1, -3}};
    int mat_start2[][SIZE_MAT] = {{-2, 0, -1},
                                   {1, 3, -2},
                                   {-3, 1, 1}}; // надо перемножить 2 марицы в первых степенях
    int mat_final[][SIZE_MAT] = {{-9, 9, -2},
                                  {-7, -1, 4},
                                  {4, 0, -8}};
    struct matrix mat1;
    struct matrix mat2;
    struct matrix mat_res;
    ck_assert_int_eq(init_struct(&mat1, mat_start1, SIZE_MAT, SIZE_MAT), OK);
    ck_assert_int_eq(init_struct(&mat2, mat_start2, SIZE_MAT, SIZE_MAT), OK);
    ck_assert_int_eq(create_mat(&mat_res, SIZE_MAT, SIZE_MAT), OK);
    // перемножает матрицы нужное количество раз на себя и друг с другом
    ck_assert_int_eq(mult_mat(&mat_res, &mat1, &mat2, p, y), OK);
    ck_assert_int_eq(mat_res.n, SIZE_MAT);
    ck_assert_int_eq(mat_res.m, SIZE_MAT);
    for (int i = 0; i < mat_res.n; i++)
        for (int j = 0; j < mat_res.m; j++)
            ck_assert_int_eq(mat_res.arr[i][j], mat_final[i][j]);
    free_mat(&mat1);
    free_mat(&mat2);
    free_mat(&mat_res);
}
END_TEST

START_TEST(test_mult_mat_p2_y2)
{
    int p = 2;
    int y = 2;
    int mat_start1[][SIZE_MAT] = {{1, 2, 3},
                                   {0, -1, 2},
                                   {3, 1, -3}};
    int mat_start2[][SIZE_MAT] = {{-2, 0, -1},
                                   {1, 3, -2},
                                   {-3, 1, 1}}; // надо перемножить 2 марицы во вторых степенях
    int mat_final[][SIZE_MAT] = {{83, 3, -21},
                                  {31, -17, -37},
                                  {52, 100, 16}};
    struct matrix mat1;
    struct matrix mat2;
    struct matrix mat_res;
    ck_assert_int_eq(init_struct(&mat1, mat_start1, SIZE_MAT, SIZE_MAT), OK);
    ck_assert_int_eq(init_struct(&mat2, mat_start2, SIZE_MAT, SIZE_MAT), OK);
    ck_assert_int_eq(create_mat(&mat_res, SIZE_MAT, SIZE_MAT), OK);
    // перемножает матрицы нужное количество раз на себя и друг с другом
    ck_assert_int_eq(mult_mat(&mat_res, &mat1, &mat2, p, y), OK);
    ck_assert_int_eq(mat_res.n, SIZE_MAT);
    ck_assert_int_eq(mat_res.m, SIZE_MAT);
    for (int i = 0; i < mat_res.n; i++)
        for (int j = 0; j < mat_res.m; j++)
            ck_assert_int_eq(mat_res.arr[i][j], mat_final[i][j]);
    free_mat(&mat1);
    free_mat(&mat2);
    free_mat(&mat_res);
}
END_TEST

START_TEST(test_mult_mat_p2_y1)
{
    int p = 2;
    int y = 1;
    int mat_start1[][SIZE_MAT] = {{1, 2, 3},
                                   {0, -1, 2},
                                   {3, 1, -3}};
    int mat_start2[][SIZE_MAT] = {{-2, 0, -1},
                                   {1, 3, -2},
                                   {-3, 1, 1}}; // надо перемножить 2 марицы первую во второй вторую в первой степенях
    int mat_final[][SIZE_MAT] = {{-11, 7, -18},
                                  {15, 1, -20},
                                  {-46, 26, 22}};
    struct matrix mat1;
    struct matrix mat2;
    struct matrix mat_res;
    ck_assert_int_eq(init_struct(&mat1, mat_start1, SIZE_MAT, SIZE_MAT), OK);
    ck_assert_int_eq(init_struct(&mat2, mat_start2, SIZE_MAT, SIZE_MAT), OK);
    ck_assert_int_eq(create_mat(&mat_res, SIZE_MAT, SIZE_MAT), OK);
    // перемножает матрицы нужное количество раз на себя и друг с другом
    ck_assert_int_eq(mult_mat(&mat_res, &mat1, &mat2, p, y), OK);
    ck_assert_int_eq(mat_res.n, SIZE_MAT);
    ck_assert_int_eq(mat_res.m, SIZE_MAT);
    for (int i = 0; i < mat_res.n; i++)
        for (int j = 0; j < mat_res.m; j++)
            ck_assert_int_eq(mat_res.arr[i][j], mat_final[i][j]);
    free_mat(&mat1);
    free_mat(&mat2);
    free_mat(&mat_res);
}
END_TEST

START_TEST(test_mult_mat_p1_y2)
{
    int p = 1;
    int y = 2;
    int mat_start1[][SIZE_MAT] = {{1, 2, 3},
                                   {0, -1, 2},
                                   {3, 1, -3}};
    int mat_start2[][SIZE_MAT] = {{-2, 0, -1},
                                   {1, 3, -2},
                                   {-3, 1, 1}}; // надо перемножить 2 марицы первую в первой вторую во второй степенях
    int mat_final[][SIZE_MAT] = {{33, 25, -11},
                                  {1, 1, 13},
                                  {16, -8, -12}};
    struct matrix mat1;
    struct matrix mat2;
    struct matrix mat_res;
    ck_assert_int_eq(init_struct(&mat1, mat_start1, SIZE_MAT, SIZE_MAT), OK);
    ck_assert_int_eq(init_struct(&mat2, mat_start2, SIZE_MAT, SIZE_MAT), OK);
    ck_assert_int_eq(create_mat(&mat_res, SIZE_MAT, SIZE_MAT), OK);
    // перемножает матрицы нужное количество раз на себя и друг с другом
    ck_assert_int_eq(mult_mat(&mat_res, &mat1, &mat2, p, y), OK);
    ck_assert_int_eq(mat_res.n, SIZE_MAT);
    ck_assert_int_eq(mat_res.m, SIZE_MAT);
    for (int i = 0; i < mat_res.n; i++)
        for (int j = 0; j < mat_res.m; j++)
            ck_assert_int_eq(mat_res.arr[i][j], mat_final[i][j]);
    free_mat(&mat1);
    free_mat(&mat2);
    free_mat(&mat_res);
}
END_TEST

START_TEST(test_mult_mat_p3_y3)
{
    int p = 3;
    int y = 3;
    int mat_start1[][SIZE_MAT] = {{1, 2, 3},
                                   {0, -1, 2},
                                   {3, 1, -3}};
    int mat_start2[][SIZE_MAT] = {{-2, 0, -1},
                                   {1, 3, -2},
                                   {-3, 1, 1}}; // надо перемножить 2 марицы в третьих степенях
    int mat_final[][SIZE_MAT] = {{-192, 760, -886},
                                  {-136, 720, -438},
                                  {-112, -1072, 344}};
    struct matrix mat1;
    struct matrix mat2;
    struct matrix mat_res;
    ck_assert_int_eq(init_struct(&mat1, mat_start1, SIZE_MAT, SIZE_MAT), OK);
    ck_assert_int_eq(init_struct(&mat2, mat_start2, SIZE_MAT, SIZE_MAT), OK);
    ck_assert_int_eq(create_mat(&mat_res, SIZE_MAT, SIZE_MAT), OK);
    // перемножает матрицы нужное количество раз на себя и друг с другом
    ck_assert_int_eq(mult_mat(&mat_res, &mat1, &mat2, p, y), OK);
    ck_assert_int_eq(mat_res.n, SIZE_MAT);
    ck_assert_int_eq(mat_res.m, SIZE_MAT);
    for (int i = 0; i < mat_res.n; i++)
        for (int j = 0; j < mat_res.m; j++)
            ck_assert_int_eq(mat_res.arr[i][j], mat_final[i][j]);
    free_mat(&mat1);
    free_mat(&mat2);
    free_mat(&mat_res);
}
END_TEST

START_TEST(test_mult_mat_p0_y0)
{
    int p = 0;
    int y = 0;
    int mat_start1[][SIZE_MAT] = {{1, 2, 3},
                                   {0, -1, 2},
                                   {3, 1, -3}};
    int mat_start2[][SIZE_MAT] = {{-2, 0, -1},
                                   {1, 3, -2},
                                   {-3, 1, 1}}; // надо перемножить 2 марицы в нулевых степенях
    int mat_final[][SIZE_MAT] = {{1, 0, 0},
                                  {0, 1, 0},
                                  {0, 0, 1}};
    struct matrix mat1;
    struct matrix mat2;
    struct matrix mat_res;
    ck_assert_int_eq(init_struct(&mat1, mat_start1, SIZE_MAT, SIZE_MAT), OK);
    ck_assert_int_eq(init_struct(&mat2, mat_start2, SIZE_MAT, SIZE_MAT), OK);
    ck_assert_int_eq(create_mat(&mat_res, SIZE_MAT, SIZE_MAT), OK);
    // перемножает матрицы нужное количество раз на себя и друг с другом
    ck_assert_int_eq(mult_mat(&mat_res, &mat1, &mat2, p, y), OK);
    ck_assert_int_eq(mat_res.n, SIZE_MAT);
    ck_assert_int_eq(mat_res.m, SIZE_MAT);
    for (int i = 0; i < mat_res.n; i++)
        for (int j = 0; j < mat_res.m; j++)
            ck_assert_int_eq(mat_res.arr[i][j], mat_final[i][j]);
    free_mat(&mat1);
    free_mat(&mat2);
    free_mat(&mat_res);
}
END_TEST

START_TEST(test_mult_mat_p0_y1)
{
    int p = 0;
    int y = 1;
    int mat_start1[][SIZE_MAT] = {{1, 2, 3},
                                   {0, -1, 2},
                                   {3, 1, -3}};
    int mat_start2[][SIZE_MAT] = {{-2, 0, -1},
                                   {1, 3, -2},
                                   {-3, 1, 1}}; // надо перемножить 2 марицы первая в нулевой вторая в первой степенях
    int mat_final[][SIZE_MAT] = {{-2, 0, -1},
                                  {1, 3, -2},
                                  {-3, 1, 1}};
    struct matrix mat1;
    struct matrix mat2;
    struct matrix mat_res;
    ck_assert_int_eq(init_struct(&mat1, mat_start1, SIZE_MAT, SIZE_MAT), OK);
    ck_assert_int_eq(init_struct(&mat2, mat_start2, SIZE_MAT, SIZE_MAT), OK);
    ck_assert_int_eq(create_mat(&mat_res, SIZE_MAT, SIZE_MAT), OK);
    // перемножает матрицы нужное количество раз на себя и друг с другом
    ck_assert_int_eq(mult_mat(&mat_res, &mat1, &mat2, p, y), OK);
    ck_assert_int_eq(mat_res.n, SIZE_MAT);
    ck_assert_int_eq(mat_res.m, SIZE_MAT);
    for (int i = 0; i < mat_res.n; i++)
        for (int j = 0; j < mat_res.m; j++)
            ck_assert_int_eq(mat_res.arr[i][j], mat_final[i][j]);
    free_mat(&mat1);
    free_mat(&mat2);
    free_mat(&mat_res);
}
END_TEST

START_TEST(test_mult_mat_p2_y0)
{
    int p = 2;
    int y = 0;
    int mat_start1[][SIZE_MAT] = {{1, 2, 3},
                                   {0, -1, 2},
                                   {3, 1, -3}};
    int mat_start2[][SIZE_MAT] = {{-2, 0, -1},
                                   {1, 3, -2},
                                   {-3, 1, 1}}; // надо перемножить 2 марицы первая во второй вторая в нулевой степенях
    int mat_final[][SIZE_MAT] = {{10, 3, -2},
                                  {6, 3, -8},
                                  {-6, 2, 20}};
    struct matrix mat1;
    struct matrix mat2;
    struct matrix mat_res;
    ck_assert_int_eq(init_struct(&mat1, mat_start1, SIZE_MAT, SIZE_MAT), OK);
    ck_assert_int_eq(init_struct(&mat2, mat_start2, SIZE_MAT, SIZE_MAT), OK);
    ck_assert_int_eq(create_mat(&mat_res, SIZE_MAT, SIZE_MAT), OK);
    // перемножает матрицы нужное количество раз на себя и друг с другом
    ck_assert_int_eq(mult_mat(&mat_res, &mat1, &mat2, p, y), OK);
    ck_assert_int_eq(mat_res.n, SIZE_MAT);
    ck_assert_int_eq(mat_res.m, SIZE_MAT);
    for (int i = 0; i < mat_res.n; i++)
        for (int j = 0; j < mat_res.m; j++)
            ck_assert_int_eq(mat_res.arr[i][j], mat_final[i][j]);
    free_mat(&mat1);
    free_mat(&mat2);
    free_mat(&mat_res);
}
END_TEST

START_TEST(test_mult_mat_1elem_p2_y2)
{
    int p = 2;
    int y = 2;
    int mat_start1[][1] = {{3}};
    int mat_start2[][1] = {{-2}}; // надо перемножить 2 марицы содержащие по одному элементу во вторых степенях
    int mat_final[][1] = {{36}};
    struct matrix mat1;
    struct matrix mat2;
    struct matrix mat_res;
    int n1 = 1, m1 = 1;
    ck_assert_int_eq(create_mat(&mat1, n1, m1), OK);
    mat1.n = n1;
    mat1.m = m1;
    mat1.arr[0][0] = mat_start1[0][0];
    int n2 = 1, m2 = 1;
    ck_assert_int_eq(create_mat(&mat2, n2, m2), OK);
    mat2.n = n2;
    mat2.m = m2;
    mat2.arr[0][0] = mat_start2[0][0];
    ck_assert_int_eq(create_mat(&mat_res, n1, m2), OK);
    // перемножает матрицы нужное количество раз на себя и друг с другом
    ck_assert_int_eq(mult_mat(&mat_res, &mat1, &mat2, p, y), OK);
    ck_assert_int_eq(mat_res.n, 1);
    ck_assert_int_eq(mat_res.m, 1);
    for (int i = 0; i < mat_res.n; i++)
        for (int j = 0; j < mat_res.m; j++)
            ck_assert_int_eq(mat_res.arr[i][j], mat_final[i][j]);
    free_mat(&mat1);
    free_mat(&mat2);
    free_mat(&mat_res);
}
END_TEST

// Функции-тесты группируются в тестовые случаи (test case, TCase), а несколько
// тестовых случаев образуют тестовый набор (test suite, Suite).
Suite* mult_mat_suite(void)
{
    Suite *s;
    TCase *tc_all;

    // Создадим тестовый набор для тестирования функции mult_mat
    s = suite_create("mult_mat");

    // Создадим тестовый случай из функций-тестов, которые проверяют работу
    // mult_mat для корректных параметров
    tc_all = tcase_create("all_tests");
    // Добавим в tc_all соответствующие функции-тесты
    tcase_add_test(tc_all, test_mult_mat_p1_y1);
    tcase_add_test(tc_all, test_mult_mat_p2_y2);
    tcase_add_test(tc_all, test_mult_mat_p1_y2);
    tcase_add_test(tc_all, test_mult_mat_p2_y1);
    tcase_add_test(tc_all, test_mult_mat_p3_y3);
    tcase_add_test(tc_all, test_mult_mat_p0_y0);
    tcase_add_test(tc_all, test_mult_mat_p0_y1);
    tcase_add_test(tc_all, test_mult_mat_p2_y0);
    tcase_add_test(tc_all, test_mult_mat_1elem_p2_y2);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_all);

    return s;
}
