#include <stdio.h>
#include <stdlib.h>

#include "check_func_1.h"
#include "associative_array.h"

typedef struct
{
    char *key;
    int value;
} type_t;

void print_address(const char *key, int *num, void *param)
{
    (void)param;
    printf("key: %s; num: %d; &num: %p\n", key, *num, (void *)num);
}

// region assoc_array_create

// endregion

// region assoc_array_destroy

// array = NULL после вызова
START_TEST(test_assoc_array_destroy_assign_null)
{
    assoc_array_t arr = assoc_array_create();
    assoc_array_destroy(&arr);
    ck_assert_ptr_null(arr);
}
END_TEST

// endregion

// region assoc_array_insert

// Пустой ключ
START_TEST(test_assoc_array_insert_key_empty)
{
    type_t exp[] = {{.key = "", .value = 0}};
    assoc_array_t arr = assoc_array_create();

    int rc = assoc_array_insert(arr, exp[0].key, exp[0].value);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);

    assoc_array_destroy(&arr);
}
END_TEST

// Ключ существует
START_TEST(test_assoc_array_insert_key_exist)
{
    type_t exp[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-1", .value = 0}};
    assoc_array_t arr = assoc_array_create();
    int rc;
    rc = assoc_array_insert(arr, exp[0].key, exp[0].value);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(arr, exp[1].key, exp[1].value);
    ck_assert_int_eq(rc, ASSOC_ARRAY_KEY_EXISTS);

    assoc_array_destroy(&arr);
}
END_TEST

// Успешное добавление
START_TEST(test_assoc_array_insert_ok)
{
    type_t exp[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 0}};
    assoc_array_t arr = assoc_array_create();
    int rc;
    rc = assoc_array_insert(arr, exp[0].key, exp[0].value);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(arr, exp[1].key, exp[1].value);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);

    assoc_array_destroy(&arr);
}
END_TEST

// arr==NULL
START_TEST(test_assoc_array_insert_arr_null)
{
    type_t exp[] = {{.key = "", .value = 0}};
    assoc_array_t arr = assoc_array_create();

    int rc = assoc_array_insert(NULL, exp[0].key, exp[0].value);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);

    assoc_array_destroy(&arr);
}
END_TEST

// key==NULL
START_TEST(test_assoc_array_insert_key_null)
{
    type_t exp[] = {{.key = "", .value = 0}};
    assoc_array_t arr = assoc_array_create();

    int rc = assoc_array_insert(arr, NULL, exp[0].value);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);

    assoc_array_destroy(&arr);
}
END_TEST

// endregion

// region assoc_array_find

// Пустой ключ
START_TEST(test_assoc_array_find_empty)
{
    type_t exp[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 1},
        {.key = "Key-3", .value = 2},
        {.key = "Key-4", .value = 3},
        {.key = "Key-5", .value = 4},
        {.key = "Key-6", .value = 5}};
    size_t n_exp = sizeof(exp) / sizeof(exp[0]);
    assoc_array_t arr = assoc_array_create();
    int rc;
    for (size_t i = 0; i < n_exp; i++)
    {
        rc = assoc_array_insert(arr, exp[i].key, exp[i].value);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    }

    int *num;
    const char *key = "";
    rc = assoc_array_find(arr, key, &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);

    assoc_array_destroy(&arr);
}
END_TEST

// Не найден
START_TEST(test_assoc_array_find_not_found)
{
    type_t exp[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 1},
        {.key = "Key-3", .value = 2},
        {.key = "Key-4", .value = 3},
        {.key = "Key-5", .value = 4},
        {.key = "Key-6", .value = 5}};
    size_t n_exp = sizeof(exp) / sizeof(exp[0]);
    assoc_array_t arr = assoc_array_create();
    int rc;
    for (size_t i = 0; i < n_exp; i++)
    {
        rc = assoc_array_insert(arr, exp[i].key, exp[i].value);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    }

    int *num;
    const char *key = "Key-0";
    rc = assoc_array_find(arr, key, &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_NOT_FOUND);

    assoc_array_destroy(&arr);
}
END_TEST

