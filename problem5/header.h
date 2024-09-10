// header.h - problem 5 

#ifndef HEADER       			// multiple file inclusion protection
#define HEADER

#include <stdbool.h> 			// for using "false" and "true"
#include <assert.h>				// for error handling

long get_nod_iter(long num1, long num2);
// operation:		получение наибольшего общего делителя итеративным способом
// precondition:	num1, num2 	- натуральные числа
// postcondition:	NOD

long get_nod_rec(long num1, long num2);
// operation:		получение наибольшего общего делителя рекурсивно
// precondition:	num1, num2 	- натуральные числа
// postcondition:	NOD

long get_nok(long num1, long num2, long (*get_nod)(long, long));
// operation:		получение наименьшего общего кратного двух чисел
// precondition:	num1, num2 	- натуральные числа
//                  get_nod     - указатель на функцию, возвращающую НОД
// postcondition:	NOK

#endif
