#include <stdio.h>
#include <stddef.h>

#include "sort.h"
#include "read.h"
#include "print.h"
#include "const.h"

//main function
int main(void)
{
    int a[M_MAX][N_MAX];
    size_t m;
    size_t n;
    int x = read(a, &m, &n);
    if (x != OK)
    {
        if (x == ERR_M)
            printf("Error with scanf m.\n");
        if (x == ERR_N)
            printf("Error with scanf n.\n");
        if (x == ERR_ELEM)
            printf("Error with scanf elem.\n");
        return x;
    }
    sort(a, m, n);
    print(a, m, n);
    return OK;
}