// Искать первый элемент
START_TEST(test_assoc_array_find_ok_first)
{
    type_t exp[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 1},
        {.key = "Key-3", .value = 2},
        {.key = "Key-4", .value = 3},
        {.key = "Key-5", .value = 4},
        {.key = "Key-6", .value = 5}};
    size_t n_exp = sizeof(exp) / sizeof(exp[0]);
    assoc_array_t arr = assoc_array_create();
    int rc;
    for (size_t i = 0; i < n_exp; i++)
    {
        rc = assoc_array_insert(arr, exp[i].key, exp[i].value);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    }

    int *num, *num_exp = &exp[0].value;
    const char *key = "Key-1";

    rc = assoc_array_find(arr, key, &num);

    // assoc_array_each(arr, print_address, NULL);
    // print_address("found", num, NULL);

    ck_assert_int_eq(*num, *num_exp);

    assoc_array_destroy(&arr);
}
END_TEST

// Искать последний элемент
START_TEST(test_assoc_array_find_ok_last)
{
    type_t exp[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 1},
        {.key = "Key-3", .value = 2},
        {.key = "Key-4", .value = 3},
        {.key = "Key-5", .value = 4},
        {.key = "Key-6", .value = 5}};
    size_t n_exp = sizeof(exp) / sizeof(exp[0]);
    assoc_array_t arr = assoc_array_create();
    int rc;
    for (size_t i = 0; i < n_exp; i++)
    {
        rc = assoc_array_insert(arr, exp[i].key, exp[i].value);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    }

    int *num, *num_exp = &exp[5].value;
    const char *key = "Key-6";

    rc = assoc_array_find(arr, key, &num);

    // assoc_array_each(arr, print_address, NULL);
    // print_address("found", num, NULL);

    ck_assert_int_eq(*num, *num_exp);

    assoc_array_destroy(&arr);
}
END_TEST

// Искать серединый элемент
START_TEST(test_assoc_array_find_ok_mid)
{
    type_t exp[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 1},
        {.key = "Key-3", .value = 2},
        {.key = "Key-4", .value = 3},
        {.key = "Key-5", .value = 4},
        {.key = "Key-6", .value = 5}};
    size_t n_exp = sizeof(exp) / sizeof(exp[0]);
    assoc_array_t arr = assoc_array_create();
    int rc;
    for (size_t i = 0; i < n_exp; i++)
    {
        rc = assoc_array_insert(arr, exp[i].key, exp[i].value);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    }

    int *num, *num_exp = &exp[3].value;
    const char *key = "Key-4";

    rc = assoc_array_find(arr, key, &num);

    // assoc_array_each(arr, print_address, NULL);
    // print_address("found", num, NULL);

    ck_assert_int_eq(*num, *num_exp);

    assoc_array_destroy(&arr);
}
END_TEST

// arr==NULL
START_TEST(test_assoc_array_arr_null)
{
    type_t exp[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 1},
        {.key = "Key-3", .value = 2},
        {.key = "Key-4", .value = 3},
        {.key = "Key-5", .value = 4},
        {.key = "Key-6", .value = 5}};
    size_t n_exp = sizeof(exp) / sizeof(exp[0]);
    assoc_array_t arr = assoc_array_create();
    int rc;
    for (size_t i = 0; i < n_exp; i++)
    {
        rc = assoc_array_insert(arr, exp[i].key, exp[i].value);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    }

    int *num;
    const char *key = "";
    rc = assoc_array_find(NULL, key, &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);

    assoc_array_destroy(&arr);
}
END_TEST

// key==NULL
START_TEST(test_assoc_array_key_null)
{
    type_t exp[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 1},
        {.key = "Key-3", .value = 2},
        {.key = "Key-4", .value = 3},
        {.key = "Key-5", .value = 4},
        {.key = "Key-6", .value = 5}};
    size_t n_exp = sizeof(exp) / sizeof(exp[0]);
    assoc_array_t arr = assoc_array_create();
    int rc;
    for (size_t i = 0; i < n_exp; i++)
    {
        rc = assoc_array_insert(arr, exp[i].key, exp[i].value);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    }

    int *num;
    rc = assoc_array_find(arr, NULL, &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);

    assoc_array_destroy(&arr);
}
END_TEST

