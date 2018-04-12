#include <stdio.h>
#include "com_func/IO_func.h"

#define LINE_BUF_SIZE 1024

char g_line_buff[LINE_BUF_SIZE];

void fget_point_mass()
{
    FILE *fp;
    fp = fopen("gravity_data.txt", "r");

    if (NULL == fp)
    {
        return FILE_NOT_EXIST;
    }

    if (NULL = fgets(line_buff, 512, fp))
    {
        printf("Get line fail.\n");
        return 1;
    }

}
