// timer.h - Are using to measure and print the program running time

#ifndef TIMER       // multiple file inclusion protection
#define TIMER

#include <time.h>   // for clock_t, clock(), CLOCKS_PER_SEC

#define TIMER_START double time_spent = 0.0; clock_t begin = clock(); 
#define TIMER_FINISH clock_t end = clock(); time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
// operation:		measuring the program running time
// precondition:	double time_spent = 0.0;	create a variable to store code execution time
//					clock_t begin = clock();	timer START
// postcondition:	clock_t end = clock();		timer STOP
//					time_spent += (double)(end - begin) / CLOCKS_PER_SEC; 
//												measure operating time in seconds

#define SHOW_TIME printf("runtime = %f\n", time_spent);
// pass the MACRO to print the run time

#endif
