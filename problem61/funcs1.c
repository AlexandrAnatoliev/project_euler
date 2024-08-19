// funcs.c - реализация функций

#ifndef FUNCS
#define FUNCS // защита от множественного включения файла

#include "header1.h"
#include <stdlib.h> // для malloc() и free()

int get_near_figure(fig_t *figure, int value)
// operation:		присвоение фигурному числу ближайшего (большего) значения
// precondition:	figure  - фигурное число
//                  value   - значение
// postcondition:	присваивает новое значение фигурному числу и возвращает
//                  значение фигурного числа
{
    int min = 1;
    int max = 1;
    int x;

    while ((GET_FIGURE(max, figure->name)) < value) // ищем диапазон для поиска значения
    {
        min = max;
        max *= 2;
    }

    while (min <= max) // ищем значение
    {
        int mid = (min + max) / 2;
        int guess = GET_FIGURE(mid, figure->name);

        if (guess == value) // если число совпало
        {

            figure->number = mid;
            figure->value = guess;
            figure->step = (GET_FIGURE(figure->number + 1, figure->name)) - (GET_FIGURE(figure->number, figure->name));
            figure->step_change = (GET_FIGURE(figure->number + 2, figure->name)) - (GET_FIGURE(figure->number + 1, figure->name)) - figure->step;
            return figure->value;
        }

        if (guess > value)
            max = mid - 1;
        else
            min = mid + 1;
    }

    figure->number = (max + min) / 2 + 1; // иначе присваиваем ближайшее большее
    figure->value = GET_FIGURE(figure->number, figure->name);
    figure->step = (GET_FIGURE(figure->number + 1, figure->name)) - (GET_FIGURE(figure->number, figure->name));
    figure->step_change = (GET_FIGURE(figure->number + 2, figure->name)) - (GET_FIGURE(figure->number + 1, figure->name)) - figure->step;
    
    return figure->value;

}

int get_next_figure(fig_t *figure)
// operation:		присвоение фигурному числу следующего (большего) значения
// precondition:	figure  - фигурное число
// postcondition:	присваивает новое значение фигурному числу и возвращает его значение
{
    figure->number += 1; //  присваиваем ближайшее большее
    figure->value = GET_FIGURE(figure->number, figure->name);
    return figure->value;
}

#endif
