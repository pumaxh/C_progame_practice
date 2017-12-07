#include <stdio.h>
#include <math.h>

void separate(double num, char *p_sign, int *p_whole, double *p_frac);

int main()
{
	double value; /* input - number to analyze */
	char   sn;    /* output - sign of value */
	int    whl;   /* output - whole number magnitude of value */
	double fr;    /* output - fractional part of value */

	/* Gets data */
	printf("Enter a value to analyze> ");
	scanf("%lf", &value);

	/* Separates data value into three parts */
	separate(value, &sn, &whl, &fr);

	printf("Parts of %.4f\n sign: %c\n", value, sn);
	printf(" whole number magnitude: %d\n", whl);
	printf(" fractional part: %.4f\n", fr);

	return 0;
}

/*
 * Separates a number into three parts: a sign(+, -, or blank), 
 * a while number magnitude, and a fractional part.
 */

void separate(double num,
              char *p_sign, int *p_whole, double *p_frac)
{
    double magnitude; /* local variable - magnitude of num */
    /* Determines sign of num */
    if (num < 0)
        *p_sign = '-';
    else if (0 == num)
        *p_sign = ' ';
    else
        *p_sign = '+';
    /* Finds magnitude of num (its absolute value) and
     * separates it into whole and fractional parts
     */

	magnitude = fabs(num);
    *p_whole = floor(magnitude);
    *p_frac = magnitude - *p_whole;
}