// num==NULL
START_TEST(test_assoc_array_num_null)
{
    type_t exp[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 1},
        {.key = "Key-3", .value = 2},
        {.key = "Key-4", .value = 3},
        {.key = "Key-5", .value = 4},
        {.key = "Key-6", .value = 5}};
    size_t n_exp = sizeof(exp) / sizeof(exp[0]);
    assoc_array_t arr = assoc_array_create();
    int rc;
    for (size_t i = 0; i < n_exp; i++)
    {
        rc = assoc_array_insert(arr, exp[i].key, exp[i].value);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    }

    const char *key = "";
    rc = assoc_array_find(arr, key, NULL);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);

    assoc_array_destroy(&arr);
}
END_TEST
// endregion

// region assoc_array_remove

// Пустой ключ
START_TEST(test_assoc_array_remove_empty)
{
    type_t exp[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 1},
        {.key = "Key-3", .value = 2},
        {.key = "Key-4", .value = 3},
        {.key = "Key-5", .value = 4},
        {.key = "Key-6", .value = 5}};
    size_t n_exp = sizeof(exp) / sizeof(exp[0]);
    assoc_array_t arr = assoc_array_create();
    int rc;
    for (size_t i = 0; i < n_exp; i++)
    {
        rc = assoc_array_insert(arr, exp[i].key, exp[i].value);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    }

    const char *key = "";
    rc = assoc_array_remove(arr, key);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);

    assoc_array_destroy(&arr);
}
END_TEST

// Не найден
START_TEST(test_assoc_array_remove_not_found)
{
    type_t exp[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 1},
        {.key = "Key-3", .value = 2},
        {.key = "Key-4", .value = 3},
        {.key = "Key-5", .value = 4},
        {.key = "Key-6", .value = 5}};
    size_t n_exp = sizeof(exp) / sizeof(exp[0]);
    assoc_array_t arr = assoc_array_create();
    int rc;
    for (size_t i = 0; i < n_exp; i++)
    {
        rc = assoc_array_insert(arr, exp[i].key, exp[i].value);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    }

    const char *key = "Key-0";
    rc = assoc_array_remove(arr, key);
    ck_assert_int_eq(rc, ASSOC_ARRAY_NOT_FOUND);

    assoc_array_destroy(&arr);
}
END_TEST

// Удалить первый элемент
START_TEST(test_assoc_array_remove_first_elem)
{
    type_t exp[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 1},
        {.key = "Key-3", .value = 2},
        {.key = "Key-4", .value = 3},
        {.key = "Key-5", .value = 4},
        {.key = "Key-6", .value = 5}};
    size_t n_exp = sizeof(exp) / sizeof(exp[0]);
    assoc_array_t arr = assoc_array_create();
    int rc;
    for (size_t i = 0; i < n_exp; i++)
    {
        rc = assoc_array_insert(arr, exp[i].key, exp[i].value);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    }

    const char *key = "Key-1";
    rc = assoc_array_remove(arr, key);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);

    int *num;
    for (size_t i = 1; i < n_exp; i++)
    {
        int rc = assoc_array_find(arr, exp[i].key, &num);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
        ck_assert_int_eq(*num, exp[i].value);
    }

    assoc_array_destroy(&arr);
}
END_TEST

// Удалить последний элемент
START_TEST(test_assoc_array_remove_last_elem)
{
    type_t exp[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 1},
        {.key = "Key-3", .value = 2},
        {.key = "Key-5", .value = 3},
        {.key = "Key-4", .value = 4},
        {.key = "Key-6", .value = 5}};
    size_t n_exp = sizeof(exp) / sizeof(exp[0]);
    assoc_array_t arr = assoc_array_create();
    int rc;
    for (size_t i = 0; i < n_exp; i++)
    {
        rc = assoc_array_insert(arr, exp[i].key, exp[i].value);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    }

    const char *key = "Key-6";
    rc = assoc_array_remove(arr, key);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);

    int *num;
    for (size_t i = 0; i < n_exp - 1; i++)
    {
        int rc = assoc_array_find(arr, exp[i].key, &num);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
        ck_assert_int_eq(*num, exp[i].value);
    }

    assoc_array_destroy(&arr);
}
END_TEST

