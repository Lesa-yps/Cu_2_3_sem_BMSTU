#include "strchr.h"

char *my_strchr(const char *str, const char x);

/**
* \brief The function compares the results of work strchr and my_strchr
* \param count the current count of mismatches between the two functions
* \param arr_str the string to test the functions on
* \return int the updated count of mismatches
*/
int all_strchr(int count, char arr_str[])
{
    char *str1;
    char *str2;
    int x;
    char asc[] = "qwertyuioopasd-=+fghjkl;zxcvbnm,.?!# )(*^QWERTYUIOPASDFGLZXCVBNM[];'./,   \0";
    for (size_t i = 0; i < strlen(asc); i++)
    {
        x = asc[i];
        str1 = strchr(arr_str, x);
        str2 = my_strchr(arr_str, x);
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
* \brief The function searches for the first occurrence of a character by the asci code in the string
* \param str the string in which to search
* \param x the character to search for
* \return char* a pointer to the location of the first occurrence of the character or NULL if it is not found
*/
char *my_strchr(const char *str, const char x)
{
    char *res = NULL;
    do
    {
        if (*str == x)
        {
            res = (char *) str;
            break;
        }
    } while (*(str++));
    return res;
}
