#define GET_TRIANGLE(number) (((number) * ((number) + 1)) / 2)
#define GET_SQUARE(number) ((number) * (number))
#define GET_PENTAGONAL(number) (((number) * (3 * (number) - 1)) / 2)
#define GET_HEXAGONAL(number) ((number) * (2 * (number) - 1))
#define GET_HEPTAGONAL(number) (((number) * (5 * (number) - 3)) / 2)
#define GET_OCTAGONAL(number) ((number) * (3 * (number) - 2))
// operation:		получение фигурного числа по его номеру
// precondition:	number  - порядковый номер фигурного числа
// postcondition:	        - значение фигурного числа