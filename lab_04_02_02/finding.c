#include "finding.h"

//find the same words in 2 string
void finding(char arr_word1[][MAX_LEN_WORD + 1], char arr_word2[][MAX_LEN_WORD + 1], size_t n_w, size_t m_w)
{
    printf("Result: ");
    int flag;
    for (size_t i = 0; i < n_w; i++)
    {
        flag = 0;
        for (long int j = (i - 1); j >= 0; j--)
            if (strncmp(arr_word1[i], arr_word1[j], MAX_LEN_WORD + 1) == 0)
            {
                flag = 1;
                break;
            }
        if (flag)
            continue;
        printf("%s ", arr_word1[i]);
        for (size_t k = 0; k < m_w; k++)
        {
            if (strncmp(arr_word1[i], arr_word2[k], MAX_LEN_WORD + 1) == 0)
            {
                flag = 1;
                printf("yes\n");
                break;
            }
        }
        if (! flag)
            printf("no\n");
    }
}
