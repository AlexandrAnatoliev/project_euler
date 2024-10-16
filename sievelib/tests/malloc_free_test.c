// malloc_free_test.c - тест для проверки работы функций sieve_init_malloc() и sieve_free()

#include <stdio.h>
#include "../sievelib.h"

int main(void)
{
	sieve_t* sieve = sieve_init_malloc(10);
	
	printf("len_arr = %d\n", sieve->len_arr);
	printf("last_prime = %d\n", sieve->last_prime);
	for(int i = 0; i < sieve->len_arr; i++)
		printf("arr[%d] = %d\n", i, sieve->arr[i]);

	bool result = sieve_free(sieve);
	
	printf("sieve_free() function freed memory %s\n", (result == true) ? "successfully" : "unsuccessfully");

	return 0;
}
