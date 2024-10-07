// test_funcs.h 

#ifndef TEST_FUNCS_H       		// multiple file inclusion protection
#define TEST_FUNCS_H

#include <stdbool.h> 			// for using "false" and "true"
#include <stdio.h>				

bool func_response_is_correct(int expect_res, int num, int (*func)(int));
// operation:	    checking the correctness of the result returned by the function being tested;
// precondition:    expect_res  - expected result;
//                  num 		- natural number;
//                  (*func)     - pointer to the function being tested;
// postcondition:   displays a message about the correctness/incorrectness of the function being checked,
//                  returns true/false depending on the results of the check.

#endif
