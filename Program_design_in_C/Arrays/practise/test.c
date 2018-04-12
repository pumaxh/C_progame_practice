#include <stdio.h>
#include <string.h>
#include "com_func/IO_func.h"

int main()
{
    FILE *fp;
    char line_buf[1024];

    fp = fopen("gravity_data.txt", "r");
    if (NULL == fp)
    {
        return FILE_NOT_EXIST;
    }

    while (SUCCESS == get_line_from_file(fp, line_buf, 1023))
    {
        printf("[%s], [%u]\n", line_buf, (unsigned int)strlen(line_buf));
    }

    return 0;
}
