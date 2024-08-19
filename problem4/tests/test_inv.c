// test_inv.c

#include <stdio.h>
#include "../funcs.c"

int main(void)
{
	for(int num = 1, dig = 1; num < 1000000000; num *= 10 + dig)
		printf("num: %10d - invert num: %10d\n", num, invert(num));
	return 0;
} 
