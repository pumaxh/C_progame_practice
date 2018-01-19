#ifndef REPORT_H
#define REPORT_H

#define FALSE           0
#define TRUE            1
#define PARAM_ERROR    -1
#define SUCCESS         0
#define FILE_NOT_EXIST  1
#define GET_LINE_FAIL   2
#define PARSE_FAIL      3
#define IS_VALID_ANS(c) (c <= 'd' && c >= 'a')
#define IS_VALID_NUM(n) (n <= '9' && n >= '0')

typedef int BOOL;

int get_line_from_file(FILE *fp, char line_buf[]);

#endif
