// testlib.c - tests for checking the timerlib.h library

#include <stdio.h>
#include "../timerlib.h"

int main(void)
{
	int cnt = 6;	// number of iterations
	int limit = 1;	// limit of iterating over values in a loop

	while(cnt)
	{	
		union time_u time;

		time = timer_start();
		for(int i = 1; i < limit; i++)
		{
			for(int j = 1; j < limit; j++)
				i/j;
		}

		time = timer_stop(time);
		printf("Iterating (in two loops) numbers i and j up to %d and calculating i/j took:", limit); 
		timer_show(time);

		limit *= 10;
		cnt--;
	}

	return 0;
}
