// get_lcm_test.c - problem 5

#include <stdbool.h>
#include <stdio.h>
#include "../funcs.c"

bool check_lcm(long num1, long num2, long (*func) (long, long));

int main(void)
{
    check_lcm(1, 23, get_gcd_iter);
    check_lcm(456,7891, get_gcd_rec);
    check_lcm(11121,314151, get_gcd_iter);
    check_lcm(6171819,20212223, get_gcd_rec);
    check_lcm(242526272,8293031323, get_gcd_iter);
    
    return 0;
}

bool check_lcm(long num1, long num2, long (*func)(long, long))
{
    long lcm = get_lcm(num1, num2, func);
    
    if(lcm % num1)
    {
        printf("Numbers are not divisible evenly: %ld % %ld == %ld\n", lcm, num1, lcm % num1);
        return false;
    }   
    
    if(lcm % num2)
    {
        printf("Numbers are not divisible evenly: %ld % %ld == %ld\n", lcm, num2, lcm % num2);
        return false;
    }   
    
    printf("check_lcm(%ld, %ld) == %ld is OK\n", num1, num2, lcm);
 
    return true;
}
