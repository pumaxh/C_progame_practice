#include "exercise.h"

int g_var = 0;
pthread_mutex_t lock;   /* Mutual exclusion id */

void *sub_thread(void *argument)
{
    printf("Sub Thread Started, Self PID:%d.\n", getpid());
    sleep(5);
    printf("Sub Thread Finished.\n");
}

BOOL create_new_thread_5()
{
    pthread_t sub_tid; 

    printf("Main Thread Started, Main PID:%d.\n", getpid());
    if(pthread_create(&sub_tid, NULL, sub_thread, NULL) != 0)
    {
        printf("Error Creating The Sub Thread\n");
        return FALSE;
    }
    
    if(pthread_join(sub_tid, NULL) != 0)
    {
        printf("Error Joining The Sub Thread\n");
        return FALSE;
    }
    printf("Main Thread Finished.\n");
    return TRUE; 
}

void *change_var(void *argument)
{
    if(argument == NULL)
        return NULL;

    if(pthread_mutex_lock(&lock) != 0)
        printf("Error Locking Mutex\n");

    g_var++;
    printf("%s Thread Data = %d.\n", (char *)argument, g_var);
    printf("%s Thread call end.\n", (char *)argument);

    if(pthread_mutex_unlock(&lock) != 0)
            printf("Error Unlocking Mutex\n");
}

BOOL multi_thread_change_var()
{
    pthread_t sub_tid; 

    if(pthread_mutex_init(&lock, NULL) !=0 )
    {
        puts("Error Initializing The Mutex Lock");
    }

    if(pthread_create(&sub_tid, NULL, change_var, (void *)"New") != 0)
    {
        puts("Error Creating The Sub Thread");
        return FALSE;
    }
    change_var((void *)"Main");
    
    if(pthread_join(sub_tid, NULL) != 0)
    {
        puts("Error Joining The Sub Thread");
        return FALSE;
    }

    puts("Main process end!");
    return TRUE;
}
