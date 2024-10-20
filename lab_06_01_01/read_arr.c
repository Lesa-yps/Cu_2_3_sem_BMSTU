#include "read_arr.h"

//чтение года
int read_year(FILE *file, int *year);
//чтение строки
int read_str(char *str, FILE *file);

//вставка элемента на нужное место в массиве (сортировка после ввода каждого элемента)
void input_sort(int n, char *what, struct film one, struct film *films);

//функция читает информацию о фильмах из файла
int read_arr(FILE *file, struct film *films, int *n, char *what)
{
    //проверка на корректность поля поиска
    if ((strcmp(what, "title") * strcmp(what, "name") * strcmp(what, "year")) != 0)
        return ERROR;

    int rc = OK;
    int rc2;
    int rc_func;
    int finish = 0;
    struct film one;
    //количество структур
    *n = 0;
    //пока не ошибка и не конец структур
    while ((! rc) && (! finish))
    {
        //чтение названия
        rc_func = read_str(one.title, file);
        //структуры кончились
        if (rc_func == MY_ERROR)
        {
            finish = 1;
            continue;
        }
        //ошибка чтения названия
        else if (rc_func == ERROR)
            rc = ERROR;

        //чтение амени автора
        rc_func = read_str(one.name, file);
        //ошибка чтения имени автора
        if (rc_func != OK)
            rc = ERROR;

        //чтение года
        rc2 = read_year(file, &one.year);
        //ошибка чтения года
        if (rc2 == ERROR)
            rc = ERROR;

        //если прочитано слишком много
        if (*n == MAX_COUNT)
            rc = ERROR;
        //если ошибок не было
        else if (! rc)
        {
            //вставляем считанный элемент на верное место в массив (сортировка)
            input_sort(*n, what, one, films);
            //увеличиваем количество элементов в массиве
            (*n)++;
        }
    }
    //если файл пуст у него в конце несколько пустых строк - ошибка
    if ((*n == 0) || (fgetc(file) == '\n'))
        rc = ERROR;
    //вернули код ошибки
    return rc;
}

//чтение года
int read_year(FILE *file, int *year)
{
    int rc = OK;
    //прочитали символ
    char a = fgetc(file);
    //обозначает что хоть одну цифру прочитали
    int flag = 1;
    *year = 0;
    // пока символ - цифра
    while (isdigit(a))
    {
        flag = 0;
        //добавляем её к году
        *year = (a - '0') + *year * 10;
        //считали символ
        a = fgetc(file);
    }
    //если не прочитали ни одной цифры или последний считанный символ - не конец файла или перевод строки - ошибка
    if (flag || (! ((a == '\n') || (a == EOF))))
        rc = ERROR;
    //вернули код ошибки
    return rc;
}

//чтение строки
int read_str(char *str, FILE *file)
{
    //код ошибки
    int rc = OK;
    //если не конец файла, иначе код возврата MY_ERROR
    if (fgets(str, MAX_LEN + 1, file) != NULL)
    {
        //мы хоть что-то прочитали, иначе ошибка
        if (strlen(str) > 1)
        {
            //прочитали всю строчку до переноса строки и  заменяем его на конец строки "\0", иначе ошибка
            if (str[strlen(str) - 1] == '\n')
                str[strlen(str) - 1] = '\0';
            else
                rc = ERROR;
        }
        else
            rc = MY_ERROR;
    }
    else
        rc = MY_ERROR;
    //вернули код ошибки
    return rc;
}

//функция сравнивает переданные структуры по переданному полю
//работает аналогично strcmp
int struct_strcmp(char *what, struct film film1, struct film film2)
{
    int res = 0;
    if (strcmp(what, "title") == 0)
        res = strcmp(film1.title, film2.title);
    if (strcmp(what, "name") == 0)
        res = strcmp(film1.name, film2.name);
    if (strcmp(what, "year") == 0)
        res = film1.year - film2.year;
    return res;
}

//обмен структур
void swap(struct film *one, struct film *two)
{
    struct film help = *one;
    *one = *two;
    *two = help;
}

//вставляем считанный элемент на верное место в массив (сортировка)
void input_sort(int n, char *what, struct film one, struct film *films)
{
    for (int j = 0; j < n; j++)
    {
        //доходим до первого элемента большего вставляемого и вставляем,
        //а остальные элементы массива сдвигаем на 1 вправо
        if (struct_strcmp(what, one, films[j]) < 0)
            swap(&one, films + j);
    }
    films[n] = one;
}
