// header.h - Project Euler (problem2): Even Fibonacci Numbers

#ifndef HEADER		// multiple file inclusion protection
#define HEADER

int get_fib_recurs(int ser_num);
// operation:		getting the Fibonacci number by its serial number recursively
// precondition:	function takes the serial number
// postcondition:	and return the Fibonacci number

int get_next_fib(int array[]);
// operation:		getting the next Fibonacci number by using array
// precondition:	function takes the array is containing the first two Fibonacci numbers
// postcondition:	return the next Fibonacci number and stores the last two numbers in an array
//					return error if input is invalidate 	

#endif
