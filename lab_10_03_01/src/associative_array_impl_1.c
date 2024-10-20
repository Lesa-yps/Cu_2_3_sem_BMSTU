#define _POSIX_C_SOURCE 200809L

#include "associative_array.h"

#include <stdlib.h>
#include <string.h>

// односвязный список

typedef struct node node_t;

// структура - элемент односвязного списка
struct node
{
    char *key;    // ключ - строка
    int value;    // значение - целое число
    node_t *next; // указатель на следующий элемент
};

struct assoc_array_type
{
    node_t *head;
};

/**
 * Тип ассоциативный массив: ключ - строка, значение - целое число.
 *
 * Ключ не может быть пустой строкой.
 */

/**
 * Удаляет объект ассоциативный массив.
 *
 * \param[in,out] arr - описатель массив
 *
 * После вызова этой функции переменная, переданная в качестве параметра, имеет
 * значение NULL.
 */
void assoc_array_destroy(assoc_array_t *arr)
{
    if (arr == NULL || *arr == NULL)
        return;
    assoc_array_clear(*arr);
    free(*arr);
    *arr = NULL;
}

/**
 * Создает объект ассоциативный массив.
 *
 * \return Созданный объект или NULL
 */
// создание одного элемента односвязного списка (+ выделение памяти)
int create_one(node_t **head, const char *str, int val)
{
    int rc = ASSOC_ARRAY_OK;
    node_t *one_node = calloc(1, sizeof(node_t));
    if (one_node == NULL)
        rc = ASSOC_ARRAY_MEM;
    else
    {
        one_node->key = strdup(str);
        if (one_node->key == NULL)
        {
            free(one_node);
            rc = ASSOC_ARRAY_MEM;
        }
        else
        {
            one_node->value = val;
            one_node->next = NULL;
            *head = one_node;
        }
    }
    return rc;
}

assoc_array_t assoc_array_create(void)
{
    assoc_array_t struct_head = calloc(1, sizeof(struct assoc_array_type));
    if (struct_head != NULL)
    {
        struct_head->head = NULL;
    }
    return struct_head;
}

/**
 * Добавляе пару "ключ-значение" в ассоциативный массив.
 *
 * \param[in,out] arr - описатель массива
 * \param[in] key - ключ
 * \param[in] num - значение
 *
 * \note Ключ не может быть пустой строкой.
 *
 * \return ASSOC_ARRAY_OK или код ошибки (ASSOC_ARRAY_INVALID_PARAM, ASSOC_ARRAY_MEM, ASSOC_ARRAY_KEY_EXISTS)
 */
assoc_array_error_t assoc_array_insert(assoc_array_t arr, const char *key, int num)
{
    int rc = ASSOC_ARRAY_OK;

    if (key == NULL || key[0] == '\0' || arr == NULL)
        rc = ASSOC_ARRAY_INVALID_PARAM;
    else
    {
        node_t *current = arr->head;
        node_t *prev = NULL;
        while (current && (!rc))
        {
            if (strcmp(current->key, key) == 0)
                rc = ASSOC_ARRAY_KEY_EXISTS;
            else
            {
                prev = current;
                current = current->next;
            }
        }
        if (!rc)
        {
            node_t *tmp;
            rc = create_one(&tmp, key, num);
            if (!rc)
            {
                if (!arr->head)
                    arr->head = tmp;
                else
                    prev->next = tmp;
            }
        }
    }
    return rc;
}

/**
 * Возвращает значение по ключу.
 *
 * \param[in] arr - описатель массива
 * \param[in] key - ключ
 * \param[out] num - указатель на значение, соответствующее ключу (в случае успеха)
 *
 * \note Ключ не может быть пустой строкой.
 *
 * \return ASSOC_ARRAY_OK или код ошибки (ASSOC_ARRAY_INVALID_PARAM, ASSOC_ARRAY_NOT_FOUND)
 */
assoc_array_error_t assoc_array_find(const assoc_array_t arr, const char *key, int **num)
{
    int rc = ASSOC_ARRAY_NOT_FOUND;
    if (key == NULL || key[0] == '\0' || arr == NULL || num == NULL)
        rc = ASSOC_ARRAY_INVALID_PARAM;
    else
    {
        node_t *current = (arr->head);
        while (current && rc)
        {
            if (strcmp(current->key, key) == 0)
            {
                *num = &current->value;
                rc = ASSOC_ARRAY_OK;
            }
            else
                current = current->next;
        }
    }
    return rc;
}

/**
 * Удаляет значение по ключу.
 *
 * \param[in,out] arr - описатель массива
 * \param[in] key - ключ
 *
 * \return ASSOC_ARRAY_OK или код ошибки (ASSOC_ARRAY_INVALID_PARAM, ASSOC_ARRAY_MEM, ASSOC_ARRAY_NOT_FOUND)
 */
