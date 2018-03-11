/*
  *  Displays each elemental component of a compound
  */

#include <stdio.h>
#include <string.h>

#define CMP_LEN 30 /* size of string to hold a compound */
#define ELEM_LEN 10 /* size of string to hold a component */

int main()
{
    char compound[CMP_LEN]; /* string represeting a compound */
    char elem[ELEM_LEN];    /* one elemental component */
    int first, next;

    /* Gets data string represeting compound  */
    printf("Enter a compound >");
    scanf("%s", compound);

    /* Display each elemental component. These are identified by a
        * initial capital letter
        */
    first = 0;
    for (next = 1; next < strlen(compound); ++next)
    {
        if (compound[next] >= 'A' && compound[next] <= 'Z')
        {
            strncpy(elem, &compound[first], next - first);
            elem[next - first] = '\0';
            printf("%s\n", elem);
            first = next;
        }
    }

    /* Display the last component */
    printf("%s\n", strcpy(elem, &compound[first]));

    return 0;
}

