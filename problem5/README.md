# Project Euler, problem 5: Smallest multiple

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
```
#ifndef HEADER
#define HEADER
#endif
```
... protect the file from being included again.

The **assert.h>** header file allows you to handle errors.

The **"header.h"** file contains three functions:
* `long get_nod_iter(long, long)`   - takes two natural numbers and returns its greatest common divisor, calculated iteratively;
* `long get_nod_rec(long, long)`    - takes two natural numbers and returns its greatest common divisor, calculated by recursion;
* `long get_nok(long, long, long(*get_nod)(long, long))` - takes two natural numbers and a pointer to a function that calculates the greatest common divisor. Returns the least common multiple of numbers. The calculation method depends on the specific implementation of the function being accepted.


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

The calculation algorithm is the same for both options (iterative and recursion). The greatest common multiple for the entire series of numbers is calculated sequentially:
* answ = lcm(1, 2) = 2;
* answ = lcm(2, 3) = 6;
* answ = lcm(6, 4) = 12;
* answ = lcm(12, 5)= ... and so on.


## test_funcs.h
Contains function declarations for testing.

`bool func_response_is_correct(long, long, long, long(*func)(long, long))` - the function checks the correctness of the result returned by the function. It accepts the expected result, the values of the checked function arguments, and a pointer to it. Prints a message about  the correctness/incorrectness of the checked function and returns **true** or **false** depending on the check results.


## scripts/
Scripts for automated program debugging.

### `compile_and_run`
Used to compile and run test files.

When called, it takes a file name:
`./compile_and_run iter_test.c`

Then it compiles it itself:
`gcc ../tests/iter_test.c`
... and runs it:
`./a.out`

### run_tests
The script records the test file names, which it compiles and runs when launched. 
`./run_tests` - run script.

### main_run
Builds the `main.c` file with the `timerlib` library, compiles and runs it.

`gcc -c ../main.c` - we obtain the `main.o` object file from source code file (`main.c`).

Let's decipher the `gcc -o main main.o -L../.. -ltimer` command:
* `gcc`     - compile the executable file;
* `-o main` - created file name;
* `main.o`  - name of the file being compiled;
* `-L../..` - address of the directory where the library files are located (in this case, relative) **../..** - means a directory two levels higher;
* After `-l` the library name is written without prefix and suffix (**libtimer.a** is shortened to **timer**).

### Using scripts

After writing the scripts, you need to make them executable by the commands:
```
chmod +x compile_and_run
chmod +x run_tests
chmod +x main_run
```

Next, after each change to the program files, we run tests:
`./run_tests`
 
If all tests pass, recompile and run the program:
`./main_run`
