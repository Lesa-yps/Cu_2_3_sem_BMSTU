#include <stdio.h>
#include <stddef.h>

#include "read.h"
#include "print.h"
#include "const.h"
#include "check.h"

//main function
int main(void)
{
    int a[M_MAX][N_MAX];
    size_t m;
    size_t n;
    int k[N_MAX];
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
    for (size_t i = 0; i < n; i++)
        k[i] = check(a, m, i);
    print(k, n);
    return OK;
}
