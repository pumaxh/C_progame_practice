#include <stdio.h>
#include "test_func.h"

int main()
{
    double one, two, three, sum, avg;
	get_3_num(&one, &two, &three);
	order(&one, &two);
	order(&one, &three);
	order(&two, &three);
    printf("Test result: the numbers in ascending order are: %.2f %.2f %.2f\n",
		   one, two, three);
    return 0;
}
