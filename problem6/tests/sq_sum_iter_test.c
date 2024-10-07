// sq_sum_iter_test.c - problem 6

#include "../funcs.c"
#include "test_funcs.c"

int main(void)
{
    func_response_is_correct(3025, 10, get_sq_sum_iter);
    
    return 0;
}
