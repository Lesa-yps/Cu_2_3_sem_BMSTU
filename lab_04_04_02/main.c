#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "array_of_words.h"
#include "const.h"
#include "read.h"
#include "check_data.h"

//main function
int main(void)
{
    char arr_str[MAX_LEN_STR + 1];
    char arr_word[LEN_DATA][MAX_LEN_WORD + 1];
    memset(arr_word, 0, sizeof(arr_word));
    size_t n_w = 0;
    int rc;

    while ((rc = reading(arr_str)) == 0)
        n_w = array_of_words(arr_word, arr_str, n_w);

    if (n_w != LEN_DATA)
    {
        if (rc == ERR_LEN_STR)
            return ERR_LEN_STR;
        if ((int)n_w == ERR_LEN_WORD)
            return ERR_LEN_WORD;
        printf("NO");
        return OK;
    }

    //check data and print result
    if (check_data(arr_word))
        printf("YES");
    else
        printf("NO");
    return OK;
}
