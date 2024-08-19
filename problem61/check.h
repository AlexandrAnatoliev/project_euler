// check.h - макросы для проверки элементов программы

#ifndef CHECK       // multiple file inclusion protection
#define CHECK

#include <time.h>   // for clock_t, clock(), CLOCKS_PER_SEC

// #define CNT 100
#define CNT_INIT(CNT) \
int count = CNT;

#define CHECK_SHOW \
if (count > 0) \
{count--;\
for(int i = 0; i < ptr->figure.name; i++) \
printf("    "); \
printf("%d (%d)\n", ptr->figure.value, ptr->figure.number);}

		
// operation:		measuring the program running time
// precondition:	double time_spent = 0.0;	create a variable to store code execution time
//					clock_t begin = clock();	timer START
// postcondition:	clock_t end = clock();		timer STOP
//					time_spent += (double)(end - begin) / CLOCKS_PER_SEC; 
//												measure operating time in seconds


#endif
