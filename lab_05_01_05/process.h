#ifndef PROCESS_H
#define PROCESS_H

#include <stdio.h>
#include <limits.h>

#include "const.h"

/**
     * @brief Функция возвращает максимальное количество идущих
     *  подряд одинаковых элементов вводимой последовательности целых чисел.
     *
     * Если последовательность пуста, выводится сообщение об ошибке и возвращается код EMPTY.
     *
     * @param stdin Файловый поток стандартного ввода.
     * @param count Счетчик элементов последовательности.
     *
     * @return int Код возврата.
     */

int process(FILE *file, long long int *count);

#endif // PROCESS_H
