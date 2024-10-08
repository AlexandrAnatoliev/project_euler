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
	sieve->last_prime = 0;					// обнуляем поля
	
	for(int i = 0; i <= max_num; i++)
		sieve->arr[i] = 0;

	return sieve;
}

bool sieve_free(sieve_t *sieve)
{
	free(sieve);

	return true;
}

bool sieve_push_prime(sieve_t *sieve, int prime)
{
	assert(prime > 1);						// первое простое число - 2
	assert(prime < sieve->len_arr);			// проверка невыхода за пределы массива

	sieve->last_prime = prime;
	for(int i = 2 * prime; i < sieve->len_arr; i += prime)
		sieve->arr[i] = 1;					// отмечаем составные числа
	
	return true;
}

int sieve_get_next_prime(sieve_t *sieve)
// operation:		проходит по массиву и возвращает значение следующего простого числа
// precondition:	sieve	- указатель на структуру "решето" 
// postcondition:	возвращает 0 в случае, если до конца массива простых чисел нет
{
	int next_prime = 0;

	for(int i = sieve->last_prime + 1; i < sieve->len_arr; i++)
	{
		if(sieve->arr[i] == 0)
			return next_prime = i;
	}

	return 0;
}
