// header.h

#ifndef HEADER       			// multiple file inclusion protection
#define HEADER

#include <stdbool.h> 			// for using "false" and "true"
#include <assert.h>				// for error handling

int invert(int num);
// operation:		iverts a number		
// precondition:	num	- number (for example, 123456)
// postcondition:	inverted number (654321)

bool is_palindrome(int num);
// operation:		checking if a number is a palindrome	
// precondition:	num		- number being checked
// postcondition:	true	- number is palindrome
// 					false	- otherwise

int get_max_pal(int prev_max, int num1, int num2);
// operation:		finding the maximum palindrome recursively
// precondition:	num1	- first multiplier (it's not change)
//					num2	- second multiplier (variable from num2 to 0)
// postcondition:	returns the maximum palindrome obtained from the factors
//					or the previous maximum multiplier (if it's greater)

#endif
