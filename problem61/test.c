// test.c - тесты

#include <stdio.h>
#include "arr.h"
#include "arr.c"

int main(void)
{
	printf("\nTest \"arr.h\" start\n\n");
		
	printf("COLUMNS = %d\n", COLUMNS);
	printf("ROWS = %d\n", ROWS);
	
	printf("ARR_INIT\n");	
	ARR_INIT
	
	printf("show_arr\n");
	show_arr(arr);
	
	printf("push_flag(arr, 0, 0)\n");
	push_flag(arr, 0, 0); 
	show_arr(arr);

	printf("push_flag(arr, 6, 6)\n");
	push_flag(arr, 6, 6); 
	show_arr(arr);

	printf("push_flag(arr, 1, 1)\n");
	push_flag(arr, 1, 1); 
	show_arr(arr);

	printf("push_flag(arr, 3, 3)\n");
	push_flag(arr, 3, 3); 
	show_arr(arr);
	
	printf("del_flag(arr, 0, 0)\n");
	del_flag(arr, 0, 0); 
	show_arr(arr);

	printf("del_flag(arr, 6, 6)\n");
	del_flag(arr, 6, 6); 
	show_arr(arr);

	printf("del_flag(arr, 1, 1)\n");
	del_flag(arr, 1, 1); 
	show_arr(arr);

	printf("del_flag(arr, 3, 3)\n");
	del_flag(arr, 3, 3); 
	show_arr(arr);
	return 0;

}
