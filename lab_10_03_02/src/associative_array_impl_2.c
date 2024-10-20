#define _POSIX_C_SOURCE 200809L

#include "associative_array.h"

#include <stdlib.h>
#include <string.h>

#define SIZE_OF_ARR 512

// массив структур

typedef struct node node_t;

struct node
{
    char *key; // ключ - строка
    int value; // значение - целое число
};

struct assoc_array_type
{
    node_t *head[SIZE_OF_ARR];
    int n;
};

/**
 * Тип ассоциативный массив: ключ - строка, значение - целое число.
 *
 * Ключ не может быть пустой строкой.
 */

/**
 * Создает объект ассоциативный массив.
 *
 * \return Созданный объект или NULL
 */
assoc_array_t assoc_array_create(void)
{
    assoc_array_t struct_head = malloc(sizeof(struct assoc_array_type));
    if (struct_head != NULL)
    {
        struct_head->n = 0;
        memset(struct_head->head, 0, sizeof(node_t *) * SIZE_OF_ARR);
    }
    return struct_head;
}

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
        for (int i = 0; i < arr->n && (!rc); i++)
        {
            if (strcmp((arr->head[i])->key, key) == 0)
                rc = ASSOC_ARRAY_KEY_EXISTS;
        }
        if (!rc)
        {
            node_t *new_node = calloc(1, sizeof(node_t));
            if (new_node == NULL)
                rc = ASSOC_ARRAY_MEM;
            else
            {
                new_node->key = strdup(key);
                if (new_node->key == NULL)
                {
                    free(new_node);
                    rc = ASSOC_ARRAY_MEM;
                }
                else
                {
                    new_node->value = num;
                    arr->head[arr->n] = new_node;
                    (arr->n)++;
                }
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
        for (int i = 0; i < arr->n && (rc); i++)
            if (strcmp((arr->head[i])->key, key) == 0)
            {
                *num = &((arr->head[i])->value);
                rc = ASSOC_ARRAY_OK;
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
        for (int i = 0; i < arr->n && (rc == ASSOC_ARRAY_NOT_FOUND); i++)
        {
            if (strcmp((arr->head[i])->key, key) == 0)
            {
                free((arr->head[i])->key);
                free(arr->head[i]);
                rc = ASSOC_ARRAY_OK;
                int j;
                for (j = i; j < (arr->n - 1); j++)
                {
                    arr->head[j] = arr->head[j + 1];
                }
                arr->head[j + 1] = NULL;
                arr->n--;
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
    if (arr == NULL || arr->head == NULL)
        rc = ASSOC_ARRAY_INVALID_PARAM;
    else
    {
        node_t *current;
        for (int i = 0; i < arr->n; i++)
        {
            current = arr->head[i];
            if (current != NULL)
            {
                free(current->key);
                free(current);
                arr->head[i] = NULL;
            }
        }
        arr->n = 0;
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
        for (int i = 0; i < arr->n && (!rc); i++)
            action((arr->head[i])->key, &((arr->head[i])->value), param);
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
        for (int i = 0; i < arr->n; i++)
        {
            if (flag == 0)
            {
                *num = &((arr->head[i])->value);
                min_key = (arr->head[i])->key;
                rc = ASSOC_ARRAY_OK;
                flag = 1;
            }
            else if (strcmp((arr->head[i])->key, min_key) < 0)
            {
                *num = &((arr->head[i])->value);
                min_key = (arr->head[i])->key;
            }
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
        for (int i = 0; i < arr->n; i++)
        {
            if (flag == 0)
            {
                *num = &((arr->head[i])->value);
                max_key = (arr->head[i])->key;
                rc = ASSOC_ARRAY_OK;
                flag = 1;
            }
            else if (strcmp((arr->head[i])->key, max_key) > 0)
            {
                *num = &((arr->head[i])->value);
                max_key = (arr->head[i])->key;
            }
        }
    }
    return rc;
}
