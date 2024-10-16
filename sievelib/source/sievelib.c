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
    
    if(prime * prime < sieve->len_arr)      // после prime == sqrt(len_arr) все составные числа уже отмечены
    {
        for(int i = prime * prime; i < sieve->len_arr; i += prime)
		    sieve->arr[i] = 1;			    // отмечаем составные числа
                                            // числа кратные от (2 * prime) до (prime * prime)
                                            // отмечены как составные ранее (при внесении чисел меньших prime)
	}

	return true;
}

int sieve_get_next_prime(sieve_t *sieve)
// operation:		проходит по массиву и возвращает значение следующего простого числа
// precondition:	sieve	- указатель на структуру "решето" 
// postcondition:	возвращает 0 в случае, если до конца массива простых чисел нет
{
	int next_prime = 0;
    
    if(sieve->last_prime == 2)              // после 2 следующее простое число 3
        return 3;

	for(int i = sieve->last_prime + 2; i < sieve->len_arr; i += 2)
	{                                       // проверяем только нечетные числа
		if(sieve->arr[i] == 0)
			return next_prime = i;
	}

	return 0;
}
