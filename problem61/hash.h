// hash.h - хеширование данных

// массив[  ... структ,     структ,     структ  ...]
//              NULL        структ      структ
//                          структ      структ
//                          структ      NULL
//                          структ
//                          NULL

#ifndef HASH
#define HASH // защита от повторного включения файла

// определяем параметры массива и хеш-функции
#if defined(ENCLOSURE)      // задаем вложенность
    #if defined(LEN_HASH)   // задаем максимальное значение хранимого в хэше числа
        #define LEN_ARR (((LEN_HASH) / (ENCLOSURE)) + 1) // вычисляем длдину массива
    #else
        #define LEN_HASH 10000
        #define LEN_ARR (((LEN_HASH) / (ENCLOSURE)) + 1)
    #endif
        
#else
    #if defined(LEN_HASH)
        #define ENCLOSURE 100
        #define LEN_ARR (((LEN_HASH) / (ENCLOSURE)) + 1)
    #else
        #define LEN_HASH 10000             // по умолчанию
        #define ENCLOSURE 100              // по умолчанию
        #define LEN_ARR (((LEN_HASH) / (ENCLOSURE)) + 1)
    #endif

#endif

#define CHECK(num) (num < LEN_HASH) ? false : true
// operation:		проверка корректности ввода
// precondition:	num - вносимое в хеш число
// postcondition:	false    - число входит в массив
//                  true   - число не войдет

#include <stdbool.h>

typedef struct node // структура "узел"
{
    int num;           // значение числа в узле
    struct node *prev; // указатель на предыдущее число
    struct node *next; // на следующее
} node_t;

typedef struct list // структура "список"
{
    // int len;           // длина списка
    struct node *head; // указатель на начало списка
    struct node *tail; // на конец
} list_t;

typedef struct list_arr // структура "массив связанных списков"
{
    list_t *head_arr[LEN_ARR]; // массив указателей на списки
    int len;                   // длина массива
} hash_t;

bool hash_null(hash_t *hash);
// operation:		присваивание значения NULL данным в структуре hash
// precondition:	hash    - структура "массив связанных списков"
// postcondition:	проходит по массиву и присваивает значение NULL данным в структуре hash
//                  возвращает true в случае успеха

bool hash_free(hash_t *hash);
// operation:		удаление все данные из структуры hash и освобождение памяти
// precondition:	hash    - структура "массив связанных списков"
// postcondition:	проходит по массиву и удаляет все списки
//                  возвращает true в случае успеха

node_t *node_malloc(const int num);
// operation:		выделение памяти под структуру узла и инициализация его полей
// precondition:	num     - значение числа
// postcondition:	выделяет память для узла, инициализирует поля и возвращает указатель на структуру
//                  иначе   - NULL

list_t *list_malloc(void);
// operation:		выделение памяти под структуру списка и инициализация его полей
// precondition:	
// postcondition:	выделяет память под список, инициализирует поля и возвращает указатель на структуру
//                  иначе   - NULL

node_t *add_num(hash_t *hash, const int num);
// operation:		добавление числа в кэш (заносятся в порядке возрастания)
// precondition:	hash    - структура "массив связанных списков"
//                  num     - добавляемое число
// postcondition:	создает и добавляет в список узел с числом, возвращает  указатель на него
//                  возвращает NULL в случае если память не выделена
// TODO ВОЗВРАЩАТЬ bool?

node_t *push_num(hash_t *hash, const int num);
// operation:		вставка числа в кэш (заносится в любом порядке)
// precondition:	hash    - структура "массив связанных списков"
//                  num     - добавляемое число
// postcondition:	вставляет в список узел, возвращает  указатель на него

bool del_num(hash_t *hash, const int num);
// operation:		удаление числа из кэш
// precondition:	hash    - структура "массив связанных списков"
//                  num     - удаляемое число
// postcondition:	удаляет из списка узел, удаляет пустой список, возвращает true
//                  возвращает false в случае, если нет такого числа

bool *is_num(const hash_t *hash, const int num);
// operation:		поиск значений num в структуре hash
// precondition:	hash    - структура "массив связанных списков"
//                  num     -  искомое число
// postcondition:	возвращает true - если есть такое число
//                  иначе - false

int get_near_num(const hash_t *hash, int num);
// operation:		поиск в структуре hash ближайшего (большего) значения к num 
// precondition:	hash    - структура "массив связанных списков"
//                  num     - искомое число
// postcondition:	возвращает значение самого числа, если оно есть в hash
//                  или ближайшее большее к нему
//                  возращает 0 если hash закончился

int get_next_num(const hash_t *hash, int num);
// operation:		поиск в структуре cash следующего значения после num 
// precondition:	hash    - структура "массив связанных списков"
//                  num     - искомое число
// postcondition:	возвращает ближайшего большего числа к num
//                  возращает 0 если hash закончился

#endif