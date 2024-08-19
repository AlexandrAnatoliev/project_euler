// main.c - project Euler problem 3 "Largest Prime Factor"

// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 6008514745143?

#include <stdbool.h>							// allows you to use "false" and "true"
#include <stdio.h>
#include "timer.h"								// to measure the program running time

int main(void)
{
    long long num = 600851475143;
    int div;                    
	bool is_div = true;							// "there is divider" flag	

	TIMER_START

    while(is_div)                              	// while there is divider
    {
        is_div = false;							// there is not divider 

		for(div = 2 ; div * div < num; div++)	// to check dividers only up to the square root of a number
		{
            if(num % div == 0)                  // if the number is divisible by an integer
            {                                    
                num /= div;                    	// reduse the number
                is_div = true;					// divider is founded
				break;   
            }
		}
    } 
    
	TIMER_STOP
	TIMER_PRINT

    printf("answer = %lld\n", num);
	
	return 0;
}

