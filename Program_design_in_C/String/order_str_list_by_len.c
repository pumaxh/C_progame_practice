#include <stdio.h>
#include <string.h>

#define BOOL    int
#define TRUE    1
#define FALSE   0
#define STR_SIZ (256)

int len_sort(char str_list[][], fill, num)
{
    size_t min_len, len;
    int loop, index_of_min;

    index_of_min = fill;
    min_len = strlen(str_list[fill]);

    for(loop = fill; loop < num; ++loop)
    {
            if(len < min_len)
            {
                min_len = len;
                index_of_min = loop;
            }
    }
    return index_of_min;
}

void order_str_by_len(char str_list[][STR_SIZ], int str_num_in_list)
{
    int loop = 0;
    char *tem;
    for(loop = 0; loop < str_num_in_list; ++loop)
    {
        index_of_min = len_sort(str_list + loop, str_num_in_list - loop);
        if(index_of_min != loop)
        {
            tem = str_list[index_of_min];
            str_list[index_of_min] = str_list[loop];
            str_list[loop] = tem;
        }
    }
}

int main()
{
    
}

