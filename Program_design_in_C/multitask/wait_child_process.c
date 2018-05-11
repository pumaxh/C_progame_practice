#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <wait.h>

int main()
{
    pid_t pid;
    int status_val;

    pid = fork();
    if(-1 == pid)
    {
        printf("Fork child process fail.");
    }
    else if(0 == pid)
    {
        
        printf("Child PID:%d\n", getpid());
        sleep(5);
        printf("Child Finished.\n");
    }
    else
    {
        wait(&status_val);
        printf("Parent PID:%d, Parent Finished.\n", getpid());
    }
    return 0;
}