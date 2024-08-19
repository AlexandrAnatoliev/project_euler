// test_get_max_pal.c

#include <stdio.h>
#include "../funcs.c"

int main(void)
{
	for(int num = 1, dig = 1; num < 1000000000; num *= 10 + dig)
		printf("get_max_pal(0, %12d, %12d) = %12d\n", num, num, get_max_pal(0, num, num));
	
	return 0;
} 
