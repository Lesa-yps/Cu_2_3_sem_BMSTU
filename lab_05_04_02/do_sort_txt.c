#include "do_sort_txt.h"

/*void print_txt(FILE *file)
{
    printf("Vot_txt:\n");
    struct tovar x;
    fseek(file, 0, SEEK_SET);
    while (fscanf(file, "%s%s%u%u", x.name, x.maker, &(x.price), &(x.count)) == 4)
        printf("%s %s %u %u\n", x.name, x.maker, x.price, x.count);
}*/

void do_sort_txt(FILE *file_in, FILE *file_out)
{
    struct tovar x;
    int flag;
    long int n = 0;
    struct tovar arr[MAX_STRUCT];

    while (fscanf(file_in, "%s%s%u%u", arr[n].name, \
    arr[n].maker, &(arr[n].price), &(arr[n].count)) == 4)
        n++;

    for (long int i = 0; i < (n - 1); i++)
    {
        flag = 1;
        for (long int j = 0; j < (n - 1); j++)
        {
            if ((arr[j].price < arr[j + 1].price) || ((arr[j].price == arr[j + 1].price) \
                && (arr[j].count < arr[j + 1].count)))
            {
                flag = 0;
                x = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = x;
            }
        }
        if (flag)
            break;
    }

    for (long int i = 0; i < n; i++)
        fprintf(file_out, "%s\n%s\n%u\n%u\n", arr[i].name, arr[i].maker, arr[i].price, arr[i].count);
}
