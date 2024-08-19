// hash.c - хеширование данных

// массив[  ... структ,     структ,     структ  ...]
//              NULL        структ      структ
//                          структ      структ
//                          структ      NULL
//                          структ
//                          NULL

#include <stdlib.h> // для malloc() и free() и NULL!
#include "hash.h"

// вспомогательные функции
int static inline get_indx(int num)
// operation:		вычисляет индекс в массиве хеша
// precondition:	num   - вносимое в хеш число
// postcondition:	возвращает индекс массива
{
    return (num / ENCLOSURE);
}

bool static inline list_free(list_t *list)
// operation:		удаление списка и освобождение памяти
// precondition:	list   - удаляемый список
// postcondition:	проходит по списку до его конца (пока next != NONE) и освобождает память (free())
//                  возвращает true в случае успеха
{
    if (list == NULL)
        return false;

    node_t *ptr = list->head;

    while (ptr != NULL) // проходим по списку и удаляем узлы
    {
        ptr = list->head->next;
        free(list->head);
        list->head = ptr;
    }

    free(list);  // освобождаем память
    list = NULL; // обнуляем поле в массиве

    return true;
}

bool hash_null(hash_t *hash)
// operation:		присваивание значения NULL данным в структуре hash
// precondition:	hash    - структура "массив связанных списков"
// postcondition:	проходит по массиву и присваивает значение NULL данным в структуре hash
//                  возвращает true в случае успеха
{
    hash->len = LEN_ARR;

    for (int i = 0; i < LEN_ARR; i++)
        hash->head_arr[i] = NULL;

    return true;
}

bool hash_free(hash_t *hash)
// operation:		удаление все данные из структуры hash и освобождение памяти
// precondition:	hash    - структура "массив связанных списков"
// postcondition:	проходит по массиву и удаляет все списки
//                  возвращает true в случае успеха
{
    for (int indx = 0; indx < hash->len; indx++)
    {
        if (hash->head_arr[indx] != NULL)
        {
            list_free(hash->head_arr[indx]);
            hash->head_arr[indx] = NULL;
        }
    }

    return true;
}

node_t *node_malloc(const int num)
// operation:		выделение памяти под структуру узла и инициализация его полей
// precondition:	num     - значение числа
// postcondition:	выделяет память для узла, инициализирует поля и возвращает указатель на структуру
//                  иначе   - NULL
{
    if (CHECK(num)) // проверка корректности ввода
        return NULL;

    node_t *node = malloc(sizeof(node_t)); // создаем узел

    if (node != NULL)
    {
        node->num = num; // заносим в него число
        node->next = NULL;
        node->prev = NULL;
    }

    else
        return NULL; // прерываем, если память не выделилась
}

list_t *list_malloc(void)
// operation:		выделение памяти под структуру списка и инициализация его полей
// postcondition:	выделяет память под список, инициализирует поля и возвращает указатель на структуру
//                  иначе   - NULL
{
    list_t *list = malloc(sizeof(list)); // создаем список

    if (list != NULL)
    {
        list->head = NULL;
        list->tail = NULL;
        return list;
    }

    else
        return NULL; // прерываем, если память не выделилась
}

node_t *add_num(hash_t *hash, const int num)
// operation:		добавление числа в кэш (заносятся в порядке возрастания)
// precondition:	hash    - структура "массив связанных списков"
//                  num     - добавляемое число
// postcondition:	создает и добавляет в список узел с числом, возвращает  указатель на него
//                  возвращает NULL в случае если память не выделена
{
    if (CHECK(num)) // проверка корректности ввода
        return NULL;

    int indx = get_indx(num); // индекс в хеш-массиве

    node_t *node = node_malloc(sizeof(node_t)); // выделяем память для узла

    if (node == NULL)
        return NULL; // прерываем, если память не выделилась

    node->num = num;                            // инициализируем узел
    node->next = NULL;
    node->prev = NULL;

    if (hash->head_arr[indx] == NULL)         // если ячейка пуста
        hash->head_arr[indx] = list_malloc(); // создаем список

    if (hash->head_arr[indx] == NULL)
        return NULL; // прерываем, если память не выделилась

    if (hash->head_arr[indx]->head == NULL) // если узел первый
        hash->head_arr[indx]->head = node;

    else if (hash->head_arr[indx]->tail == NULL) // если второй
    {
        hash->head_arr[indx]->tail = node;
        node->prev = hash->head_arr[indx]->head;
        hash->head_arr[indx]->head->next = node;
    }

    else // добавляем узел в конец списка
    {
        hash->head_arr[indx]->tail->next = node;
        node->prev = hash->head_arr[indx]->tail;
        hash->head_arr[indx]->tail = node;
    }

    return node;
}

