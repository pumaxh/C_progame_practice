/* 
 * Compute the mean and stadard deviation of an array of data and displays
 * the difference between each value and the mean.
 */

#include <stdio.h>
#include <math.h>

#define MAX_ITEM 8 /* maximum number of items in list of data */
#define BOOL     int
#define TRUE     1
#define FALSE    0

BOOL is_prime(unsigned int number)
{
    int i;
    for (i = 2; i < (number / 2 + 2); i++)
    {
        if(!(number % i))
        {
            return FALSE;
        }
    }
    return TRUE;
}

unsigned int get_a_prime(unsigned int begin_num)  /* get first prime number from begin_num */
{
    while(!is_prime(begin_num))
    {
        begin_num++;
    }
    return begin_num;
}

unsigned int get_nth_prime(unsigned int n) /* get n'th prime number */
{
    int i, count = 1, prime, begin_num;
    if(1 == n)
    {
        return 2;
    }
    
    begin_num = 3;
    while(count < n)
    {
        prime = get_a_prime(begin_num);
        count++;
        if(count == n)
        {
            return prime;
        }
        begin_num = prime + 1;
    }
}

int main(void)
{
#if 0        
    double x[MAX_ITEM],
           mean,
           st_dev,      /* standard deviation of the data */
           sum,
           sum_sqr;     /* sum of the squares of the data */
    int    i;

    /* Gets the data */
    printf("Enter %d numbers separated by blanks or <return>\n", MAX_ITEM);
    for (i = 0; i < MAX_ITEM; i++)
    {
        scanf("%lf", &x[i]);
    }

    /* Computes the sum and the sum of the squares of all data */
    sum = 0;
    sum_sqr = 0;
    for (i = 0; i < MAX_ITEM; i++)
    {
        sum    += x[i];
        sum_sqr = x[i] * x[i];
    }

    /* Computes and prints the mean and standard deviation */
    mean = sum / MAX_ITEM;
    st_dev = sqrt(sum_sqr / MAX_ITEM - mean * mean);
    printf("The mean is %.2f.\n", mean);
    printf("The standard deviation is %.2f.\n", st_dev);
    printf("Index     Item     Difference\n");
    for (i = 0; i < MAX_ITEM; i++)
    {
        printf("%3d%4c%8.2f%5c%8.2f\n", i, ' ', x[i], ' ', x[i] - mean);
    }
#endif
    unsigned int m;
    m = get_nth_prime(5);
    printf("The 5'th prime is:%u\n", m);

    return 0;
}
