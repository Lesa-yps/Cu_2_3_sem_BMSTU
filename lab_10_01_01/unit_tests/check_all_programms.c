#include "all_programms.h"
#include <check.h>
#include "const_struct.h"
#include <stddef.h>

int create_one(node_t **one_node, int a, int b, int c);
// сравнивает структуры день в приоритете год->месяц->день
int comparator(const void *a, const void *b);
// освобождение памяти всего односвязного списка
void free_all(node_t **head);

// 1 работа с 1 элементом в односвязном списке

// вставка элемента перед данным
//void insert(node_t **head, node_t *elem, node_t *before);

START_TEST(test_insert)
{
    int rc = OK;
    node_t *head;
    node_t *elem;
    rc = create_one(&elem, 31, 9, 2021);
    if (rc == OK)
    {
        rc = create_one(&head, 12, 11, 2023);
        if (rc == OK)
        {
            rc = create_one(&(head->next), 1, 11, 2019);
            if (rc == OK)
            {
                // вставка элемента перед данным
                insert(&head, elem, head->next);
                ck_assert_int_eq(head->next == elem, 1);
            }
            free_all(&head);
        }
    }
}
END_TEST

// достаётся и удаляется из списка перый элемент
//void *pop_front(node_t **head);

START_TEST(test_pop_front)
{
    int rc = OK;
    node_t *head;
    struct this_day *elem;
    rc = create_one(&head, 12, 9, 2023);
    if (rc == OK)
    {
        rc = create_one(&(head->next), 1, 11, 2019);
        if (rc == OK)
        {
            // достаётся и удаляется из списка перый элемент
            elem = (struct this_day *) pop_front(&head);
            ck_assert_int_eq(elem->day, 12);
            ck_assert_int_eq(elem->month, 9);
            ck_assert_int_eq(elem->year, 2023);
        }
        free_all(&head);
    }
    free(elem);
}
END_TEST

// 2 работа с односвязным списком целиком

// разворот односвязного списка (возвращается «новая» голова)
//node_t *reverse(node_t *head);

int smp_elems(struct this_day *a, struct this_day b)
{
    if (a->day == b.day && a->month == b.month && a->year == b.year)
        return OK;
    return ERROR;
}

START_TEST(test_reverse)
{
    int rc = OK;
    node_t *head;
    node_t *head_new;
    struct this_day elems[] = {{.day = 12, .month = 9, .year = 2023},
                               {.day = 1, .month = 11, .year = 2019}};

    rc = create_one(&head, (elems[0]).day, (elems[0]).month, (elems[0]).year);
    if (rc == OK)
    {
        rc = create_one(&(head->next), (elems[1]).day, (elems[1]).month, (elems[1]).year);
        if (rc == OK)
        {
            // разворот односвязного списка (возвращается «новая» голова)
            head_new = reverse(head);
            ck_assert_int_eq(smp_elems((struct this_day *)(head_new->data), elems[1]), OK);
            ck_assert_int_eq(smp_elems((struct this_day *)(head_new->next->data), elems[0]), OK);
        }
        free_all(&head_new);
    }
}
END_TEST

// 3 сортировка & односвязный список целиком

// вставка элемента в нужное место в отсортированном односвязном списке
//void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *));

START_TEST(test_sorted_insert)
{
    int rc = OK;
    node_t *head;
    struct this_day elems[] = {{.day = 23, .month = 9, .year = 2019},
                               {.day = 1, .month = 11, .year = 2019}};
    node_t *elem;
    rc = create_one(&elem, 1, 12, 2018);
    if (rc == OK)
    {
        rc = create_one(&head, (elems[0]).day, (elems[0]).month, (elems[0]).year);
        if (rc == OK)
        {
            rc = create_one(&(head->next), (elems[1]).day, (elems[1]).month, (elems[1]).year);
            if (rc == OK)
            {
                // вставка элемента в нужное место в отсортированном односвязном списке
                sorted_insert(&head, elem, comparator);
                ck_assert_int_eq(head == elem, 1);
            }
            free_all(&head);
        }
    }
}
END_TEST

// сортировка односвязного списка вставками с помощью функции sorted_insert
//node_t *sort(node_t *head, int (*comparator)(const void *, const void *));

START_TEST(test_sort)
{
    int rc = OK;
    node_t *head;
    node_t *new_head;
    struct this_day elems[] = {{.day = 14, .month = 12, .year = 2019},
                               {.day = 1, .month = 11, .year = 2019}};

    rc = create_one(&head, (elems[0]).day, (elems[0]).month, (elems[0]).year);
    if (rc == OK)
    {
        rc = create_one(&(head->next), (elems[1]).day, (elems[1]).month, (elems[1]).year);
        if (rc == OK)
        {
            // сортировка односвязного списка вставками с помощью функции sorted_insert
            new_head = sort(head, comparator);
            ck_assert_int_eq(comparator(new_head->data, &(elems[1])), 0);
            ck_assert_int_eq(comparator((new_head->next)->data, &(elems[0])), 0);
        }
        free_all(&new_head);
    }
}
END_TEST

// Функции-тесты группируются в тестовые случаи (test case, TCase), а несколько
// тестовых случаев образуют тестовый набор (test suite, Suite).
Suite* all_programms_suite(void)
{
    Suite *s;
    TCase *tc_all;

    // Создадим тестовый набор для тестирования функций
    s = suite_create("all_programms");

    // Создадим тестовый случай из функций-тестов
    tc_all = tcase_create("tests");
    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_all, test_insert);
    tcase_add_test(tc_all, test_pop_front);
    tcase_add_test(tc_all, test_reverse);
    tcase_add_test(tc_all, test_sorted_insert);
    tcase_add_test(tc_all, test_sort);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_all);

    return s;
}

// вспомогательные функции создания и освобождения односвязного списка

int create_one(node_t **one_node, int a, int b, int c)
{
    int rc = OK;
    *one_node = calloc(1, sizeof(node_t));
    struct this_day *one_data = calloc(1, sizeof(struct this_day));
    if ((one_node == NULL) || (one_data == NULL))
        rc = ERROR;
    else
    {
        one_data->day = a;
        one_data->month = b;
        one_data->year = c;
        (*one_node)->data = one_data;
        (*one_node)->next = NULL;
    }
    return rc;
}

// сравнивает структуры день в приоритете год->месяц->день
int comparator(const void *a, const void *b)
{
    int res = 0;
    struct this_day *a1 = (struct this_day *) a;
    struct this_day *b1 = (struct this_day *) b;
    if (a1->year == b1->year)
    {
        if (a1->month == b1->month)
            res = a1->day - b1->day;
        else
            res = a1->month - b1->month;
    }
    else
        res = a1->year - b1->year;
    return res;
}

// освобождение памяти одного элемента односвязного списка
void free_one(node_t *one_node)
{
    if (one_node->data)
    {
        free(one_node->data);
        one_node->data = NULL;
    }
    if (one_node)
    {
        free(one_node);
        one_node = NULL;
    }
}

// освобождение памяти всего односвязного списка
void free_all(node_t **head)
{
    node_t *tmp;
    while (*head != NULL)
    {
        tmp = (*head)->next;
        free_one(*head);
        *head = tmp;
    }
}
