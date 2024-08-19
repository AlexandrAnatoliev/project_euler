// timerlib.c - source code for the static library

#include <stdio.h>
#include <time.h>
#include "../timerlib.h"

union time_u timer_start(void)
{
	union time_u time;
	time.clk = clock();													// note the current time
	
	return time;
}

union time_u timer_stop(union time_u start_time)
{
	clock_t end = clock();												// finish time 
	union time_u stop_time;

	stop_time.dbl = (double)(end - start_time.clk) / CLOCKS_PER_SEC;	// save the measured time

	return stop_time;
}

int timer_show(union time_u time)
{
	printf("\nruntime = %f sec\n\n", time.dbl);							// output to screen

	return 0;
}
