# Project Euler problem 4: Largest palindrom product

The program is divided into several files for convenience:
* header.h	- header file containing plug-in libraries and function prototypes;
* funcs.c	- contains implementation of functions;
* main.c	- program source code;
* main		- executable program file.

The project also contains a `tests` folder with unit tests of functions used in the program.

In addition, there is a `timelib.h` library in separate folder. It's used to measure the program running time.


## header.h
 
Using the design:
```
#ifndef HEADER
#define HEADER
#endif
```
... the file is protected from being included again.

* The `<time.h>` header file allows you to work with time;
* `<assert.h>` is required for error handling.
 
The `"header.h"` file contains three functions:
* `invert(int num)`			- takes a number (12345) and returns it inverted (54321);
* `is_palindrome(int num)`	- returns `true` if the number is a palindrome, otherwise `false`;
* `get_max_pal(int prev_max, int num1, int num2)` 	- iterates through the factors (`num1` and `num2`) recursively and calculates the maximum product of its, which is a palindrome. The `num1` value is a constant and `num2` varies from `num2` to `0`. The function takes the previous maximum value `prev_max` also. It's compared with the value calculated by the function and maximum of its is returned.


## timerlib.h - library for measuring program running time
This header file describes the data structures and prototypes (declarations) of all functions contained in the library.

The header file `<time.h>` allows you to work with time.

The file `"timerlib.h"` contains three functions:
* `timer_start`	- starts a timer and stores the current time in the `time` union (integer type clock_t);
* `timer_stop`	- stops the timer and calculates the program execution time in seconds, stores it in `time` (in real form - type double);
* `timer_show`	- displays the operating time on the screen, with an accuracy of six decimal places.

The `union time_u` type union is used to store two different types of time:
* clock_t	- to measure program running time;
* double	- to display the results of work on the screen in real form.


## main.c
This file contains the main program logic.

We include standard libraries and necessary files:
* `<stdio.h>` - I/O library. It allows to use of the `printf()` function.

The program algorithm is based on enumerating the factors and searching for the answer amount them:
* we go through the `num1` factor in a loop;
* `num2` - by recursion.

Since the factors go from larger to smaller, when recursively searching `num2` the first answer found will stop the recursion. Because each subsequent factor of `num2` will be less then previous one and the product `num1 * num2`, respectively, too.
The search for `num1` will stop when the product of the factors `num1 * num2` exceeds the already founded maximum answer `answ` for same reason.

