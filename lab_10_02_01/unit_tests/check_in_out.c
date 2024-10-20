#include "in_out.h"
#include "const_struct.h"
#include "work_with_mem.h"
#include <check.h>
#include <stdio.h>

#define N 2

// чтение полинома
//int read_polyn(FILE *file, node_t **head)

int smp_elems(struct elem *a, struct elem b)
{
    if (a->degree == b.degree && a->coefficient == b.coefficient)
        return OK;
    return ERROR;
}

// pos tests

START_TEST(test_read_pos)
{
    FILE *file;
    int rc = OK;
    node_t *head = NULL;
    struct elem arr_polyn[N] = {{.coefficient = 1, .degree = 2}, {.coefficient = -1, .degree = 1}};
    file = fopen("file.txt", "w");
    for (int i = 0; i < N; i++)
        fprintf(file, "%d %d %d %d\n", (arr_polyn[0]).coefficient, (arr_polyn[0]).degree, (arr_polyn[1]).coefficient, (arr_polyn[1]).degree);
    fclose(file);
    file = fopen("file.txt", "r");
    // функция читает и сортирует массив
    rc = read_polyn(file, &head);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(smp_elems((struct elem *)(head->data), arr_polyn[0]), OK);
    ck_assert_int_eq(smp_elems((struct elem *)(head->next->data), arr_polyn[1]), OK);
    free_all(&head);
    fclose(file);
}
END_TEST

// neg tests

START_TEST(test_read_neg)
{
    FILE *file;
    int rc = OK;
    node_t *head = NULL;
    struct elem arr_polyn[N] = {{.coefficient = 1, .degree = 2}, {.coefficient = -1, .degree = 1}};
    file = fopen("file.txt", "w");
    for (int i = 0; i < N; i++)
        fprintf(file, "%d %d %c %d\n", (arr_polyn[0]).coefficient, (arr_polyn[0]).degree, 'a', (arr_polyn[1]).coefficient);
    fclose(file);
    file = fopen("file.txt", "r");
    // функция читает и сортирует массив
    rc = read_polyn(file, &head);
    ck_assert_int_eq(rc, ERROR);
    fclose(file);
}
END_TEST

// Функции-тесты группируются в тестовые случаи (test case, TCase), а несколько
// тестовых случаев образуют тестовый набор (test suite, Suite).
Suite *in_out_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    // Создадим тестовый набор для тестирования функции in_out
    s = suite_create("read_arr");

    // Создадим тестовый случай из функций-тестов, которые проверяют разного
    // рода ошибочные ситуации при вызове in_out
    tc_neg = tcase_create("negatives");
    // Добавим в tc_neg соответствующие функции-тесты
    tcase_add_test(tc_neg, test_read_neg);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_neg);

    // Создадим тестовый случай из функций-тестов, которые проверяют работу
    // read_arr для корректных параметров
    tc_pos = tcase_create("positives");
    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_pos, test_read_pos);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);

    return s;
}
