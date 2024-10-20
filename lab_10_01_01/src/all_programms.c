#include "all_programms.h"

// 1 работа с 1 элементом в односвязном списке

// вставка элемента перед данным
void insert(node_t **head, node_t *elem, node_t *before)
{
    if (elem == NULL)
        return;
    if (*head == NULL)
    {
        elem->next = NULL;
        *head = elem;
    }
    else if (*head == before)
    {
        elem->next = *head;
        *head = elem;
    }
    else
    {
        node_t *cursor = *head;
        while (cursor != NULL && cursor->next != before)
            cursor = cursor->next;
        if (cursor != NULL)
        {
            elem->next = cursor->next;
            cursor->next = elem;
        }
    }
}
// достаётся и удаляется из списка перый элемент
void *pop_front(node_t **head)
{
    struct this_day *data_res = NULL;
    if (head != NULL && *head != NULL)
    {
        data_res = (*head)->data;
        node_t *tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
    return data_res;
}

// 2 работа с односвязным списком целиком

// разворот односвязного списка (возвращается «новая» голова)
node_t *reverse(node_t *head)
{
    node_t *before = NULL;
    node_t *after;
    node_t *current = head;
    while (current != NULL)
    {
        after = current->next;
        current->next = before;
        before = current;
        current = after;
    }
    return before;
}

// 3 сортировка & односвязный список целиком

// вставка элемента в нужное место в отсортированном односвязном списке
void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *))
{
    if (element == NULL)
        return;

    if (*head == NULL)
    {
        element->next = *head;
        *head = element;
    }
    else
    {
        node_t *cursor = *head;
        node_t *before = NULL;

        while (cursor != NULL && comparator(cursor->data, element->data) < 0)
        {
            before = cursor;
            cursor = cursor->next;
        }

        if (before != NULL)
            before->next = element;
        else
            *head = element;

        element->next = cursor;
    }
}

// сортировка односвязного списка вставками с помощью функции sorted_insert
node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    if (head == NULL)
        return NULL;
    node_t *new_head = head;
    node_t *tmp;
    node_t *cursor = head->next;
    new_head->next = NULL;
    while (cursor != NULL)
    {
        tmp = cursor->next;
        cursor->next = NULL;
        sorted_insert(&new_head, cursor, comparator);
        cursor = tmp;
    }
    return new_head;
}
