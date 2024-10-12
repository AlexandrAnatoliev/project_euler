// next_prime_test.c - тест для проверки работоспособности функции sieve_get_next_prime() 

#include <stdio.h>
#include "../sievelib.h"

int main(void)
{
	int last_prime = 2;
	sieve_t* sieve = sieve_init_malloc(10);
	
	sieve_push_prime(sieve, last_prime);
 	int next_prime= sieve_get_next_prime(sieve);
	
	printf("len_arr = %d\n", sieve->len_arr);
	printf("last_prime = %d\n", sieve->last_prime);
	for(int i = 0; i < sieve->len_arr; i++)
		printf("arr[%d] = %d\n", i, sieve->arr[i]);

	sieve_free(sieve);
	
	printf("sieve_get_next_prime(): function returns %d for last_prime = %d\n", next_prime, last_prime);

	return 0;
}
