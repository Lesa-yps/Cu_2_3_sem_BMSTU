/**
 * @file finding.h
 *
 * @brief This is a module that finds words that appear in both input arrays.
 */

#ifndef FINDING_H
#define FINDING_H

#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "const.h"

/**
 * @brief This function finds words that appear in both input arrays.
 *
 * This function takes two two-dimensional character arrays, arr_word1 and
 * arr_word2, and searches for words that appear in both arrays. The maximum
 * length of a word is defined as MAX_LEN_WORD. The function prints the words
 * that appear in both arrays, followed by "yes" if the word appears in both
 * arrays and "no" otherwise.
 *
 * @param arr_word1 The first two-dimensional character array to search.
 * @param arr_word2 The second two-dimensional character array to search.
 * @param n_w The number of words in arr_word1.
 * @param m_w The number of words in arr_word2.
 */
void finding(char arr_word1[][MAX_LEN_WORD + 1], char arr_word2[][MAX_LEN_WORD + 1], size_t n_w, size_t m_w);

#endif // FINDING_H
