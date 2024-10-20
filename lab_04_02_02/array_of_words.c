#include "array_of_words.h"

size_t array_of_words(char arr_word[][MAX_LEN_WORD + 1], char arr_str[MAX_LEN_WORD + 1], size_t n)
{
    size_t n_w = 0;
    size_t j = 0;
    int flag = 0;
    for (size_t i = 0; i < n; i++)
    {
        if ((! strchr(",;: -.!?  ", arr_str[i])) && (arr_str[i] != '\n'))
        {
            if (j == 0 && flag)
                n_w ++;
            if (j > MAX_LEN_WORD)
                return ERR_LEN_WORD;
            arr_word[n_w][j++] = arr_str[i];
        }
        else if (j != 0)
        {
            flag = 1;
            arr_word[n_w][j] = '\0';
            j = 0;
        }
    }
    if (j != 0)
        arr_word[n_w][j] = '\0';
    return n_w + 1;
}
