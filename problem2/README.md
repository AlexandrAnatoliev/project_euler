# Project Euler problem2: Even Fibonacci Numbers

For convenience, the program is divided into several files:
* header.h
* funcs.c
* timer.h
* main_recurs.c
* main_array.c


## File header.h
Contains declarations of functions used in the program.

Using the design:
```
#ifndef HEADER
#define HEADER
#endif
```
...the file is protected from being included again.

Since we solve the problem in two ways, we will need two functions:
* The `int get_fib_recurs(int ser_num)` function takes the ordinal number of the desired Fibonacci number and searches for it recursively.
* `int get_next_fib(int array[])` takes an array with the last two numbers in a series, calculates the next number and updates the contents of the array.


## File funcs.c
Contains a release of the functions used in the program.

The file is protected from being re-enabled.
Function declarations are included using `"header.h"`.
The assertion library is included using the header file `<assert.h>`. It is necessary for error handling when debugging the program.

If the assertion accepted by the `assert()` macro is false:
* the macro outputs an error message to the standard error stream,
* the `abort()` function is called, which terminates program execution.

When `assert()` terminates program execution, it displays:
* failed test (condition),
* name of the file containing this test,
* line number where the test is located.


## timer.h
The file is used to measure the program's performance.

The file is protected from being re-enabled.
The header file `<time.h>` allows you to work with time.

The file `"timer.h"` contains three macros:
* `TIMER_START` - creates a variable to measure code execution time and starts the timer,
* `TIMER_STOP` - stops the timer and calculates the program execution time in seconds,
* `TIMER_PRINT` - displays the operating time on the screen.


## main_recurs.c
A recursive way to solve a problem.

All header files used in the program are included.

The timer starts.

In the `main_recurs.c` function:
* ordinal numbers are sorted out,
* using the recursive function `get_fib_recurs()` the value of the Fibonacci number is calculated,
* even values are added,
* the cycle is interrupted when the next Fibonacci number exceeds 4,000,000.

The timer stops and the calculation results and time are displayed.


## main_array.c
An array is used to store the values of the last two numbers

All header files are connected in the same way.

The array is initialized with the values of the first two numbers of the Fibonacci series.
The answer is immediately entered as 2, because the search will continue from the next numbers.
The timer starts.

In the `main_array.c` function:
* a pointer to an array is passed to the `get_next_fib()` function;
* the value of the next Fibonacci number is calculated and the contents of the array are updated;
* even values are added;
* the cycle is interrupted when the next Fibonacci number value exceeds 4000000.

The timer stops and the results are displayed.

