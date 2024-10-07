// main.c - project Euler problem 6 "Sum square difference"i
// 
// The sum of the squares of the first ten natural numbers is,
// 1^2 + 2^2 + ... + 10^2 = 385;
// The square of the sum of the first ten natural numbers is,
// (1 + 2 + ... + 10)^2 = 55^2 = 3025;
// Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is
// 3025 - 385 = 2640.

// Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

#include <stdio.h>
#include "header.h"
#include "funcs.c"
#include "../timerlib/timerlib.h"

int main(void)
{
    int answ = 0;							// use iterative function
    union time_u time;						// variable to store program execution time
	
	time = timer_start();					
	
	answ += get_sq_sum_iter(100);
	answ -= get_sum_sq_iter(100);

	time = timer_stop(time);
    
	printf("Iterative solution: answer = %d\n", answ);
    timer_show(time);						// display operating time on screen
    
    answ = 0;								// use recursive funcion
	time = timer_start();					
	
	answ += get_sq_sum_math(100);
	answ -= get_sum_sq_math(100);
	
	time = timer_stop(time);

	printf("Mathematical solution: answer = %d\n", answ);
	timer_show(time);					
	
    return 0;
}
