#include "print_arr.h"

//вывод отсортированного массива
void print_arr(FILE *file, struct film *films, size_t n)
{
    for (size_t i = 0; i < n; i++)
        fprintf(file, "%s\n%s\n%d\n", (films[i]).title, (films[i]).name, (films[i]).year);
}
