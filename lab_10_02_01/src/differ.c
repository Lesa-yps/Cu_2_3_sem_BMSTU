#include "differ.h"

// находит производную полинома
int differ(void)
{
    int rc = OK;
    node_t *head = NULL;
    node_t *current;
    node_t **after = &head;
    struct elem *elem1;
    rc = read_polyn(stdin, &head);
    if (rc == OK)
    {
        //printf("differ!\n");
        current = head;
        while (current != NULL)
        {
            elem1 = (struct elem*) current->data;
            if (elem1->degree == 0)
            {
                *after = current->next;
                free_one(current);
                current = *after;
            }
            else
            {
                elem1->coefficient *= elem1->degree;
                elem1->degree--;
                after = &(current->next);
                current = current->next;
            }
        }
        print_polyn(head);
        free_all(&head);
    }
    return rc;
}
