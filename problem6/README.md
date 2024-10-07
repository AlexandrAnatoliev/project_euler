# Project Euler, problem 6: Sum square difference

For convenience, the program is divided into several files:
* `header.h`        - a header file containing the included libraries and function prototypes;
* `funcs.c`	        - contains the implementation of functions;
* `main.c`	        - program source code;
* `main`	        - executable program file;

The project also contains folders:
* `tests/`   - unit tests of functions used in the program, includes:
    - `test_funcs.h`    - a header file containing functions to be included for testing;
    - `test_funcs.c`    - contains the implementation of testing functions;
    - files with tests for each function.

* `scripts/` - scripts to speed up program debugging;
    - `main_run`        - builds, compiles and runs the **main.c** file with the **timerlib** library;
    - `compile_and_run` - compiles and runs a test file accepted by the script as an argument;
    - `run_tests`       - compiles and runs tests of functions in a list.

In addition, there is a library in a separate **timerlib/** folder, which is used to measure the program's running time.


## header.h

The design:
```c
#ifndef HEADER
#define HEADER
#endif
```
... protect the file from being included again.

The **assert.h>** header file allows you to handle errors.

The **"header.h"** file contains four functions:
* `int get_sq_sum_iter(int)`    - calculates the square of the sum of numbers iteratively. Takes a number of natural numbers and returns its sum square, starting from 1;
* `int get_sum_sq_iter(int)`    - calculates the sum of the squares (iterative version);
* `int get_sq_sum_math(int)`    - calculating the square of the sum of numbers (math version);
* `int get_sum_sq_math(int)`    - calculating the sum of the squares (math version).


## timerlib.h - program execution time measuring library
This header file describes the data structures and prototypes (declarations) of all the functions contained in the library.

The **<time.h>** header file allows you to work with time.

The **"timerlib.h"** file contains three functions:
* `union time_u timer_start()`              - starts the timer and stores the current time in the **time** union (**clock_t** integer type);
* `union time_u timer_stop(union time_u)`   - stops the timer and calculates the program execution time in seconds, saves it in **time** (in real form - **double** type);
* `int timer_show(union time_u)`            - displays the running time on the screen, with a preciosity of six decimal places.

The **union time_u** type is used to store time of two different types:
* `clock_t` - to measure the program running time;
* `double`  - to display the work results on screen in real form.


## main.c

This file contains the **main()** function and the main program logic.

We connect standard libraries and necessary files:
**<stdio.h>**   - I/O library. Allows you to use **printf()** function.

Before the calculations start:
`timer_start()` - the timer is started,
...and after the calculations are finished:
`timer_stop()`  - it is stopped.

The calculation algorithm is the same for both options. First, the square of the sum of numbers is calculated, after which the sum of squares is subtracted from it.

## test_funcs.h
Contains function declarations for testing.

`bool func_response_is_correct(int, int, int(*func)(int))` - the function checks the correctness of the result returned by the function. It accepts the expected result, the values of the checked function arguments, and a pointer to it. Prints a message about  the correctness/incorrectness of the checked function and returns **true** or **false** depending on the check results.


## scripts/
Scripts for automated program debugging.

### `compile_and_run`
Used to compile and run test files.

When called, it takes a file name:
`./compile_and_run sq_sum_iter_test.c`

### run_tests
The script records the test file names, which it compiles and runs when launched. 
`./run_tests` - run script.

### main_run
Builds the `main.c` file with the `timerlib` library, compiles and runs it.

### Using scripts

After each change to the program files, we run tests:
`./run_tests`
 
If all tests pass, recompile and run the program:
`./main_run`
