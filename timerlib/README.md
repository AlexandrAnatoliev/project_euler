# timerlib - static library for measuring program running time

The library consists of two files:
* timerlib.h	- library header file
* libtimer.a	- object file

The project contains two folders also: 
* sourse	- contains a file with the source code of the library functions
* tests 	- tests to check the functionality of the library

## timerlib.h
This header file describes the data structures and prototypes (declarations) of all functions contained in the library.

The header file `<time.h>` allows you to work with time.

The file `"timerlib.h"` contains three functions:
* `timer_start`	- starts a timer and stores the current time in the `time` union (integer type clock_t);
* `timer_stop`	- stops the timer and calculates the program execution time in seconds, stores it in `time` (in real form - type double);
* `timer_show`	- displays the operating time on the screen, with an accuracy of six decimal places.

The `union time_u` type union is used to store two different types of time:
* clock_t	- to measure program running time;
* double	- to display the results of work on the screen in real form.
