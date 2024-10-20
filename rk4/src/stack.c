#include "stack.h"

int pop_din(struct Node** head, char *res)
{
    int rc = OK;
    struct Node tmp;
    if ((*head) != NULL)
    {
        tmp = **head;
        *res = tmp.data;
        free(*head);
        (*head) = tmp.next;
    }
    else
    {
        rc = ERROR;
    }
    return rc;
}

int push_din(struct Node **head, char num)
{
    int rc = OK;
    struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
    if (tmp == NULL)
    {
        printf("Memory error!\n");
        rc = ERROR;
    }
    else
    {
        tmp->next = *head;
        tmp->data = num;

        *head = tmp;
    }
    return rc;
}

void free_stack_din(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        struct Node *tmp = current;
        current = current->next;
        free(tmp);
    }
}

void read_din(struct Node *head)
{
    if (head == NULL)
    {
        printf("Stack is empty!");
        return;
    }
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%c", current->data);
        current = current->next;
    }
}

int work_din(struct Node **head)
{
    int res = 0;
    char sim_now;
    while (*head != NULL)
    {
        pop_din(head, &sim_now);
        if (sim_now == '(')
            res++;
        else if (sim_now == ')')
            res--;
    }
    return res;
}

/*int work_din(struct Node **head)
{
    int res = 0;
    if (*head == NULL)
    {
        res = YES;
    }
    else
    {
        char sim_now;
        while (*head != NULL)
        {
            pop_din(head, &sim_now);
            if (sim_now == '(')
                res++;
            else if (sim_now == ')')
                res--;
        }
        if (res != 0)
            res = NO;
        else
            res = YES;
    }
    return res;
}*/

