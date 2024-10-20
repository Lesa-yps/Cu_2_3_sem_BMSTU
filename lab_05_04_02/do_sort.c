#include "do_sort.h"

/*void print(FILE *file)
{
    printf("Vot:\n");
    struct tovar x;
    fseek(file, 0, SEEK_SET);
    while (fread(&x, sizeof(struct tovar), 1, file) == 1)
        printf("%s %s %u %u\n", x.name, x.maker, x.price, x.count);
}*/

void do_sort(FILE *file_in, FILE *file_out)
{
    struct tovar x;
    struct tovar y;
    int flag;
    int err;
    long int n = 0;

    while (fread(&x, sizeof(struct tovar), 1, file_in) == 1)
    {
        //printf("%ld\n", n);
        fwrite(&x, sizeof(struct tovar), 1, file_out);
        n++;
    }

    for (long int i = 0; i < (n - 1); i++)
    {
        flag = 1;
        for (long int j = 0; j < (n - 1); j++)
        {
            x = get_by_pos(file_out, j, &err);
            y = get_by_pos(file_out, j + 1, &err);
            if ((x.price < y.price) || ((x.price == y.price) && (x.count < y.count)))
            {
                flag = 0;
                put_by_pos(file_out, j + 1, x);
                put_by_pos(file_out, j, y);
            }
        }
        if (flag)
            break;
    }
}
