// ProjectEuler1c - Multiples of 3 or 5

// If we list all the natural numbers below 10 that are multiples of 3 or5, we get 3, 5, 6 and 9. 
// The sum of these multiples is 23.

// Find the sum of all the multiples of 3 or 5 below 1000.

#include <stdio.h>
#include "header.h"
#include "timer.h"

int main(void)
{
    int answ = 0;

    TIMER_START

    for (int num = 1; num < 1000; num++)    // sorting through the numbers
        if(IS_MULTIPLES(num))               // if it is divisible by 3 or 5
            answ += num;                    // add to answer

    TIMER_FINISH
    TIMER_PRINT                             // display the running time of the program using MACRO

    printf("answer = %d\n", answ);          // display the result

    return 0;
}
