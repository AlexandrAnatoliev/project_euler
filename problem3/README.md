# Project Euler problem 3: Largest Prime Factor 

For convenience, the program is divided into two files:
* timer.h
* main.c


## timer.h
The file is used to measure the running time of the program.

Using the design:
```
#ifndef TIMER
#define TIMER
#endif
```
...the file is protected from being included again.

The header file `<time.h>` allows you to work with time.

The file `"timer.h"` contains three macros:
* `TIMER_START` - creates a variable to measure code execution time and starts the timer;
* `TIMER_STOP` - stops the timer and calculates the program execution time in seconds;
* `TIMER_PRINT` - displays the operating time on the screen


## main.c
This file contains the `main()` function and the main logic of the program.

We connect standard libraries:
* `<stdbool.h>` - header file that allows `true` and `false` to be used;
* `<stdio.h>` - I/O library. Allows the use of the `printf()` function.

We include the header file `"timer.h"` to measure the speed of the program.

The program's algorithm is based on factoring a number:
* iterate over divisors (div) of a given number (num);
* since the divisors move from smaller to larger, therefore the found divisor is minimal;
* using the found divisor, we decompose the number into divisors: minimum and maximum (div_min * div_max = num);
* the cycle starts again, but this time the already found maximum divisor is expanded: *num = num / div (div_max = num / div);*
* and so on until the number can no longer be factorized - the maximum possible prime divisor.

There is no need to iterate over the divisors (*div*) of the number (*num*) right down to the number itself. It is enough to search for them only up to the square root of the number being checked (*sqrt(num)*). If the divisor has not been found up to this point, the number is prime. 
