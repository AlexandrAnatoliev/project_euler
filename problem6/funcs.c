// funcs.c - problem 6

#ifndef FUNCS       			// multiple file inclusion protection
#define FUNCS

#include "header.h"

int get_sq_sum_iter(int num)
{
	assert(num > 0);			// the function works with positive numbers only

	int sum = 0;
	for(int i = 1; i <= num; i++)
		sum += i;

	return sum * sum;
}

int get_sum_sq_iter(int num)
{
	assert(num > 0);	

	int sum = 0;
	for(int i = 1; i <= num; i++)
		sum += i * i;

	return sum;
}

int get_sq_sum_math(int num)
{
	assert(num > 0);	

	int sum = (num * num + num) / 2;

	return sum * sum;
}

int get_sum_sq_math(int num)
{	
	assert(num > 0);	

	return (num * (num + 1) * (2 * num + 1)) / 6;
}

#endif
