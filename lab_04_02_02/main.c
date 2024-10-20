#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "array_of_words.h"
#include "const.h"
#include "finding.h"
#include "read.h"

//main function
int main(void)
{
    char arr_str1[MAX_LEN_STR + 1];
    char arr_str2[MAX_LEN_STR + 1];
    size_t n;
    size_t m;
    char arr_word1[MAX_LEN_STR + 1][MAX_LEN_WORD + 1];
    char arr_word2[MAX_LEN_STR + 1][MAX_LEN_WORD + 1];
    size_t m_w;
    size_t n_w;
    int rc;

    //reading
    rc = reading(arr_str1);
    if (rc == ERR)
    {
        printf("ERROR: with reading first string.\n");
        return ERR_1;
    }
    if (rc == ERR_LEN_STR)
    {
        printf("ERROR: too big first string.\n");
        return ERR_BIG_1;
    }
    rc = reading(arr_str2);
    if (rc == ERR)
    {
        printf("ERROR: with reading second string.\n");
        return ERR_2;
    }
    if (rc == ERR_LEN_STR)
    {
        printf("ERROR: too big second string.\n");
        return ERR_BIG_2;
    }

    n = strlen(arr_str1);
    m = strlen(arr_str2);

    //string -> words
    n_w = array_of_words(arr_word1, arr_str1, n);
    if ((int)n_w == ERR_LEN_WORD)
    {
        printf("ERROR: too big word in first string.\n");
        return ERR_WORD_1;
    }
    m_w = array_of_words(arr_word2, arr_str2, m);
    if ((int)m_w == ERR_LEN_WORD)
    {
        printf("ERROR: too big word in second string.\n");
        return ERR_WORD_2;
    }

    //find
    finding(arr_word1, arr_word2, n_w, m_w);

    return OK;
}
