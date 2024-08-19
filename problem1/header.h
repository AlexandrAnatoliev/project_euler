// header.h

#ifndef HEADER      // multiple file inclusion protection
#define HEADER

#define IS_NOT_DIVIDED(NUM, DIV) (NUM % DIV)
// operation:		determining whether a number is divisible by an integer divisor
// precondition:	NUM			- number to be checked
//					DIV			- number divisor
// postcondition:	false (0)	- if the number is evenly divisible by the divisor
//					true		- if the number is not divisible

#define IS_MULTIPLES(NUM) (!IS_NOT_DIVIDED(NUM, 3)) || (!IS_NOT_DIVIDED(NUM, 5))
// operation:		determining whether a number is divisible by 3 or 5
// precondition:	NUM		- number to be checked
// postcondition:	true	- if the number is divisible by one of the divisors
//					false	- if the number is not divisible

#endif
