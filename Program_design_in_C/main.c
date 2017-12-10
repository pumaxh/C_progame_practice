#include <stdio.h>
#include "test_func.h"

int main()
{
    double one, two, three, sum, avg;
	get_3_num(&one, &two, &three);
    sum_n_avg(one, two, three,  &sum, &avg);
    printf("Test result: sum = %f, avg = %f\n", sum, avg);
    return 0;
}
