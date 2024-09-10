// get_nok_test.c - problem 5

#include <stdbool.h>
#include <stdio.h>
#include "../funcs.c"

bool check_nok(long num1, long num2, long (*func) (long, long));

int main(void)
{
    check_nok(1, 23, get_nod_iter);
    check_nok(456,7891, get_nod_rec);
    check_nok(11121,314151, get_nod_iter);
    check_nok(6171819,20212223, get_nod_rec);
    check_nok(242526272,8293031323, get_nod_iter);
    
    return 0;
}

bool check_nok(long num1, long num2, long (*func)(long, long))
{
    long nok = get_nok(num1, num2, func);
    
    if(nok % num1)
    {
        printf("Числа не делятся нацело: %ld % %ld == %ld\n", nok, num1, nok % num1);
        return false;
    }   
    
    if(nok % num2)
    {
        printf("Числа не делятся нацело: %ld % %ld == %ld\n", nok, num2, nok % num2);
        return false;
    }   
    
    printf("check_nok(%ld, %ld) == %ld is OK\n", num1, num2, nok);
 
    return true;
}
