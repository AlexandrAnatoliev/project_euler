// funcs.c

#ifndef FUNCS       			// multiple file inclusion protection
#define FUNCS

#include "header.h"

int invert(int num)
// operation:		iverts a number		
// precondition:	num		- number (for example, 123456)
// postcondition:	inverted number (654321)
{
	assert	(num >= 0);			// the function works with positive numbers only

	int invert_num = 0;
	
	while(num)
	{
		invert_num *= 10;		// the inverted number is constructed 6->65->654->...
		invert_num += num % 10;	// from trimmed digits;
		num /= 10;				// the original number is truncated 123456->12345->1234->... 
	}
	
	return invert_num;
}

bool is_palindrome(int num)
// operation:		checking if a number is a palindrome	
// precondition:	num		- number being checked
// postcondition:	true	- number is palindrome
// 					false	- otherwise
{
	if(num < 10)				// negative number
		return false;			// or consisting of one digit only cannot be a palindrome
	
	return num == invert(num);
}

int get_max_pal(int prev_max, int num1, int num2)
// operation:		поиск максимального палиндрома рекурсивно
// precondition:	num1	- первый множитель (не изменяемый)
//					num2	- второй множитель (изменяемый от num2 до 0)
// postcondition:	возвращает максимальный палиндром полученный из множителей 
//					либо предыдущий максимальный множитель если он больше
{
	if(num1 <= 0 || num2 <= 0)		// we exit the recursion for negative values of the factors
		return prev_max;

	if(prev_max > num1 * num2)		// with a furter decrease in num2 product (num1 * num2) will be smaller
		return prev_max;	

	if(is_palindrome(num1 * num2))	// save the found palindrome value
		prev_max = num1 * num2;
	
	prev_max = get_max_pal(prev_max, num1, num2 - 1);	// iterate over num2 recursively
	
	return prev_max;	
}

#endif
