// main.c - project Euler problem 5 "Smallest multiple"

// 2520 is smallest number that can be divided by each of the numbers from 1 to 10 without any remainder
// What is the smallest positive number that is evently divisible by all of the numbers from 1 t 20?

#include <stdio.h>
#include "header.h"
#include "funcs.c"
#include "../timerlib/timerlib.h"

int main(void)
{
    long answ = 1;							// use iterative function
    union time_u time;						// variable to store program execution time
	
	time = timer_start();					
	
    for(int i = 2; i <= 20; i++)
        answ = get_lcm(answ, i, get_gcd_iter);
	
	time = timer_stop(time);
    
	printf("Iterative get_gcd function: answer = %ld\n", answ);
    timer_show(time);						// display operating time on screen
    
    answ = 1;								// use recursive funcion
	time = timer_start();					
	
    for(int i = 2; i <= 20; i++)
        answ = get_lcm(answ, i, get_gcd_rec);
	
	time = timer_stop(time);

	printf("Recursive get_gcd function: answer = %ld\n", answ);
	timer_show(time);					
	
    return 0;
}
