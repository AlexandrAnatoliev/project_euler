// header.h - структуры данных, макросы и объявления функций характерных для этой программы
#ifndef HEADER 
#define HEADER // multiple file inclusion protection

#include <stdbool.h>

typedef enum figures_names				// имена фигурных чисел
{
	triangle,
	square,
	pentagonal,
	hexagonal,
	heptagonal,
	octagonal
} name_t;

#define GET_TRIANGLE(number) (((number) * ((number) + 1)) / 2)
#define GET_SQUARE(number) ((number) * (number))
#define GET_PENTAGONAL(number) (((number) * (3 * (number) - 1)) / 2)
#define GET_HEXAGONAL(number) ((number) * (2 * (number) - 1))
#define GET_HEPTAGONAL(number) (((number) * (5 * (number) - 3)) / 2)
#define GET_OCTAGONAL(number) ((number) * (3 * (number) - 2))

#define GET_FIGURE(number,figure_name) \
    ((figure_name) < square) ? GET_TRIANGLE(number) : \
    ((figure_name) < pentagonal) ? GET_SQUARE(number) : \
    ((figure_name) < hexagonal) ? GET_PENTAGONAL(number) : \
    ((figure_name) < heptagonal) ? GET_HEXAGONAL(number) : \
    ((figure_name) < octagonal) ? GET_HEPTAGONAL(number) : GET_OCTAGONAL(number)
// operation:		получение фигурного числа по его номеру
// precondition:	number      - порядковый номер фигурного числа
//                  figure_name - имя фигурного числа
// postcondition:	            - значение фигурного числа

#define SHIFT_DIGITS(number) (((number) % 100) * 100)
// operation:		сдвиг цифр в числе на две влево
// precondition:	number  - число, например, 1234
// postcondition:	        - 3400

typedef struct figurate_num		// структура "фигурное число"
{
	name_t name;				// имя числа
	int value;					// значение фигурного числа
	int value;					// его порядковый номер
} fig_t;

typedef struct list_node		// структура "узел списка"
{
	fig_t figure;				// фигурное число
	struct list_node* head;		// указатель на предыдущий узел списка
	struct list_node* next;		// на следующий
} node_t;

node_t* node_malloc(const fig_t* figure);
// operation:		выделение памяти под структуру узла и инициализация его полей
// precondition:	figure  - фигурное число
// postcondition:	выделяет память для узла, инициализирует поля и возвращает указатель на структуру
//                  иначе   - NULL

node_t* list_add_node(node_t* past_node, node_t* add_node);
// operation:		добавление узла к списку
// precondition:	past_node   - последний узел
//                  add_node    - добавляемый узел
// postcondition:	добавляет в список узел, возвращает указатель на последний узел

bool list_free(node_t* head_node);
// operation:		удаление списка и освобождение памяти
// precondition:	head_node   - первый узел
// postcondition:	проходит по списку до его конца (пока next != NONE) и освобождает память (free())
//                  возвращает true в случае успеха		

bool get_near_figure(fig_t *figure, int value);
// operation:		присвоение фигурному числу ближайшего (большего) значения
// precondition:	figure  - фигурное число
//                  value   - значение
// postcondition:	присваивает новое значение фигурному числу и возвращает true 

bool get_next_figure(fig_t *figure);
// operation:		присвоение фигурному числу следующего (большего) значения
// precondition:	figure  - фигурное число
// postcondition:	присваивает новое значение фигурному числу и возвращает true 

#endif