node_t *push_num(hash_t *hash, const int num)
// operation:		вставка числа в кэш (заносится в любом порядке)
// precondition:	hash    - структура "массив связанных списков"
//                  num     - добавляемое число
// postcondition:	вставляет в список узел, возвращает  указатель на него
{
    if (CHECK(num)) // проверка корректности ввода
        return NULL;

    int indx = get_indx(num); // индекс в хеш-массиве

    if (hash->head_arr[indx] == NULL) // если ячейка массива пуста
        return add_num(hash, num);    // то просто вставляем туда число

    node_t *node = node_malloc(num); // создаем узел

    if (node == NULL)
        return NULL; // прерываем, если память не выделилась

    node_t *ptr = hash->head_arr[indx]->head; // с начала списка

    while ((ptr->next != NULL) && (ptr->next->num < num))
        // пока не дойдем до конца списка или не найдем место числу
        ptr = ptr->next; // проходим указателем

    if (ptr->next == NULL)
        ptr->next = node; // добавляем в конец списка

    else
    {
        node->next = ptr->next; // вставляем между большим
        ptr->next->prev = node;
        node->prev = ptr;
        ptr->next = node;
    }

    return node;
}

bool del_num(hash_t *hash, const int num)
// operation:		удаление числа из кэш
// precondition:	hash    - структура "массив связанных списков"
//                  num     - удаляемое число
// postcondition:	удаляет из списка узел, удаляет пустой список, возвращает true
//                  возвращает false в случае, если нет такого числа
{
    if (CHECK(num)) // проверка корректности ввода
        return false;

    int indx = get_indx(num); // индекс в хеш-массиве

    if (hash->head_arr[indx] == NULL) // если ячейка массива пуста
        return false;

    node_t *ptr = hash->head_arr[indx]->head; // с начала списка

    while ((ptr->next != NULL) && (ptr->next->num < num))
        // пока не дойдем до конца списка или не найдем место числу
        ptr = ptr->next; // проходим указателем

    if (ptr->num == num) // нашли ячейку с искомым числом
    {
        if (hash->head_arr[indx]->tail == NULL)
        {
            list_free(hash->head_arr[indx]); // удаляем весь список, если число единственное
            return true;
        }

        else if(ptr == hash->head_arr[indx]->tail) // если конец цепочки
        {
            hash->head_arr[indx]->tail = ptr->prev;
            // TODO продолжить
            // что с инициализацией ? хвост = голова?
        }

        else
        {
            ptr->next->prev = ptr->prev; // соединяем узлы между собой
            ptr->prev->next = ptr->next;
            free(ptr); // удаляем узел
            return true;
        }
    }

    else
        return false;
}

bool *is_num(const hash_t *hash, const int num)
// operation:		поиск значений num в структуре hash
// precondition:	hash    - структура "массив связанных списков"
//                  num     -  искомое число
// postcondition:	возвращает true - если есть такое число
//                  иначе - false
{
    if (CHECK(num)) // проверка корректности ввода
        return false;

    int indx = get_indx(num); // индекс в хеш-массиве

    if (hash->head_arr[indx] == NULL) // если ячейка массива пуста
        return false;

    node_t *ptr = hash->head_arr[indx]->head; // с начала списка

    while ((ptr->next != NULL) && (ptr->num != num) && (ptr->next->num < num))
        // пока не дойдем до конца списка или не найдем число
        ptr = ptr->next; // проходим указателем

    if (ptr->num == num) // нашли ячейку с искомым числом
        return true;

    else
        return false;
}

int get_near_num(const hash_t *hash, int num)
// operation:		поиск в структуре hash ближайшего (большего) значения к num
// precondition:	hash    - структура "массив связанных списков"
//                  num     - искомое число
// postcondition:	возвращает значение самого числа, если оно есть в hash
//                  или ближайшее большее к нему
//                  возращает 0 если hash закончился
{
    if (CHECK(num)) // проверка корректности ввода
        return 0;

    int indx = get_indx(num); // индекс в хеш-массиве

    if (hash->head_arr[indx] != NULL) // если список есть
    {
        node_t *ptr = hash->head_arr[indx]->head; // с начала списка

        while ((ptr->next != NULL) && (ptr->num != num) && (ptr->next->num < num))
            // пока не дойдем до конца списка или не найдем число
            ptr = ptr->next; // проходим указателем

        if (ptr->num == num) // нашли ячейку с искомым числом
            return ptr->num;

        else if (ptr != NULL) // возвращаем следующее
            return ptr->num;
    }

    // если в этом списке нет - проходим дальше по массиву
    for (int i = indx + 1; i < hash->len; i++)
    {
        if (hash->head_arr[i] != NULL)
            return hash->head_arr[i]->head->num;
    }

    return 0;
}

int get_next_num(const hash_t *hash, int num)
// operation:		поиск в структуре cash следующего значения после num
// precondition:	hash    - структура "массив связанных списков"
//                  num     - искомое число
// postcondition:	возвращает ближайшего большего числа к num
//                  возращает 0 если hash закончился
{
    if (CHECK(num)) // проверка корректности ввода
        return 0;

    int indx = get_indx(num); // индекс в хеш-массиве

    if (hash->head_arr[indx] != NULL)
    {
        node_t *ptr = hash->head_arr[indx]->head; // с начала списка

        while ((ptr->next != NULL) && (ptr->next->num < num))
            // пока не дойдем до конца списка или не найдем большее число
            ptr = ptr->next; // проходим указателем

        if (ptr->next != NULL) // возвращаем следующее
            return ptr->next->num;
    }

    // если в этом списке нет - проходим дальше по массиву
    for (int i = indx + 1; i < hash->len; i++)
    {
        if (hash->head_arr[i] != NULL)
            return hash->head_arr[i]->head->num;
    }

    return 0;
}