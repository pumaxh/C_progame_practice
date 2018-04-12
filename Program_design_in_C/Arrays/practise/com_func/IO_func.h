#ifndef IO_FUNC_H
#define IO_FUNC_H

#include <stdio.h>

#define SUCCESS         0
#define FILE_NOT_EXIST  1
#define GET_LINE_FAIL   2
#define PARSE_FAIL      3

int get_line_from_file(FILE *fp, char line_buf[], int buf_size);

#endif

