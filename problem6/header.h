// header.h - problem 6 

#ifndef HEADER       			// multiple file inclusion protection
#define HEADER

#include <assert.h>				// for error handling

int get_sq_sum_iter(int num);
// operation:		calculating the square of the sum of numbers (iterative version);
// precondition:	num - the number of natural numbers;
// postcondition:	returns the square of the sum of numbers from 1 to num inclusive.

int get_sum_sq_iter(int num);
// operation:		calculating the sum of squares (iterative version);
// precondition:	num - the number of natural numbers;
// postcondition:	returns the sum of the squares of numbers from 1 to num inclusive.

int get_sq_sum_math(int num);
// operation:		calculating the square of the sum of numbers (mathematical version);
// precondition:	num - the number of natural numbers;
// postcondition:	returns the sum of the squares of numbers from 1 to num inclusive.

int get_sum_sq_math(int num);
// operation:		calculating the sum of squares (mathematical version);
// precondition:	num - the number of natural numbers;
// postcondition:	returns the sum of the squares of numbers from 1 to num inclusive.

#endif
