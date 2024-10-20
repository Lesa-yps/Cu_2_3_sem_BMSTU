#include "diff_even_odd.h"

// добавляет переданный элемент в конец односвязного списка
void push_back(node_t **head, node_t *ins)
{
    node_t *current = *head;
    if (current == NULL)
    {
        *head = ins;
        ins->next = NULL;
    }
    else
    {
        while (current->next != NULL)
            current = current->next;
        current->next = ins;
        ins->next = NULL;
    }
}

// разделяет полином на чётные/нечётные степени (и выводит)
int diff_even_odd(void)
{
    int rc = OK;
    node_t *head = NULL;
    struct elem *elem1;
    node_t *head_even = NULL;
    node_t *head_odd = NULL;
    node_t *current;
    node_t *tmp;
    rc = read_polyn(stdin, &head);
    if (rc == OK)
    {
        current = head;
        while (current != NULL)
        {
            elem1 = (struct elem*) current->data;
            tmp = current->next;
            if (elem1->degree % 2 == 0)
                push_back(&head_even, current);
            else
                push_back(&head_odd, current);
            current = tmp;
        }
        print_polyn(head_even);
        print_polyn(head_odd);
        free_all(&head_even);
        free_all(&head_odd);
    }
    return rc;
}