assoc_array_error_t assoc_array_remove(assoc_array_t arr, const char *key)
{
    int rc = ASSOC_ARRAY_NOT_FOUND;
    if (key == NULL || key[0] == '\0' || arr == NULL)
        rc = ASSOC_ARRAY_INVALID_PARAM;
    else
    {
        node_t *current = (arr->head);
        node_t *prev = NULL;
        while (current && rc)
        {
            if (strcmp(current->key, key) == 0)
            {
                if (arr->head == current)
                    arr->head = current->next;
                else
                    prev->next = current->next;
                free(current->key);
                free(current);
                rc = ASSOC_ARRAY_OK;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
    }
    return rc;
}

/**
 * Очищает ассоциативный массив (т.е. массив становится пустым).
 *
 * \param[in,out] arr - описатель массива
 *
 * \return ASSOC_ARRAY_OK или код ошибки (ASSOC_ARRAY_INVALID_PARAM)
 */
assoc_array_error_t assoc_array_clear(assoc_array_t arr)
{
    int rc = ASSOC_ARRAY_OK;
    if (arr == NULL)
        rc = ASSOC_ARRAY_INVALID_PARAM;
    else
    {
        node_t *current = (arr->head);
        node_t *tmp;
        while (current != NULL)
        {
            tmp = current->next;
            free(current->key);
            free(current);
            current = tmp;
        }
        arr->head = NULL;
    }
    return rc;
}

/**
 * Применяет к значениям указанное действие.
 *
 * \param[in] arr - описатель массива
 * \param[in] action - указатель на функцию обратного вызова для обработки очередного значения
 * \param[in] param - параметр функции обратного вызова (может быть NULL)
 *
 * \return ASSOC_ARRAY_OK или код ошибки (ASSOC_ARRAY_INVALID_PARAM)
 */
assoc_array_error_t assoc_array_each(const assoc_array_t arr, void (*action)(const char *key, int *num, void *param), void *param)
{
    int rc = ASSOC_ARRAY_OK;
    if (arr == NULL || action == NULL)
        rc = ASSOC_ARRAY_INVALID_PARAM;
    else
    {
        node_t *current = (arr->head);
        node_t *tmp;
        while (current != NULL)
        {
            tmp = current->next;
            action(current->key, &(current->value), param);
            current = tmp;
        }
    }
    return rc;
}

/**
 * Возвращает значение соответствующее минимальному ключу.
 *
 * \param[in] arr - описатель массива
 * \param[out] num - указатель на значение, соответствующее минимальному ключу (в случае успеха)
 *
 * \return ASSOC_ARRAY_OK или код ошибки (ASSOC_ARRAY_INVALID_PARAM, ASSOC_ARRAY_NOT_FOUND - т.е. массив пустой)
 */
assoc_array_error_t assoc_array_min(const assoc_array_t arr, int **num)
{
    int rc = ASSOC_ARRAY_NOT_FOUND;
    if (arr == NULL || num == NULL)
        rc = ASSOC_ARRAY_INVALID_PARAM;
    else
    {
        char *min_key;
        int flag = 0;
        node_t *current = (arr->head);
        while (current)
        {
            if (flag == 0)
            {
                *num = &current->value;
                min_key = current->key;
                flag = 1;
                rc = ASSOC_ARRAY_OK;
            }
            else if (strcmp(current->key, min_key) < 0)
            {
                min_key = current->key;
                *num = &current->value;
            }
            current = current->next;
        }
    }
    return rc;
}

/**
 * Возвращает значение соответствующее максимальному ключу.
 *
 * \param[in] arr - описатель массива
 * \param[out] num - указатель на значение, соответствующее максимальному ключу (в случае успеха)
 *
 * \return ASSOC_ARRAY_OK или код ошибки (ASSOC_ARRAY_INVALID_PARAM, ASSOC_ARRAY_NOT_FOUND - т.е. массив пустой)
 */
assoc_array_error_t assoc_array_max(const assoc_array_t arr, int **num)
{
    int rc = ASSOC_ARRAY_NOT_FOUND;
    if (arr == NULL || num == NULL)
        rc = ASSOC_ARRAY_INVALID_PARAM;
    else
    {
        char *max_key;
        int flag = 0;
        node_t *current = (arr->head);
        while (current)
        {
            if (flag == 0)
            {
                *num = &current->value;
                max_key = current->key;
                rc = ASSOC_ARRAY_OK;
                flag = 1;
            }
            else if (strcmp(current->key, max_key) > 0)
            {
                max_key = current->key;
                *num = &current->value;
            }
            current = current->next;
        }
    }
    return rc;
}
