// header.h - структуры данных, макросы и объявления функций характерных для этой программы
#ifndef HEADER
#define HEADER // multiple file inclusion protection

#include <stdbool.h>

#define GET_TRIANGLE(number) (((number) * ((number) + 1)) / 2)
#define GET_SQUARE(number) ((number) * (number))
#define GET_PENTAGONAL(number) (((number) * (3 * (number) - 1)) / 2)
#define GET_HEXAGONAL(number) ((number) * (2 * (number) - 1))
#define GET_HEPTAGONAL(number) (((number) * (5 * (number) - 3)) / 2)
#define GET_OCTAGONAL(number) ((number) * (3 * (number) - 2))

#define GET_FIGURE(number, figure_name)                                                                     \
    ((figure_name) < square) ? GET_TRIANGLE(number) : ((figure_name) < pentagonal) ? GET_SQUARE(number)     \
                                                  : ((figure_name) < hexagonal)    ? GET_PENTAGONAL(number) \
                                                  : ((figure_name) < heptagonal)   ? GET_HEXAGONAL(number)  \
                                                  : ((figure_name) < octagonal)    ? GET_HEPTAGONAL(number) \
                                                                                   : GET_OCTAGONAL(number)
// operation:		получение фигурного числа по его номеру
// precondition:	number      - порядковый номер фигурного числа
//                  figure_name - имя фигурного числа
// postcondition:	            - значение фигурного числа

// #define LEN_ARR 100

typedef enum figures_names // имена фигурных чисел
{
    triangle,
    square,
    pentagonal,
    hexagonal,
    heptagonal,
    octagonal
} name_t;

typedef struct figurate_num // структура "фигурное число"
{
    name_t name;     // имя числа
    int value;       // значение фигурного числа
    int number;      // его порядковый номер
    int step;        // шаг изменения числа
    int step_change; // шаг изменения шага числа
} fig_t;

#define SHIFT_DIGITS(number) (((number) % 100) * 100)
// operation:		сдвиг цифр в числе на две влево
// precondition:	number  - число, например, 1234
// postcondition:	        - 3400

int get_near_figure(fig_t *figure, int value);
// operation:		присвоение фигурному числу ближайшего (большего) значения
// precondition:	figure  - фигурное число
//                  value   - значение
// postcondition:	присваивает новое значение фигурному числу и возвращает
//                  значение фигурного числа
//                  0   - если не присвоили значения

int get_next_figure(fig_t *figure);
// operation:		присвоение фигурному числу следующего (большего) значения
// precondition:	figure  - фигурное число
// postcondition:	присваивает новое значение фигурному числу и возвращает его значение
#endif