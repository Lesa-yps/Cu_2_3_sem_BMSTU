#include "array_of_words.h"

//the function perform string to array of words
size_t array_of_words(char arr_word[][MAX_LEN_WORD + 1], char arr_str[MAX_LEN_WORD + 1], size_t j)
{
    size_t k = 0;
    int flag = 0;
    size_t n = strlen(arr_str);
    for (size_t i = 0; i < n; i++)
    {
        if (j == 0)
        {
            if (! isspace((int) arr_str[i]) && arr_str[i] >= '0' && arr_str[i] <= '9')
            {
                flag = 1;
                if (k >= MAX_LEN_WORD)
                    return ERR_LEN_WORD;
                arr_word[j][k++] = arr_str[i];
            }
            else if ((flag && isspace((int) arr_str[i]))\
                || (! isspace((int) arr_str[i]) && (arr_str[i] < '0' || arr_str[i] > '9')))
            {
                flag = 0;
                arr_word[j][k] = '\0';
                k = 0;
                j++;
            }
        }
        if (j == 1)
        {
            if (! isspace((int) arr_str[i]) && (arr_str[i] < '0' || arr_str[i] > '9'))
            {
                flag = 1;
                if (k >= MAX_LEN_WORD)
                    return ERR_LEN_WORD;
                arr_word[j][k++] = arr_str[i];
            }
            else if ((flag && isspace((int) arr_str[i]))\
                || (! isspace((int) arr_str[i]) && arr_str[i] >= '0' && arr_str[i] <= '9'))
            {
                flag = 0;
                arr_word[j][k] = '\0';
                k = 0;
                j++;
            }
        }
        if (j == 2)
        {
            if (! isspace((int) arr_str[i]) && arr_str[i] >= '0' && arr_str[i] <= '9')
            {
                flag = 1;
                if (k >= MAX_LEN_WORD)
                    return ERR_LEN_WORD;
                arr_word[j][k++] = arr_str[i];
            }
            else if ((flag && isspace((int) arr_str[i]))\
                || (! isspace((int) arr_str[i]) && (arr_str[i] < '0' || arr_str[i] > '9')))
            {
                flag = 0;
                arr_word[j][k] = '\0';
                k = 0;
                j++;
            }
        }
        if (j == 3)
            if (! isspace((int) arr_str[i]))
                return j + 1;
    }
    return j;
}
