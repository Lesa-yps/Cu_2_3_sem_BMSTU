#include "array_of_words.h"

//the function perform string to array of words
size_t array_of_words(char arr_word[][MAX_LEN_WORD + 1], char arr_str[MAX_LEN_WORD + 1])
{
    size_t j = 0;
    char *help_str = strtok(arr_str, ",;: -.!?	");
    while (help_str != NULL)
    {
        if (strlen(help_str) > MAX_LEN_WORD)
            return ERR_LEN_WORD;
        if (strlen(help_str) > 0 && help_str[0] != '\n')
        {
            if (help_str[strlen(help_str) - 1] == '\n')
                strncpy(arr_word[j++], help_str, strlen(help_str) - 1);
            else
                strcpy(arr_word[j++], help_str);
        }
        help_str = strtok(NULL, ",; :-.!?	");
    }
    return j;
}
