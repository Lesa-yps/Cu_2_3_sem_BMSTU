#ifndef POS_H
#define POS_H

/**
    * @file pos.h
    * @brief Get and put struct by position in file.
    */

#include <stdio.h>

#include "const&struct.h"

/**
    * @brief Get struct by position from file.
    *
    * @param file_in A pointer to the input text file.
    * @param file_out A pointer to the output text file.
    * @return void This function does not return a value.
    */
struct tovar get_by_pos(FILE *file, long int i, int *err);

/**
    * @brief Put struct by position to file.
    *
    * @param file A pointer to the file.
    * @param i The position to write the item to.
    * @param x The item to write.
    * @return void This function does not return a value.
    */
void put_by_pos(FILE *file, long int i, struct tovar x);

#endif // POS_H
