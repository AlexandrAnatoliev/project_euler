// header.h - problem 5 

#ifndef HEADER       			// multiple file inclusion protection
#define HEADER

#include <stdbool.h> 			// for using "false" and "true"
#include <assert.h>				// for error handling

long get_gcd_iter(long num1, long num2);
// operation:		getting the greatest common divisor iteratively;
// precondition:	num1, num2 	- natural numbers;
// postcondition:	greatest common divisor (GCD).

long get_gcd_rec(long num1, long num2);
// operation:		getting the greatest common divisor by recursion;
// precondition:	num1, num2 	- natural numbers;
// postcondition:	GCD

long get_lcm(long num1, long num2, long (*get_gcd)(long, long));
// operation:		getting the least common multiple of two numbers;
// precondition:	num1, num2 	- natural numbers;
//                  get_gcd     - pointer to a funcion returning GCD
// postcondition:	least common multiple (LCM).

#endif
