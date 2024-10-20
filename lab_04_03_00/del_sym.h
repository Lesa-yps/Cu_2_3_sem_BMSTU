/**
 * @file del_sym.h
 *
 * @brief This is a module that removes all subsequent occurrences of the first character.
 */

#ifndef PRINT_H
#define PRINT_H

#include <string.h>
#include <stddef.h>
#include <ctype.h>

/**
 * @brief Function that removes all subsequent occurrences of the first character.
 * @param x[in] - a string to be processed
 * @return the processed string
 */
char *del_sym(char x[]);

#endif // PRINT_H
