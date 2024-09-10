// test_funcs.h - problem 5 

#ifndef TEST_FUNCS_H       		// multiple file inclusion protection
#define TEST_FUNCS_H

#include <stdbool.h> 			// for using "false" and "true"
#include <stdio.h>				

bool func_response_is_correct(long expect_res, long num1, long num2, long (*func)(long, long));
// operation:	    проверка корректности результата, возвращаемого проверяемой функцией
// precondition:	expect_res  - ожидаемый результат
//                  num1, num2 	- натуральные числа
//                  (*func)     - указатель на проверяемую функцию
// postcondition:	выводит сообщение о корректности / некорректности работы проверяемой функции
//                  возвращает true / false в зависимости от результатов проверки

#endif
