// test_funcs.c  

#ifndef TEST_FUNCS_C       			// multiple file inclusion protection
#define TEST_FUNCS_C

#include "test_funcs.h"

bool func_response_is_correct(long expect_res, long num1, long num2, long (*func)(long, long))
{
    if(expect_res == func(num1, num2))
    {
        printf("OK: %ld == func(%ld, %ld)\n", expect_res, num1, num2);
        return true;
    }
    
    else
    {
        printf("ERROR: (espect_res == %ld) != (%ld == func(%ld, %ld))\n", expect_res, func(num1, num2), num1, num2); 
        return false;
    }
}

#endif
