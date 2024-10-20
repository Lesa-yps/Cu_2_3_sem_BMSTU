#include "do_add_txt.h"

/*void print_txt(FILE *file)
{
    printf("Vot_txt:\n");
    struct tovar x;
    fseek(file, 0, SEEK_SET);
    while (fscanf(file, "%s%s%u%u", x.name, x.maker, &(x.price), &(x.count)) == 4)
        printf("%s %s %u %u\n", x.name, x.maker, x.price, x.count);
}*/

int do_add_txt(FILE *file_in)
{
    struct tovar y;
    struct tovar arr[MAX_STRUCT];
    long int i = 0;
    long int n = 0;
    int err;
    struct tovar x = read(&err);

    if (err == 1)
        return ERR_READ;

    while (fscanf(file_in, "%s%s%u%u", arr[n].name, \
    arr[n].maker, &(arr[n].price), &(arr[n].count)) == 4)
        n++;
    fseek(file_in, 0, SEEK_SET);
    if (n == 10)
        return ERR_N;

    while ((x.price < arr[i].price) || ((x.price == arr[i].price) \
        && (x.count < arr[i].count)))
    {
        i++;
        if (i == n)
            break;
    }

    for (long int j = i; j < n; j++)
    {
        y = arr[j];
        arr[j] = x;
        x = y;
    }
    arr[n] = x;
    for (long int j = 0; j <= n; j++)
        fprintf(file_in, "%s\n%s\n%u\n%u\n", arr[j].name, \
        arr[j].maker, arr[j].price, arr[j].count);
    return OK;
}
