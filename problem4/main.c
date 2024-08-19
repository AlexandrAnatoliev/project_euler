// main.c - project Euler problem 4 "Largest Palindrome Product"

// A palindromic number reads the same both ways. The largest palindrome made from the product of two-digit numbers is
// 9009 = 91 * 99.
// Find the largest palindrome made from the product of two-digit numbers.

#include <stdio.h>
#include "header.h"
#include "funcs.c"
#include "../timerlib/timerlib.h"

int main(void)
{
	int answ = 0;
	int num = 999;
	union time_u time;						// variable to store program execution time
	
	time = timer_start();					
	
	while(answ < num * num && num > 99)		// loop through num1
	{
		answ = get_max_pal(answ, num, num);	// and num2 is recursive
		num--;	
	}
	
	time = timer_stop(time);
	timer_show(time);						// display operating time on screen
	
	printf("answer = %d\n", answ);
	return 0;
}

