#include <stdio.h>
#include <stddef.h>

#include "chooser.h"
#include "read.h"
#include "const.h"

//main function
int main(void)
{
    int a[M_MAX][M_MAX];
    size_t m;
    int res;
    int x = read(a, &m);
    if (x != OK)
    {
        if (x == ERR_SIZE)
            printf("Error with scanf size of list.\n");
        if (x == ERR_ELEM)
            printf("Error with scanf elem.\n");
        return x;
    }
    res = chooser(a, m);
    if (res == 10)
    {
        printf("Error: element not found.\n");
        return NO;
    }
    printf("Result: %d\n", res);
    return OK;
}
