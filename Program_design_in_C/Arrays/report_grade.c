#include <stdio.h>
#include <string.h>

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


int fill_num(char *token,int token_len, int *num)
{
    int i, total = 0;

    for(i = 0; i < token_len; ++i)
    {
        if (!IS_VALID_NUM(token[i]))
        {
            *num = 0;
            return PARAM_ERROR;
        }
        total = total * 10 + (token[i] - '0');
    }
    *num = total;
    return SUCCESS;
}

int get_num_ans(char line_buf[], int *num, char ans_buf[])
{
    char *token;
    char div[] = " ";

    if (NULL == line_buf || NULL == ans_buf)
    {
        return PARAM_ERROR;
    }

    token = strtok(line_buf, div);
    fill_num(token, strlen(token), num);

    token = strtok(NULL, div);
    memcpy(ans_buf, token, strlen(token));

    return 0;
}

int f_get_answers()
{
    FILE *fp;
    char *path = "examdat.txt";
    char line_buf[101];
    int  num, i;
    char ans_buf[100];
    BOOL first_line = TRUE;
    
    fp = fopen(path, "r");
    if (NULL == fp)
    {
        printf("Open exam data file fail.\n");
        return FILE_NOT_EXIST;
    }

    while (SUCCESS == get_line_from_file(fp, line_buf))
    {
        if (0 != get_num_ans(line_buf, &num, ans_buf))
        {
            printf("Prase line fail.\n");
            return PARSE_FAIL;
        }

        if (first_line)
        {
            printf("          Exam Report\n");
            printf("Question   ");
            for (i = 0; i < num; ++i)
            {
                printf("%d ", i);
            }
            printf("\nAnswer     ");
            for (i = 0; i < num; ++i)
            {
                if(i != num - 1)
                    printf("%c ", ans_buf[i]);
                else
                    printf("%c\n", ans_buf[i]);
            }
            first_line = FALSE;
        }
    }

    return 0;
}

int get_line_from_file(FILE *fp, char line_buf[])
{
    if (NULL == fp)
    {
        line_buf[0] = 0;
        return FILE_NOT_EXIST;
    }
    if(NULL != fgets(line_buf, 101, fp))
    {
         return SUCCESS;
    }
    
    line_buf[0] = 0;
    return GET_LINE_FAIL;
}

int main(void)
{
    f_get_answers();
}
