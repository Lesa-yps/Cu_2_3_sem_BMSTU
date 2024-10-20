#include "calc_a.h"

int my_pow(int a, int deg);

// вычисляет полином для переданного значения
int calc_a(void)
{ 
    int rc = OK;
    int res = 0;
    node_t *head = NULL;
    node_t *current;
    struct elem *elem1;
    int a;
    rc = read_polyn(stdin, &head);
    if (rc == OK)
    {
        //printf("read a: ");
        if (scanf("%d", &a) != 1)
        {
            //printf("ERROR!\n");
            rc = ERROR;
        }
        else
        {
            //printf("---------------------------------\n");
            current = head;
            //printf("head = %p", (void *) head);
            while (current != NULL)
            {
                elem1 = (struct elem*) current->data;
                res += elem1->coefficient * my_pow(a, elem1->degree);
                //printf(" coef = %d deg = %d res = %d\n", elem1->coefficient, elem1->degree, res);
                current = current->next;
                //printf("cur = %p\n", (void *) current);
            }
            printf("%d\n", res);
        }
        free_all(&head);
    }
    return rc;
}

int my_pow(int a, int deg)
{
    int res;
    if (deg == 0)
        res = 1;
    else
    {
        res = a;
        int j = 2;
        while (j <= deg)
        {
            res *= a;
            j++;
        }
    }
    return res;
}
