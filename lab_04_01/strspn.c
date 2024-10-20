#include "strspn.h"

size_t my_strspn(char str[], char symbols[]);

/**
* \brief The function compares the results of work strspn and my_strspn
* \param count the current count of mismatches between the two functions
* \param arr_str the string to test the functions on
* \return int the updated count of mismatches
*/
int all_strspn(int count, char arr_str[])
{
    size_t str1;
    size_t str2;
    str1 = strspn(arr_str, "abc123");
    str2 = my_strspn(arr_str, "abc123");
    if (str1 != str2)
        count += 1;
    return count;
}

/**
* \brief The function determines the maximum length of the section of the string consisting only of the characters of the argument string 2
* \param str the string to search
* \param symbols the set of characters to search for in the string
* \return size_t the length of the maximum section of the string that consists only of characters from argument 2
*/
size_t my_strspn(char str[], char symbols[])
{
    size_t n = strlen(str);
    size_t m = strlen(symbols);
    size_t res = 0;
    int flag;
    for (size_t i = 0; i < n; i++)
    {
        flag = 1;
        for (size_t j = 0; j < m; j++)
            if (str[i] == symbols[j])
            {
                res += 1;
                flag = 0;
                break;
            }
        if (flag)
            break;
    }
    return res;
}
