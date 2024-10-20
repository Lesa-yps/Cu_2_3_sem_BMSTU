#include "sum_2_lists.h"

// сравнивает структуры
int comparator(const void *a, const void *b);
void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *));

// складывает два полинома
int sum_2_lists(void)
{
    int rc = OK;
    node_t *head1 = NULL;
    node_t *head2 = NULL;
    node_t *current;
    node_t *tmp;
    rc = read_polyn(stdin, &head1);
    if (rc == OK)
    {
        rc = read_polyn(stdin, &head2);
        if (rc == OK)
        {
            current = head2;
            while (current != NULL)
            {
                tmp = current->next;
                current->next = NULL;
                sorted_insert(&head1, current, comparator);
                current = tmp;
            }
            print_polyn(head1);
        }
        free_all(&head1);
    }
    return rc;
}

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *))
{
    if (element == NULL)
        return;

    if (*head == NULL)
    {
        element->next = *head;
        *head = element;
        return;
    }

    node_t *cursor = *head;
    node_t *before = NULL;

    while (cursor != NULL && comparator(cursor->data, element->data) > 0)
    {
        before = cursor;
        cursor = cursor->next;
    }

    if (cursor != NULL && comparator(cursor->data, element->data) == 0)
    {
        // Element already exists in the list, free memory and return
        ((struct elem *) cursor->data)->coefficient += ((struct elem *) element->data)->coefficient;
        free_one(element);
        return;
    }

    if (before != NULL)
        before->next = element;
    else
        *head = element;

    element->next = cursor;
}

// сравнивает структуры
int comparator(const void *a, const void *b)
{
    struct elem *a1 = (struct elem *) a;
    struct elem *b1 = (struct elem *) b;
    return a1->degree - b1->degree;
}
