#include <stdio.h>
#include <math.h>

void get_3_num(double *n1, double *n2, double *n3)
{
    printf("Enter three numbers> ");
    scanf("%lf%lf%lf", n1, n2, n3);
}

void sum_n_avg(double n1, double n2, double n3,  /* input numbers  */
			   double *p_sum, double *p_avg)     /* output sum and avg */
{
	double sum, avg;
	sum = n1 + n2 + n3;
	*p_sum = sum;
	avg = sum / 3;
	*p_avg = avg;
}
