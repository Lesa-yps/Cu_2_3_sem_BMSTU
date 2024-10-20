#include "print_arr.h"

//вывод отсортированного массива
void print_arr(struct film *films, int n)
{
    for (int i = 0; i < n; i++)
        printf("%s\n%s\n%d\n", (films[i]).title, (films[i]).name, (films[i]).year);
}
