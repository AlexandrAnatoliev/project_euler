// push_test.c - тест функции sieve_push_prime()

#include <stdio.h>
#include "../sievelib.h"

int main(void)
{
	sieve_t* sieve = sieve_init_malloc(10);
	
	bool result = sieve_push_prime(sieve, 2);
	
	printf("len_arr = %d\n", sieve->len_arr);
	printf("last_prime = %d\n", sieve->last_prime);
	for(int i = 0; i < sieve->len_arr; i++)
		printf("arr[%d] = %d\n", i, sieve->arr[i]);

	sieve_free(sieve);
	
	printf("sieve_push_prime(2): function push prime %s\n", (result == true) ? "successfully" : "unsuccessfully");

	return 0;
}
