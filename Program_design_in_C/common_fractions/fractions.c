/*
 * Adds, subtracts, multiplies and divides common fracions, displaying
 * results in reduced form.
 */


#include <stdio.h>
#include <stdlib.h> /* provide abs func */
#include <math.h>

/* Function prototypes */
void scan_fraction(int *nump, int *denomp);

char get_operator(void);

void add_fractions(int n1, int d1, int n2, int d2,
                   int *n_ans_p, int *d_ans_p);
void multiply_fractions(int n1, int d1, int n2, int d2,
                        int *n_ans_p, int *d_ans_p);

int find_gcd(int n1, int n2);

void reduce_fraction(int *num_p, int *denom_p);

void print_fraction(int num, int denom);

int main(void)
{
    int n1, d1; /* numerator, denominator of first fraction */
    int n2, d2; /* numerator, denominator of second fraciont */
    char op;    /* arithmetic operator + - * or /  */
    char again; /* y or n depending on user's desire to continue */
    int n_ans, d_ans; /* numerator, denominator of answer */

    do
    {
        /* Get a fracion problem */
        scan_fraction(&n1, &d1);
        op = get_operator();
        scan_fraction(&n2, &d2);
        
        /* Computes the result */
        switch (op)
        {
            case '+':
                    add_fractions(n1, d1, n2, d2, &n_ans, &d_ans);
                    break;

            case '-':
                    add_fractions(n1, d1, -n2, d2, &n_ans, &d_ans);
                    break;

            case '*':
                    multiply_fractions(n1, d1, n2, d2, &n_ans, &d_ans);
                    break;

            case '/':
                    multiply_fractions(n1, d1, d2, n2, &n_ans, &d_ans);
        }
        reduce_fraction(&n_ans, &d_ans);

        /* Display problem and result */
        printf("\n");
        print_fraction(n1, d1);
        printf(" %c ", op);
        print_fraction(n2, d2);
        printf(" = ");
        print_fraction(n_ans, d_ans);

        /* Asks user about doing another problem */
        printf("\nDo another problem?(y/n)>");
        scanf(" %c", &again);

    }while(again == 'y' || again == 'Y');
    return 0;
}

/*
 * Gets and returns a valid fraction as its result
 * A valid fraction is of this form: interger/positive interger
 * Pre : none
 */

void scan_fraction(int *p_num, int * p_denom)
{
    char slash;  /* character between numberator and denominator */
    int status;  /* status code returned by scanf indicating 
                    number of valid values obtained */
    int error ;  /* flag indicating presence of an error */
    char discard;/* unprocessed character from input line */
    do
    {
        /* No errors detected yet */
        error = 0;
        
        /* Get a fraction from the user */
        printf("Enter a common fraction as two intergers separated ");
        printf("by a slash> ");
        status = scanf("%d %c%d", p_num, &slash, p_denom);

        /* validate the fraction */
        if (status < 3)
        {
            error = 1;
            printf("Invalid-please read directions carefully\n");
        }
        else if (slash != '/')
        {
            error = 1;
            printf("Invalid-separate numerator and denominator\n");
        }
        else if (*p_denom <= 0)
        {
            error = 1;
            printf("Invalid-denominator must be positive\n");
        }
        /* Discard extra input characters */
        do
        {
            scanf("%c", &discard);
        }while (discard != '\n');
    }while (error);
}

/* Gets and returns a valid arithmetic operator. Skips over newline 
 * characters and permits reentry of operator in case of error
 */
char get_operator(void)
{
    char op;

    printf("Enter an arithmetic operator (+,-,*, or /)\n>");
    for (scanf("%c", &op); 
         op != '+' && op != '-' &&
         op != '*' && op != '/';
         scanf("%c", &op))
    {
        if(op != '\n')
        {
            printf("%c invalid, reenter operate (+,-,*,/)\n> ", op);
        }
    }
    return op;
}

/*
 * Adds fractions represented by pairs of integers.
 * Pre: n1, d1, n2, d2 are defined;
 *      p_nans, p_dans are addresses of type int variables.
 * Post: sum of n1/d1 and n2/d2 is stored in variables pointed 
 *       to by p_nans and p_dans. Result is not reduced.<F9><F10>
 */
void add_fractions(int n1, int d1,          /* input - first fraction */
                   int n2, int d2,          /* input - second fraction */
                   int *p_nans,int *p_dans /* output - sum of 2 fractions */)
{
    int denom,        /* common denominator used for sum (may not be least) */
        numer,        /* numerator of sum */
        sign_factor; /* -1 for a negative, 1 otherwise */
    
    /* Finds a common denominator */
    denom = d1 * d2;

    /* Computes numerator */
    numer = n1 * d2 + n2 * d1;

    /* Adjusts sign (at most, numerator should be negative) */
    if (numer * denom >= 0)
    {
        sign_factor = 1;
    }
    else
    {
        sign_factor = -1;
    }

    *p_nans = numer;
    *p_dans = denom;
}

void multiply_fractions(int n1, int d1, /* input - first fraction */
                        int n2, int d2, /* input - second fraction */
                        int *p_nans,
                        int *p_dans)     /* output - product of 2 fractions */
                       
{
    printf("\nEntering multiply fractions with\n");
    printf("n1 = %d, d1 = %d, n2 = %d, d2 = %d\n", n1, d1, n2, d2);
    *p_nans = n1 * n2;
    *p_dans = d1 * d2;
}

void display_fraction(int n1, int d1, int n2, int d2)
{
    printf("n1 = %d, d1 = %d, n2 = %d, d2 = %d\n", n1, d1, n2, d2);
}

/* Finds greatest common divisor of two integers */
int find_gcd(int n1, int n2)
{
    int gcd, p, q, r;
    p = abs(n1);
    q = abs(n2);

    r = q % p;
    do
    {
        q = p;
        p = r;
        r = q % p;
    }while(r);
    return p;
}
#if 0
    if (n1 < n2)
    {
        tmp = n1;
        n1 = n2;
        n2 = tmp;
    }

    if (n2 == 0)
    {
        return n1;
    }
    return find_gcd(n2, n1%n2);
}
#endif

/* Reduces a fraction by dividing its numerator and denominator 
 * by their greatest common divisor 
 */
void reduce_fraction(int *p_num, int *p_denom)
{
    int gcd;
    gcd      = find_gcd(*p_num, *p_denom);
    *p_num   = *p_num / gcd;
    *p_denom = *p_denom / gcd;
}

void print_fraction(int num, int denom) /* input - numerator & denominator */
{
    printf("%d/%d", num, denom);
}



