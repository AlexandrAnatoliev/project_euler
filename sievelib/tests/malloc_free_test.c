// malloc_free_test.c

#include <stdio.h>
#include "../source/sievelib.c"	// TODO заменить потом на библиотеку.h

int main(void)
{
	sieve_t* sieve = sieve_init_malloc(10);
	
	printf("len_arr = %d\n", sieve->len_arr);
	printf("past_prime = %d\n", sieve->past_prime);
	for(int i = 0; i < sieve->len_arr; i++)
		printf("arr[%d] = %d\n", i, sieve->arr[i]);

	bool result = sieve_free(sieve);
	
	printf("sieve_free() function freed memory %s\n", (result == true) ? "successfully" : "unsuccessfully");

	return 0;
}
