#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "array_of_words.h"
#include "const.h"
#include "read.h"
#include "del_sym.h"

//main function
int main(void)
{
    char arr_str[MAX_LEN_STR + 1];
    char arr_word[MAX_LEN_STR + 1][MAX_LEN_WORD + 1];
    memset(arr_word, 0, sizeof(arr_word));
    size_t n_w;
    char rev_str[MAX_LEN_STR + 1];
    memset(rev_str, 0, sizeof(rev_str));
    int rc;

    //reading
    rc = reading(arr_str);
    if (rc == ERR)
    {
        printf("ERROR: with reading string.\n");
        return ERR;
    }
    if (rc == ERR_LEN_STR)
    {
        printf("ERROR: too big string.\n");
        return ERR_BIG;
    }

    //string -> words
    n_w = array_of_words(arr_word, arr_str);
    if ((int)n_w == ERR_LEN_WORD)
    {
        printf("ERROR: too big word in string.\n");
        return ERR_WORD;
    }

    //make new string + del > 1 + return (del last)
    for (long long int i = n_w - 2; i >= 0; i--)
        if (strncmp(arr_word[i], arr_word[n_w - 1], MAX_LEN_WORD + 1) != 0)
        {
            strcat(rev_str, del_sym(arr_word[i]));
            rev_str[strlen(rev_str)] = ' ';
        }
    rev_str[strlen(rev_str) - 1] = '\0';
    if (rev_str[0] == '\0')
        printf("String is empty.\n");
    else
        printf("Result: %s\n", rev_str);
    return OK;
}
