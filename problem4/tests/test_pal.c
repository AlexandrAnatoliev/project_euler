// test_pal.c

#include <stdio.h>
#include "../funcs.c"

int main(void)
{
	for(int num = 1, dig = 1; num < 1000000000; num *= 10 + dig)
	{		
		printf("num: %10d - %s\n", num, is_palindrome(num) ? "is palindrome" : "is not palindrome");
	}
	return 0;
} 
