#include "IO_func.h"
#include "stdio.h"

int get_line_from_file(FILE *fp, char line_buf[], int buf_size)
{
    if (NULL == fp)
    {
        line_buf = NULL;
        return FILE_NOT_EXIST;
    }
    if(NULL != fgets(line_buf, buf_size, fp))
    {
         return SUCCESS;
    }
    
    line_buf = NULL;
    return GET_LINE_FAIL;
}

/*
 * Gets one line of data from standard input. Returns an empty string on end
 * of file. If data line will not fit in allotted space, stores portion that
 * does fit and discards rest of input line.
 **** Error: returns address of space that is immediately deallocated.
 */
char *scanline(void)
{
    char dest[100];
    int i, ch;

    i = 0;
    for (ch = getchar();ch != '\n' && ch != EOF && i < 99; ch = getchar())
    {
        dest[i++] = ch;
    }
    dest[i] = 0;
}

