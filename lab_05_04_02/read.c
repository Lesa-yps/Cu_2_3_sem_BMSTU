#include "read.h"

struct tovar read(int *err)
{
    struct tovar x;
    int b;
    *err = 0;

    printf("Input name: ");
    fgets(x.name, MAX_NAME + 1, stdin);
    if (x.name[strlen(x.name) - 1] == '\n')
        x.name[strlen(x.name) - 1] = '\0';
    else
        *err = 1;
    //printf("%d\n", *err);
    if (*err)
        return x;


    printf("Input maker: ");
    fgets(x.maker, MAX_MAKER + 1, stdin);
    if (x.maker[strlen(x.maker) - 1] == '\n')
        x.maker[strlen(x.maker) - 1] = '\0';
    else
        *err = 1;
    //printf("%d\n", *err);
    if (*err)
        return x;


    printf("Input price: ");
    if (scanf("%d", &b) != 1 || b < 0)
        *err = 1;
    else
        x.price = b;
    //printf("%d\n", *err);
    if (*err)
        return x;

    printf("Input count: ");
    if (scanf("%d", &b) != 1 || b < 0)
        *err = 1;
    else
        x.count = b;
    //printf("%d\n", *err);

    return x;
}
