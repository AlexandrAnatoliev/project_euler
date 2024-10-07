// sievelib.c - source code for the library

#include "../sievelib.h"

sieve_t* sieve_init_malloc(int max_num)
{
	assert(max_num > 1);					// первое простое число - 2
	
	sieve_t* sieve = malloc(2 * sizeof(int) + (max_num + 1) * sizeof(char));
	
	if(sieve == NULL)
	{
		printf("\nsieve_init_malloc(%d): memory not allocated\n", max_num);
		return NULL;
	}

	sieve->len_arr = max_num + 1;			// вводим начальные значения
	sieve->past_prime = 0;					// обнуляем поля
	
	for(int i = 0; i <= max_num; i++)
		sieve->arr[i] = 0;

	return sieve;
}

bool sieve_free(sieve_t *sieve)
{
	free(sieve);

	return true;
}

bool sieve_push_prime(sieve_t *sieve)
// operation:		вносит простое число в структуру, отмечает все составные до конца массива
// precondition:	sieve	- указатель на структуру
// postcondition:	возвращает true, если все удачно
//					false и сообщение об ошибке иначе
{
		
}

int sieve_get_next_prime(sieve_t *sieve);
// operation:		проходит по массиву и возвращает значение следующего простого числа
// precondition:	sieve	- указатель на структуру "решето" 
// postcondition:	возвращает 0 в случае, если до конца массива простых чисел нет