// Удалить серединый элемент
START_TEST(test_assoc_array_remove_mid_elem)
{
    type_t exp[] = {
        {.key = "Key-6", .value = 0},
        {.key = "Key-1", .value = 1},
        {.key = "Key-4", .value = 2},
        {.key = "Key-3", .value = 3},
        {.key = "Key-2", .value = 4},
        {.key = "Key-5", .value = 5}};
    size_t n_exp = sizeof(exp) / sizeof(exp[0]);
    assoc_array_t arr = assoc_array_create();
    int rc;
    for (size_t i = 0; i < n_exp; i++)
    {
        rc = assoc_array_insert(arr, exp[i].key, exp[i].value);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    }

    const char *key = "Key-4";
    rc = assoc_array_remove(arr, key);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);

    int *num;
    for (size_t i = 0; i < n_exp; i++)
    {
        if (i == 2)
            continue;
        int rc = assoc_array_find(arr, exp[i].key, &num);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
        ck_assert_int_eq(*num, exp[i].value);
    }

    assoc_array_destroy(&arr);
}
END_TEST

// arr==NULL
START_TEST(test_assoc_array_remove_arr_null)
{
    type_t exp[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 1},
        {.key = "Key-3", .value = 2},
        {.key = "Key-4", .value = 3},
        {.key = "Key-5", .value = 4},
        {.key = "Key-6", .value = 5}};
    size_t n_exp = sizeof(exp) / sizeof(exp[0]);
    assoc_array_t arr = assoc_array_create();
    int rc;
    for (size_t i = 0; i < n_exp; i++)
    {
        rc = assoc_array_insert(arr, exp[i].key, exp[i].value);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    }

    const char *key = "";
    rc = assoc_array_remove(arr, key);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);

    assoc_array_destroy(&arr);
}
END_TEST

// key==NULL
START_TEST(test_assoc_array_remove_key_null)
{
    type_t exp[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 1},
        {.key = "Key-3", .value = 2},
        {.key = "Key-4", .value = 3},
        {.key = "Key-5", .value = 4},
        {.key = "Key-6", .value = 5}};
    size_t n_exp = sizeof(exp) / sizeof(exp[0]);
    assoc_array_t arr = assoc_array_create();
    int rc;
    for (size_t i = 0; i < n_exp; i++)
    {
        rc = assoc_array_insert(arr, exp[i].key, exp[i].value);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    }

    const char *key = "";
    rc = assoc_array_remove(arr, key);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);

    assoc_array_destroy(&arr);
}
END_TEST
// endregion

// region assoc_array_clear

// Пустой массив
START_TEST(test_assoc_array_clear_empty)
{
    assoc_array_t arr = assoc_array_create();
    int rc = assoc_array_clear(arr);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    assoc_array_destroy(&arr);
}
END_TEST

// Не пустой массив
START_TEST(test_assoc_array_clear_no_empty)
{
    type_t exp[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 1},
        {.key = "Key-3", .value = 2},
        {.key = "Key-4", .value = 3},
        {.key = "Key-5", .value = 4},
        {.key = "Key-6", .value = 5}};
    size_t n_exp = sizeof(exp) / sizeof(exp[0]);
    assoc_array_t arr = assoc_array_create();
    int rc;
    for (size_t i = 0; i < n_exp; i++)
    {
        rc = assoc_array_insert(arr, exp[i].key, exp[i].value);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    }

    rc = assoc_array_clear(arr);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    assoc_array_destroy(&arr);
}
END_TEST

// endregion

// region assoc_array_each

// Умножение num*param
static void mul_by(const char *key, int *num, void *param)
{
    (void)key;
    int *p = (int *)param;
    *num *= *p;
}

// Неверный параметр
START_TEST(test_assoc_array_each_null_action)
{
    type_t nums[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 1},
        {.key = "Key-3", .value = 2}};
    type_t exp[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 2},
        {.key = "Key-3", .value = 4}};
    size_t n_exp = sizeof(exp) / sizeof(exp[0]);
    assoc_array_t arr = assoc_array_create();
    int rc;
    for (size_t i = 0; i < n_exp; i++)
    {
        rc = assoc_array_insert(arr, nums[i].key, nums[i].value);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    }

    int scale = 2;
    rc = assoc_array_each(arr, NULL, &scale);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);

    assoc_array_destroy(&arr);
}
END_TEST

