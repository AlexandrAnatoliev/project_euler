// timer.h

#ifndef TIMER       			// multiple file inclusion protection
#define TIMER

#include <time.h>   			// for clock_t, clock(), CLOCKS_PER_SEC

#define TIMER_START double time_spent = 0.0; clock_t begin = clock(); 
#define TIMER_STOP clock_t end = clock(); time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
#define TIMER_PRINT printf("runtime = %f sec\n", time_spent);

// operation:					measuring the program running time
// precondition:	TIMER_START	"create a variable to store code execution time and timer start
//					TIMER_STOP	"timer stop and measure operaing time in seconds"
// postcondition:	TIMER_PRINT	"print the run time"

#endif
