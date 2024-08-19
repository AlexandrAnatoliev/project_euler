// funcs.c - реализация функций

#ifndef FUNCS 
#define FUNCS           // защита от множественного включения файла

#include "header.h"
#include <stdlib.h>     // для malloc() и free()

node_t* node_malloc(const fig_t* figure)
// operation:		выделение памяти под структуру узла и инициализация его полей
// precondition:	figure  - фигурное число
// postcondition:	выделяет память для узла, инициализирует поля и возвращает указатель на структуру
//                  иначе   - NULL
{
    node_t* node = NULL;

    if((node = malloc(sizeof(node_t))) != NULL) // если память выделена
    {
        node->figure = *figure;                 // заполняем поля
        node->head = NULL;
        node->next = NULL;
    }

    return node;
}

node_t* list_add_node(node_t* past_node, node_t* add_node)
// operation:		добавление узла к списку
// precondition:	past_node   - последний узел
//                  add_node    - добавляемый узел
// postcondition:	добавляет в список узел, возвращает указатель на последний узел

{
    past_node->next = add_node;
    add_node->head = past_node;
    return add_node;
}

bool list_free(node_t* head_node)
// operation:		удаление списка и освобождение памяти
// precondition:	head_node   - первый узел
// postcondition:	проходит по списку до его конца (пока next != NONE) и освобождает память (free())
//                  возвращает true в случае успеха		
{
    node_t* ptr = head_node;    // указатель на первый элемент
    node_t* next;               // на следующий

    while (ptr != NULL)
    {
        next = ptr->next;
        free(ptr);              // освобождаем память
        ptr = next;
    } 

    return true;    
}

bool get_near_figure(fig_t *figure, int value)
// operation:		присвоение фигурному числу ближайшего (большего) значения
// precondition:	figure  - фигурное число
//                  value   - значение
// postcondition:	присваивает новое значение фигурному числу и возвращает 
//                  true    - если value - фигурное число
//                  false   - если присвоили ближайшее большее
{
    int min = 1;
    int max = 1;
    int x;

    while((GET_FIGURE(max, figure->name)) < value) // ищем диапазон для поиска значения
    {
        min = max;
        max *= 2;
    }

    while(min <= max)                           // ищем значение
    {
        int mid = (min + max) / 2;
        int guess = GET_FIGURE(mid, figure->name);

        if(guess == value)                      // если число совпало
        {
            figure->value = mid;
            figure->value = guess;
            return true;
        }

        if(guess > value)
            max = mid - 1;
        else
            min = mid + 1;   
    }

    figure->value = (max + min) / 2 + 1;                   // иначе присваиваем ближайшее большее
    figure->value = GET_FIGURE(figure->value, figure->name);

    return false;
}

bool get_next_figure(fig_t *figure)
// operation:		присвоение фигурному числу следующего (большего) значения
// precondition:	figure  - фигурное число
// postcondition:	присваивает новое значение фигурному числу и возвращает true
{
    figure->value += 1;                   //  присваиваем ближайшее большее
    figure->value = GET_FIGURE(figure->value, figure->name);
    return true;
}

#endif