// Успешное действие (умножение все число на два)
START_TEST(test_assoc_array_each_ok)
{
    type_t nums[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 1},
        {.key = "Key-3", .value = 2}};
    type_t exp[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 2},
        {.key = "Key-3", .value = 4}};
    size_t n_exp = sizeof(exp) / sizeof(exp[0]);
    assoc_array_t arr = assoc_array_create();
    int rc;
    for (size_t i = 0; i < n_exp; i++)
    {
        rc = assoc_array_insert(arr, nums[i].key, nums[i].value);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    }

    int scale = 2;
    rc = assoc_array_each(arr, mul_by, &scale);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);

    int *num;
    for (size_t i = 0; i < n_exp; i++)
    {
        int rc = assoc_array_find(arr, exp[i].key, &num);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
        ck_assert_int_eq(*num, exp[i].value);
    }

    assoc_array_destroy(&arr);
}
END_TEST

// arr==NULL
START_TEST(test_assoc_array_each_arr_null)
{
    type_t nums[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 1},
        {.key = "Key-3", .value = 2}};
    type_t exp[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 2},
        {.key = "Key-3", .value = 4}};
    size_t n_exp = sizeof(exp) / sizeof(exp[0]);
    assoc_array_t arr = assoc_array_create();
    int rc;
    for (size_t i = 0; i < n_exp; i++)
    {
        rc = assoc_array_insert(arr, nums[i].key, nums[i].value);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    }

    int scale = 2;
    rc = assoc_array_each(NULL, mul_by, &scale);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);

    assoc_array_destroy(&arr);
}
END_TEST
// endregion

// region assoc_array_min

// Неверный параметр
START_TEST(test_assoc_array_min_wrong)
{
    type_t exp[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 1},
        {.key = "Key-3", .value = 2},
        {.key = "Key-4", .value = 3},
        {.key = "Key-5", .value = 4},
        {.key = "Key-6", .value = 5}};
    size_t n_exp = sizeof(exp) / sizeof(exp[0]);
    assoc_array_t arr = assoc_array_create();
    int rc;
    for (size_t i = 0; i < n_exp; i++)
    {
        rc = assoc_array_insert(arr, exp[i].key, exp[i].value);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    }

    rc = assoc_array_min(arr, NULL);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);

    assoc_array_destroy(&arr);
}
END_TEST

// Пустой массив
START_TEST(test_assoc_array_min_empty)
{
    type_t exp[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 1},
        {.key = "Key-3", .value = 2},
        {.key = "Key-4", .value = 3},
        {.key = "Key-5", .value = 4},
        {.key = "Key-6", .value = 5}};
    size_t n_exp = 0;
    assoc_array_t arr = assoc_array_create();
    int rc;
    for (size_t i = 0; i < n_exp; i++)
    {
        rc = assoc_array_insert(arr, exp[i].key, exp[i].value);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    }

    int *num;
    rc = assoc_array_min(arr, &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_NOT_FOUND);

    assoc_array_destroy(&arr);
}
END_TEST

// Первый элемент минимальный
START_TEST(test_assoc_array_min_first_elem)
{
    type_t exp[] = {
        {.key = "Key-.", .value = 0},
        {.key = "Key-2", .value = 1},
        {.key = "Key-3", .value = 2},
        {.key = "Key-4", .value = 3},
        {.key = "Key-5", .value = 4},
        {.key = "Key-6", .value = 5}};
    size_t n_exp = sizeof(exp) / sizeof(exp[0]);
    assoc_array_t arr = assoc_array_create();
    int rc;
    for (size_t i = 0; i < n_exp; i++)
    {
        rc = assoc_array_insert(arr, exp[i].key, exp[i].value);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    }

    int *num, num_exp = 0;
    rc = assoc_array_min(arr, &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, num_exp);

    assoc_array_destroy(&arr);
}
END_TEST

