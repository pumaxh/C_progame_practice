#include <stdio.h>
#include <math.h>
#include "complex_numbers.h"

#define SQUARE(num1, num2)      ((num1) * (num1) + (num2) * (num2))

int main(void)
{
    complex_t com1, com2;
    /* Gets two complex numbers */
    printf("Enter the real and imaginary parts of a complex number\n");
    printf("separated by a space> ");
    scan_complex(&com1);
    printf("Enter a second complex number> ");
    scan_complex(&com2);

    /* Forms and displays the sum */
    printf("\n");
    print_complex(com1);
    printf("+");
    print_complex(com2);
    printf("=");
    print_complex(add_complex(com1, com2));

    /* Forms and displays the difference */
    printf("\n\n");
    print_complex(com1);
    printf("-");
    print_complex(com2);
    printf("=");
    print_complex(subtract_complex(com1, com2));

    /* Forms and displays the absolute value of the first number */
    printf("\n\n|");
    print_complex(com1);
    printf("| = ");
    print_complex(abs_complex(com1));
    printf("\n");

    return 0;
}

/*
  * Complex number input function returns standard scanning error code
  * 1 => valid scan, 0 => error, negative EOF value => end of file
  */
int scan_complex(complex_t *c)
{
    int status;
    status = scanf("%lf%lf", &c->real, &c->imag);
    if (status == 2)
    {
        status = 1;
    }
    else if (status != EOF)
    {
        status = 0;
    }

    return status;
}

/*
  * Complex output function displays value as (a + bi) or (a - bi),
  * dropping a or b if they round to 0 unless both round to 0
  */
void print_complex(complex_t c)
{
    double a, b;
    char   sign;

    a = c.real;
    b = c.imag;

    printf("(");
    if (   fabs(a) < .005
        && fabs(b) < .005)
    {
        printf("%.2f", 0.0);
    }
    else if(fabs(b) < .005)
    {
        printf("%.2f", a);
    }
    else if(fabs(a) < .005)
    {
        printf("%.2fi", b);
    }
    else
    {
        if (b < a)
        {
            sign = '-';
        }
        else
        {
            sign = '+';
        }
        printf("%.2f %c %.2fi", a, sign, fabs(b));
    }

    printf(")");
}

/*
  * Returns sum of complex values c1 and c2
  */
complex_t add_complex(complex_t c1, complex_t c2)
{
    complex_t csum;

    csum.real = c1.real + c2.real;
    csum.imag = c1.imag + c2.imag;

    return csum;
}

/*
  * Returns difference c1 - c2
  */
complex_t subtract_complex(complex_t c1, complex_t c2)
{
    complex_t cdiff;
    cdiff.real = c1.real - c2.real;
    cdiff.imag = c1.imag - c2.imag;

    return cdiff;
}

/* 
  * Returns product of complex values c1 and c2
  */
complex_t multiply_complex(complex_t c1, complex_t c2)
{
    complex_t cmult;
    cmult.real = c1.real * c2.real - c1.imag * c2.imag;
    cmult.imag = c1.real * c2.imag + c1.imag * c2.real;

    return cmult;
}

/*
  * Returns quotient of complex values (c1 / c2)
  */
complex_t divide_complex(complex_t c1, complex_t c2)
{
    complex_t cdivid;
    cdivid.real = (c1.real * c2.real + c1.imag * c2.imag)/SQUARE(c2.real, c2.imag);
    cdivid.imag = (c2.real * c1.imag - c1.real * c2.imag)/SQUARE(c2.real, c2.imag);

    return cdivid;
}

/*
  * Returns absolute value of complex number c
  */
complex_t abs_complex(complex_t c)
{
    complex_t cabs;
    cabs.real = sqrt(SQUARE(c.real, c.imag));
    cabs.imag = 0;

    return cabs;
}

