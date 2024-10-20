#include "strpbrk.h"

char *my_strpbrk(char str[], char symbols[]);

/**
* \brief The function compares the results of work strpbrk and my_strpbrk
* \param count the current count of mismatches between the two functions
* \param arr_str the string to test the functions on
* \return int the updated count of mismatches
*/
int all_strpbrk(int count, char arr_str[])
{
    char *str1;
    char *str2;
    str1 = strpbrk(arr_str, "abc123");
    str2 = my_strpbrk(arr_str, "abc123");
    if (str1 == NULL && str2 == NULL)
        count += 0;
    else if (str1 == NULL || str2 == NULL)
        count += 1;
    else if (strncmp(str1, str2, MAX_LEN) != 0)
        count += 1;
    return count;
}

/**
* \brief The function looks for the first occurrence of one of the characters from the string in argument 2
* \param str the string in which to search
* \param symbols the set of characters to search for in the string
* \return char* a pointer to the location of the first occurrence of a character from argument 2 or NULL if it is not found
*/
char *my_strpbrk(char str[], char symbols[])
{
    size_t n = strlen(str);
    size_t m = strlen(symbols);
    char *res = NULL;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
            if (str[i] == symbols[j])
            {
                res = &str[i];
                break;
            }
        if (res != NULL)
            break;
    }
    return res;
}
