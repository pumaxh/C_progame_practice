#include <stdio.h>
#include <math.h>

#define exchange(num1, num2) \
        do \
        {  \
            num1 = num1 + num2;  \
            num2 = num1 - num2; \
            num1 = num1 - num2;  \
        }while(0)

void get_3_num(double *n1, double *n2, double *n3)
{
    printf("Enter three numbers> ");
    scanf("%lf%lf%lf", n1, n2, n3);
}

void order(double *num1, double *num2)
{
    if (*num1 > *num2)
    {
        exchange(*num1, *num2);   
    }
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
