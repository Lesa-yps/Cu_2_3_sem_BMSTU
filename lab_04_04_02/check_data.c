#include "check_data.h"

int check_day(char day[], char month[], char year[]);
int is_digit(char x[]);
int what_month(char month[]);

/**
* @brief Function that checks if the given year is a leap year.
* @param year[in] - the year to be checked
* @return 1 if the year is a leap year, otherwise 0
*/
int is_leap_year(int year)
{
    if (year % 400 == 0) {
        return 1;
    }
    if (year % 100 == 0) {
        return 0;
    }
    if (year % 4 == 0) {
        return 1;
    }
    return 0;
}

/**
* @brief Function that checks if the date is correct
* @param arr_word[in] - an array of words
* @return 1 if the date is correct, otherwise 0
*/
int check_data(char arr_word[][MAX_LEN_WORD + 1])
{
    if ((! is_digit(arr_word[2])) || (strtol(arr_word[2], NULL, 10) < 0) || (strchr(arr_word[2], '.') != NULL))
        return 0;
    if (what_month(arr_word[1]) == -1)
        return 0;
    if (! check_day(arr_word[0], arr_word[1], arr_word[2]))
        return 0;
    return 1;
}

/**
* @brief Function that checks if the given day, month, and year form a valid date.
* @param day[in] - the day of the date
* @param month[in] - the month of the date
* @param year[in] - the year of the date
* @return 1 if the date is valid, otherwise 0
*/
int check_day(char day[], char month[], char year[])
{
    int num_day;
    int num_year;
    int flag;
    if (! is_digit(day))
        return 0;
    num_day = strtol(day, NULL, 10);
    num_year = strtol(year, NULL, 10);
    if (num_day <= 0 || num_day > 31)
        return 0;
    flag = what_month(month);
    if (flag == 2 && is_leap_year(num_year) && num_day <= 29)
        return 1;
    if (flag == 2 && is_leap_year(num_year) == 0 && num_day <= 28)
        return 1;
    if (flag == 1 && num_day <= 31)
        return 1;
    if (flag == 0 && num_day <= 30)
        return 1;
    return 0;
}

/**
* @brief Function that checks if the given string consists of digits.
* @param x[in] - the string to be checked
* @return 1 if the string consists of digits, otherwise 0
*/
int is_digit(char x[])
{
    size_t i = 0;
    while (i < strlen(x))
    {
        if (x[i] < '0' || x[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

/**
* @brief Function that converts a string to lowercase
* @param x[in,out] - the string to be converted
*/
void str_lower(char x[])
{
    size_t n = strlen(x);
    for (size_t i = 0; i < n; i++)
        x[i] = tolower(x[i]);
}

/**
* @brief Function that determines the numerical value of a month given its name.
* @param x[in] - the name of the month
* @return the numerical value of the month {1; -1; 2}, -1 if the name is invalid
*/
int what_month(char x[])
{
    str_lower(x);
    if (strncmp(x, "january", MAX_LEN_WORD + 1) == 0)
        return 1;
    if (strncmp(x, "february", MAX_LEN_WORD + 1) == 0)
        return 2;
    if (strncmp(x, "march", MAX_LEN_WORD + 1) == 0)
        return 1;
    if (strncmp(x, "april", MAX_LEN_WORD + 1) == 0)
        return 0;
    if (strncmp(x, "may", MAX_LEN_WORD + 1) == 0)
        return 1;
    if (strncmp(x, "june", MAX_LEN_WORD + 1) == 0)
        return 0;
    if (strncmp(x, "july", MAX_LEN_WORD + 1) == 0)
        return 1;
    if (strncmp(x, "august", MAX_LEN_WORD + 1) == 0)
        return 1;
    if (strncmp(x, "september", MAX_LEN_WORD + 1) == 0)
        return 0;
    if (strncmp(x, "october", MAX_LEN_WORD + 1) == 0)
        return 1;
    if (strncmp(x, "november", MAX_LEN_WORD + 1) == 0)
        return 0;
    if (strncmp(x, "december", MAX_LEN_WORD + 1) == 0)
        return 1;
    return -1;
}
