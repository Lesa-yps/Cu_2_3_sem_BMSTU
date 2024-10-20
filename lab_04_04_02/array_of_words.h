/**
 * @file array_of_words.h
 *
 * @brief This is a module that splits a string into words.
 * Automatic implementation.
 */

#ifndef ARRAY_OF_WORDS_H
#define ARRAY_OF_WORDS_H

#include "const.h"

#include <stddef.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief Function that converts a string to an array of words
 * @param arr_word[in] - an array of words
 * @param arr_str[in] - a string to be converted
 * @return the number of words
 */
size_t array_of_words(char arr_word[][MAX_LEN_WORD + 1], char arr_str[MAX_LEN_WORD + 1], size_t j);

#endif // ARRAY_OF_WORDS_H
