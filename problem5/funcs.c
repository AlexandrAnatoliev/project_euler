// funcs.c - problem 5

#ifndef FUNCS       			// multiple file inclusion protection
#define FUNCS

#include "header.h"

long get_nod_iter(long num1, long num2)
{
	assert	(num1 > 0 && num2 > 0);			// the function works with positive numbers only

	while(num1 && num2)
	{
		if(num1 >= num2)
			num1 %= num2;
		else
			num2 %=num1;
	}
	
	return (num1 > num2) ? num1 : num2;
}

long get_nod_rec(long num1, long num2)
{
	if(!num1 || !num2)
		return (num1 > num2) ? num1 : num2;
	
	return get_nod_rec(num2 % num1, num1);
}

long get_nok(long num1, long num2, long (*get_nod)(long, long))
{
	return num1 * num2 / get_nod(num1, num2);
}

#endif
