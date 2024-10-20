#include <stdio.h>

#include "stack.h"

int main(void)
{
    int rc = OK;
    char a = ' ';
    struct Node *Head = NULL;
    while (((a = getchar()) != '\n') && (rc == OK))
    {
        if (a == '(')
            rc = push_din(&Head, a);
        else if (a == ')')
        {
            rc = pop_din(&Head, &a);
            if (rc == ERROR)
                printf("Result = NO\n");
        }
    }
    if (rc == OK)
    {
        if (Head != NULL)
        {
            printf("Result = NO\n");
            free_stack_din(Head);
        }
        else
            printf("Result = YES\n");
    }
    return rc;
}
