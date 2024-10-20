#include "work_with_mem.h"

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

// создание одного элемента односвязного списка (+ выделение памяти)
int create_one(node_t **head, int one_coef, int one_deg)
{
    int rc = OK;
    struct elem *one_data;
    node_t *one_node = calloc(1, sizeof(node_t));
    if (one_node == NULL)
        rc = ERROR;
    else
    {
        one_data = calloc(1, sizeof(struct elem));
        if (one_data == NULL)
            rc = ERROR;
        else
        {
            one_data->coefficient = one_coef;
            one_data->degree = one_deg;
            one_node->data = one_data;
            one_node->next = NULL;
            *head = one_node;
        }
    }
    return rc;
}


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
