#include <stdio.h>
#include "test_func.h"

int main()
{
    double sum, avg;
    sum_n_avg(1.1, 1.2, 1.3, &sum, &avg);
    printf("Test result: sum = %f, avg = %f\n", sum, avg);
    return 0;
}