// Последний элемент минимальный
START_TEST(test_assoc_array_min_last_elem)
{
    type_t exp[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 1},
        {.key = "Key-3", .value = 2},
        {.key = "Key-4", .value = 3},
        {.key = "Key-5", .value = 4},
        {.key = "Key-.", .value = -5}};
    size_t n_exp = sizeof(exp) / sizeof(exp[0]);
    assoc_array_t arr = assoc_array_create();
    int rc;
    for (size_t i = 0; i < n_exp; i++)
    {
        rc = assoc_array_insert(arr, exp[i].key, exp[i].value);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    }

    int *num, num_exp = -5;
    rc = assoc_array_min(arr, &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, num_exp);

    assoc_array_destroy(&arr);
}
END_TEST

// Серединый элемент минимальный
START_TEST(test_assoc_array_min_mid_elem)
{
    type_t exp[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 1},
        {.key = "Key-3", .value = 2},
        {.key = "Key-.", .value = -3},
        {.key = "Key-5", .value = 4},
        {.key = "Key-6", .value = 5}};
    size_t n_exp = sizeof(exp) / sizeof(exp[0]);
    assoc_array_t arr = assoc_array_create();
    int rc;
    for (size_t i = 0; i < n_exp; i++)
    {
        rc = assoc_array_insert(arr, exp[i].key, exp[i].value);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    }

    int *num, num_exp = -3;
    rc = assoc_array_min(arr, &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, num_exp);

    assoc_array_destroy(&arr);
}
END_TEST

// endregion

// region assoc_array_max

// Неверный параметр
START_TEST(test_assoc_array_max_wrong)
{
    type_t exp[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 1},
        {.key = "Key-3", .value = 2},
        {.key = "Key-4", .value = 3},
        {.key = "Key-5", .value = 4},
        {.key = "Key-6", .value = 5}};
    size_t n_exp = sizeof(exp) / sizeof(exp[0]);
    assoc_array_t arr = assoc_array_create();
    int rc;
    for (size_t i = 0; i < n_exp; i++)
    {
        rc = assoc_array_insert(arr, exp[i].key, exp[i].value);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    }

    rc = assoc_array_max(arr, NULL);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);

    assoc_array_destroy(&arr);
}
END_TEST

// Пустой массив
START_TEST(test_assoc_array_max_empty)
{
    type_t exp[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 1},
        {.key = "Key-3", .value = 2},
        {.key = "Key-4", .value = 3},
        {.key = "Key-5", .value = 4},
        {.key = "Key-6", .value = 5}};
    size_t n_exp = 0;
    assoc_array_t arr = assoc_array_create();
    int rc;
    for (size_t i = 0; i < n_exp; i++)
    {
        rc = assoc_array_insert(arr, exp[i].key, exp[i].value);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    }

    int *num;
    rc = assoc_array_max(arr, &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_NOT_FOUND);

    assoc_array_destroy(&arr);
}
END_TEST

// Первый элемент минимальный
START_TEST(test_assoc_array_max_first_elem)
{
    type_t exp[] = {
        {.key = "Key-~", .value = 0},
        {.key = "Key-2", .value = 1},
        {.key = "Key-3", .value = 2},
        {.key = "Key-4", .value = 3},
        {.key = "Key-5", .value = 4},
        {.key = "Key-6", .value = 5}};
    size_t n_exp = sizeof(exp) / sizeof(exp[0]);
    assoc_array_t arr = assoc_array_create();
    int rc;
    for (size_t i = 0; i < n_exp; i++)
    {
        rc = assoc_array_insert(arr, exp[i].key, exp[i].value);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    }

    int *num, num_exp = 0;
    rc = assoc_array_max(arr, &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, num_exp);

    assoc_array_destroy(&arr);
}
END_TEST

// Последний элемент минимальный
START_TEST(test_assoc_array_max_last_elem)
{
    type_t exp[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 1},
        {.key = "Key-3", .value = 2},
        {.key = "Key-4", .value = 3},
        {.key = "Key-5", .value = 4},
        {.key = "Key-~", .value = 5}};
    size_t n_exp = sizeof(exp) / sizeof(exp[0]);
    assoc_array_t arr = assoc_array_create();
    int rc;
    for (size_t i = 0; i < n_exp; i++)
    {
        rc = assoc_array_insert(arr, exp[i].key, exp[i].value);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    }

    int *num, num_exp = 5;
    rc = assoc_array_max(arr, &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, num_exp);

    assoc_array_destroy(&arr);
}
END_TEST

