// iter_test.c - problem 5

#include "../funcs.c"
#include "test_funcs.c"

int main(void)
{
    func_response_is_correct(3, 12, 15, get_gcd_iter);
    func_response_is_correct(14, 28, 42, get_gcd_iter);
    func_response_is_correct(325, 650, 975, get_gcd_iter);
    func_response_is_correct(1234, 2468, 1234, get_gcd_iter);
    
    return 0;
}
