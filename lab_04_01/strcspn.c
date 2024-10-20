#include "strcspn.h"

size_t my_strcspn(char str[], char symbols[]);

/**
* \brief The function compares the results of work strcspn and my_strcspn
* \param count the current count of mismatches between the two functions
* \param arr_str the string to test the functions on
* \return int the updated count of mismatches
*/
int all_strcspn(int count, char arr_str[])
{
    size_t str1;
    size_t str2;
    str1 = strcspn(arr_str, "123abc");
    str2 = my_strcspn(arr_str, "123abc");
    if (str1 != str2)
        count += 1;
    return count;
}

/**
* \brief The function determines the maximum length of a section of a string that does not contain characters from argument 2
* \param str the string to search
* \param symbols the set of characters to search for in the string
* \return size_t the length of the maximum section of the string that does not contain any character from argument 2
*/
size_t my_strcspn(char str[], char symbols[])
{
    size_t n = strlen(str);
    size_t m = strlen(symbols);
    size_t res = 0;
    int flag;
    for (size_t i = 0; i < n; i++)
    {
        flag = 0;
        for (size_t j = 0; j < m; j++)
            if (str[i] == symbols[j])
            {
                flag = 1;
                break;
            }
        if (flag)
            break;
        res += 1;
    }
    return res;
}