// Серединый элемент минимальный
START_TEST(test_assoc_array_max_mid_elem)
{
    type_t exp[] = {
        {.key = "Key-1", .value = 0},
        {.key = "Key-2", .value = 1},
        {.key = "Key-3", .value = 2},
        {.key = "Key-~", .value = 8},
        {.key = "Key-5", .value = 4},
        {.key = "Key-6", .value = 5}};
    size_t n_exp = sizeof(exp) / sizeof(exp[0]);
    assoc_array_t arr = assoc_array_create();
    int rc;
    for (size_t i = 0; i < n_exp; i++)
    {
        rc = assoc_array_insert(arr, exp[i].key, exp[i].value);
        ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    }

    int *num, num_exp = 8;
    rc = assoc_array_max(arr, &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, num_exp);

    assoc_array_destroy(&arr);
}
END_TEST

// endregion

Suite *func_1_suite(void)
{
    Suite *suite = suite_create("func_1");

    TCase *tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_assoc_array_destroy_assign_null);

    tcase_add_test(tc_pos, test_assoc_array_insert_key_empty);
    tcase_add_test(tc_pos, test_assoc_array_insert_key_exist);
    tcase_add_test(tc_pos, test_assoc_array_insert_ok);
    tcase_add_test(tc_pos, test_assoc_array_insert_arr_null);
    tcase_add_test(tc_pos, test_assoc_array_insert_key_null);

    tcase_add_test(tc_pos, test_assoc_array_find_empty);
    tcase_add_test(tc_pos, test_assoc_array_find_not_found);
    tcase_add_test(tc_pos, test_assoc_array_find_ok_first);
    tcase_add_test(tc_pos, test_assoc_array_find_ok_last);
    tcase_add_test(tc_pos, test_assoc_array_find_ok_mid);
    tcase_add_test(tc_pos, test_assoc_array_arr_null);
    tcase_add_test(tc_pos, test_assoc_array_key_null);
    tcase_add_test(tc_pos, test_assoc_array_num_null);

    tcase_add_test(tc_pos, test_assoc_array_remove_empty);
    tcase_add_test(tc_pos, test_assoc_array_remove_not_found);
    tcase_add_test(tc_pos, test_assoc_array_remove_first_elem);
    tcase_add_test(tc_pos, test_assoc_array_remove_last_elem);
    tcase_add_test(tc_pos, test_assoc_array_remove_mid_elem);
    tcase_add_test(tc_pos, test_assoc_array_remove_arr_null);
    tcase_add_test(tc_pos, test_assoc_array_remove_key_null);

    tcase_add_test(tc_pos, test_assoc_array_clear_empty);
    tcase_add_test(tc_pos, test_assoc_array_clear_no_empty);

    tcase_add_test(tc_pos, test_assoc_array_each_null_action);
    tcase_add_test(tc_pos, test_assoc_array_each_ok);
    tcase_add_test(tc_pos, test_assoc_array_each_arr_null);

    tcase_add_test(tc_pos, test_assoc_array_min_wrong);
    tcase_add_test(tc_pos, test_assoc_array_min_empty);
    tcase_add_test(tc_pos, test_assoc_array_min_first_elem);
    tcase_add_test(tc_pos, test_assoc_array_min_last_elem);
    tcase_add_test(tc_pos, test_assoc_array_min_mid_elem);

    tcase_add_test(tc_pos, test_assoc_array_max_wrong);
    tcase_add_test(tc_pos, test_assoc_array_max_empty);
    tcase_add_test(tc_pos, test_assoc_array_max_first_elem);
    tcase_add_test(tc_pos, test_assoc_array_max_last_elem);
    tcase_add_test(tc_pos, test_assoc_array_max_mid_elem);

    suite_add_tcase(suite, tc_pos);
    return suite;
}
