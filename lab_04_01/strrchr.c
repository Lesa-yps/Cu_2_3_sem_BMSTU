#include "strrchr.h"

char *my_strrchr(const char *str, const char x);

/**
* \brief The function compares the results of work strchr and my_strrchr
* \param count the current count of mismatches between the two functions
* \param arr_str the string to test the functions on
* \return int the updated count of mismatches
*/
int all_strrchr(int count, char arr_str[])
{
    char *str1;
    char *str2;
    int x;
    char asc[] = "qwertyuioopasd-=+fghjkl;zxcvbnm,.?!# )(*^QWERTYUIOPASDFGLZXCVBNM[];'./,   \0";
    for (size_t i = 0; i < strlen(asc); i++)
    {
        x = asc[i];
        str1 = strrchr(arr_str, x);
        str2 = my_strrchr(arr_str, x);
        if (str1 == NULL && str2 == NULL)
            count += 0;
        else if (str1 == NULL || str2 == NULL)
            count += 1;
        else if (strncmp(str1, str2, MAX_LEN) != 0)
            count += 1;
    }
    return count;
}

/**
* \brief The function looks for the last occurrence of a character by its asci code in a string
* \param str the string in which to search
* \param x the character to search for
* \return char* a pointer to the location of the last occurrence of the character or NULL if it is not found
*/
char *my_strrchr(const char *str, const char x)
{
    char *res = NULL;
    do
    {
        if (*str == x)
            res = (char *) str;
    } while (*(str++));
    return res;
}
