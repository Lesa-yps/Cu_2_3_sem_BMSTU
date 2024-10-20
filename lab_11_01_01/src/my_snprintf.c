#include "my_snprintf.h"

// считаем количество символов в строке
int my_strlen(const char *strk)
{
    int len = 0;
    while (strk[len] != '\0')
        len++;
    return len;
}

// возводит в степень
long int my_pow(long int num, int deg)
{
    long int res = 1;
    while (deg > 0)
    {
        res *= num;
        deg--;
    }
    return res;
}

// считаем количество символов в числе
int numlen(long int num)
{
    int minus = 0;
    int k = 1;
    if (num < 0)
    {
        minus++;
        num = -num;
    }
    while ((num / ((long int)10)) != 0)
    {
        k++;
        num /= 10;
        if (num < 0)
            num = -num;
    }
    k += minus;
    return k;
}

// записывает символ в буфер со всеми проверками
void print_char_to_str(char *s, char a, size_t size, int *count_write_all, int *count_write_real)
{
    if (((int)size > *count_write_real) && (s != NULL))
    {
        s[*count_write_real] = a;
        (*count_write_real)++;
        if ((int)size == *count_write_real)
            s[*count_write_real - 1] = '\0';
    }
    (*count_write_all)++;
}

// записывает число в буфер
void write_num_to_s(char *s, long int num, size_t size, int *count_write_all, int *count_write_real)
{
    // считаем количество символов в числе
    int k = numlen(num);
    int alpha;
    // заполнили первый символ нового числа (-/0)
    if (num < 0)
    {
        print_char_to_str(s, '-', size, count_write_all, count_write_real);
        num *= -1;
        k--;
    }
    // преобразуем число по символам в строку
    k--;
    for (; k >= 0; k--)
    {
        alpha = num / my_pow(10, k);
        num %= my_pow(10, k);
        if (num < 0)
        {
            alpha = -alpha;
            num = -num;
        }
        print_char_to_str(s, '0' + alpha, size, count_write_all, count_write_real);
    }
}

// записывает строку в буфер
void write_str_to_s(char *s, char *str_write_now, size_t size, int *count_write_all, int *count_write_real)
{
    int i = 0;
    while (str_write_now[i] != '\0')
    {
        print_char_to_str(s, str_write_now[i], size, count_write_all, count_write_real);
        i++;
    }
}

// главная функция моя реализация snprintf для %s и %ld
int my_snprintf(char *s, size_t size, const char *format, ...)
{
    // бежит по s
    int count_write_all = 0;
    int count_write_real = 0;
    int format_len = my_strlen(format);
    va_list vl;
    va_start(vl, format);
    
    // бежит по формату
    int i = 0;
    while (i < format_len)
    {
        char x = format[i];
        char *str_write_now;
        long int num_write_now;
        // встретили %s
        if (x == '%' && (i + 1) < format_len && format[i + 1] == 's')
        {
            str_write_now = va_arg(vl, char *);
            write_str_to_s(s, str_write_now, size, &count_write_all, &count_write_real);
            i += 1;
        }
        // встретили %ld
        else if (x == '%' && (i + 2) < format_len && format[i + 1] == 'l' && (format[i + 2] == 'd'))
        {
            num_write_now = va_arg(vl, long);
            write_num_to_s(s, num_write_now, size, &count_write_all, &count_write_real);
            i += 2;
        }
        // иначе просто записали этот символ в буфер
        else
            print_char_to_str(s, x, size, &count_write_all, &count_write_real);
        i++;
    }
    // добавили в буфер завершающий символ
    print_char_to_str(s, '\0', size, &count_write_all, &count_write_real);
    count_write_all--;

    va_end(vl);
    
    // вернули сколько символов нужно для записи в буфере (влезло ли в size не важно)
    return count_write_all;
}
