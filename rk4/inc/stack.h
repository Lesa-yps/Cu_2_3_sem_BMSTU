#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>

// коды ошибок
#define OK 0
#define ERROR 1

#define YES 0
#define NO 1

// Структура - элемент односвязного списка
struct Node
{
    char data; // данные
    struct Node *next;   // Указатель на следующий элемент односвязного списка
};

// достает элемент (данные о нем) из головы стека
int pop_din(struct Node** head, char *res);
// засовывает элемент в голову стека (по данным в нем)
int push_din(struct Node **head, char num);
// читает стек
void read_din(struct Node *head);
// очищает стек, работает с ним
int work_din(struct Node **head);
// освобождает весь стек
void free_stack_din(struct Node *head);

#endif // STACK_H
