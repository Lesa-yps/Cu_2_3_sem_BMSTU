/**
 * @file array_of_words.h
 *
 * @brief This is a module that splits a string into words.
 * Manual implementation.
 */

#ifndef ARRAY_OF_WORDS_H
#define ARRAY_OF_WORDS_H

#include "const.h"

#include <stddef.h>
#include <string.h>

/**
 * @brief This function splits a string into words.
 *
 * This function takes a string argument and splits it into words. Words are
 * defined as substrings of the input string separated by whitespace characters
 * (space, tab, newline, etc.). The words are stored in the two-dimensional
 * character array arr_word. The maximum length of a word is defined as
 * MAX_LEN_WORD.
 *
 * @param arr_word The two-dimensional character array in which to store the words.
 * @param arr_str The input string to split into words.
 * @param n The maximum number of words to store in arr_word.
 * @return The number of words stored in arr_word.
 */

size_t array_of_words(char arr_word[][MAX_LEN_WORD + 1], char arr_str[MAX_LEN_WORD + 1], size_t n);

#endif // ARRAY_OF_WORDS_H
