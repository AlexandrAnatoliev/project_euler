// test_funcs.c  

#ifndef TEST_FUNCS_C       			// multiple file inclusion protection
#define TEST_FUNCS_C

#include "test_funcs.h"

bool func_response_is_correct(int expect_res, int num, int (*func)(int))
{
    if(expect_res == func(num))
    {
        printf("OK: %d == func(%d)\n", expect_res, num);
        return true;
    }
    
    else
    {
        printf("ERROR: (espect_res == %d) != (%d == func(%d))\n", expect_res, func(num), num); 
        return false;
    }
}

#endif
