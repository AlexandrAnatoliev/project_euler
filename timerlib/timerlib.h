// timerlib.h - static library for measuring program running time

#include <time.h>

union time_u		// union for storing time
{
	clock_t clk;	// clock_t(long)- for measuring time
	double dbl;		// double		- for displaying as a decimal fraction
};

union time_u timer_start(void);
// operation:		start timer
// precondition:	union time_u - union storing time
// postcondition:	return the current time to union (integer type clock_t)

union time_u timer_stop(union time_u start_time);
// operation:		stop timer
// precondition:	start_time - union storing time
// postcondition:	return the runtime of the program to union (real type double)

int timer_show(union time_u time);
// operation:		вывод времени работы программы
// precondition:	time - union storing time
// postcondition:	operating time is displayed in seconds with an accuracy of six decimal places

