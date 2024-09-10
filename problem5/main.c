// main.c - project Euler problem 5 "Smallest multiple"

// 2520 is smallest number that can be divided by each of the numbers from 1 to 10 without any remainder
// What is the smallest positive number that is evently divisible by all of the numbers from 1 t 20?

#include <stdio.h>
#include "header.h"
#include "funcs.c"
#include "../timerlib/timerlib.h"

int main(void)
{
    // используем итеративную функцию get_nod_iter
    long answ = 1;
    union time_u time;						// variable to store program execution time
	
	time = timer_start();					
	
    for(int i = 2; i <= 20; i++)
        answ = get_nok(answ, i, get_nod_iter);
	
	time = timer_stop(time);
    
	printf("Iterative get_nod function: answer = %ld\n", answ);
    timer_show(time);						// display operating time on screen
    
    // используем рекурсивную функцию get_nod_rec 
    answ = 1;
	time = timer_start();					
	
    for(int i = 2; i <= 20; i++)
        answ = get_nok(answ, i, get_nod_rec);
	
	time = timer_stop(time);

	printf("Recursive get_nod functio: nanswer = %ld\n", answ);
	timer_show(time);						// display operating time on screen
	
    return 0;
}

