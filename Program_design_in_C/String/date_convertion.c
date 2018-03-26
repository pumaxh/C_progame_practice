/*
 * Functions to change the representation of a date from a string containing
 * day, month name and year to three integers (month day year) and vice versa
 */

#include <stdio.h>
#include <string.h>

#define STRSIZ    40
#define NOT_FOUND -1

char *nums_to_string_date(char *date_string, int month, int day, int year,
                          const char *month_names[]);
int search(const char*arr[], const char *target, int n);
void string_date_to_nums(const char *date_string, int *monthp, int *dayp, int *yearp,
                         const char *month_names[]);
int main()
{
    const char *month_names[] = {"January", "February", "March", "April", "May",
                           "June", "July", "Augest", "September", "October", 
                           "November", "December"};
    int m, y, mon, day, year;
    char date_string[STRSIZ];
    for (y = 1993; y < 2010; y += 10)
    {
        for (m = 1; m <= 12; ++m)
        {
            printf("%s", nums_to_string_date(date_string, m, 15, y, month_names));
            string_date_to_nums(date_string, &mon, &day, &year, month_names);
            printf(" = %d/%d/%d\n", mon, day, year);
        }
    }
    return 0;
}

/*
 * Takes integers representing a month, day and year and produces a
 * string representation of the same date.
 */
char * nums_to_string_date(char *date_string, int month, int day, int year, 
                           const char *month_names[])
{
    sprintf(date_string, "%d %-10s %d", day, month_names[month -1], year);
    return date_string;
}

/*
 * Searches for target item in first n elements of array arr
 * Returns index of target or NOT_FOUND
 * Pre: target and first n elements of array arr are defined and n>0
 */
int search(const char *arr[], const char *target, int n)
{
    int i, found = 0, where;
    i = 0;
    while (!found && i < n)
    {
        if (0 == strcmp(arr[i], target))
        {
            found = 1;
        }
        else
        {
            ++i;
        }
    }

    if(found)
        where = i;
    else
        where = NOT_FOUND;
    return where;
}

void string_date_to_nums(const char *date_string, int *monthp, int *dayp, int *yearp,
                         const char *month_names[])
{
    char mth_name[STRSIZ];
    int month_index;

    sscanf(date_string, "%d%s%d", dayp, mth_name, yearp);

    month_index = search(month_names, mth_name, 12);

    if (month_index != NOT_FOUND)
    {
        *monthp = month_index + 1;
    }
}
