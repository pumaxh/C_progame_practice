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
    unsigned int x[MAX_ITEM];
    int    i;

    /* Get nth prime then insert to array */
    for (i = 0; i < MAX_ITEM; i++)
    {
        x[i] = get_nth_prime(i);
    }

    /* Display array index and content of the array */
    printf("Index     Item\n");
    for (i = 0; i < MAX_ITEM; i++)
    {
        printf("%3d%4c%6u\n", i, ' ', x[i]);
    }
    return 0;
}
