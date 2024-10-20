#include "del_sym.h"

//function del first symbol in all world > 1
char *del_sym(char x[])
{
    size_t n = strlen(x);
    size_t i = 1;
    size_t k = 0;
    char deling;
    while (! isalpha(x[k]))
    {
        k++;
        if (k == n)
            return x;
    }
    deling = x[k];
    while (i < n)
    {
        if (x[i] == deling)
        {
            for (size_t j = i; j < (n - 1); j++)
                x[j] = x[j + 1];
            x[--n] = '\0';
            i--;
        }
        i++;
    }
    return x;
}
