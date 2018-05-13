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

BOOL multi_thread_change_var_6()
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

void set_flag(BOOL *p_share_flag)
{
    puts("Plz enter a char");
    getchar();
    if(pthread_mutex_lock(&lock) != 0)
        printf("Error Locking Mutex\n");

    *p_share_flag = 0;

    if(pthread_mutex_unlock(&lock) != 0)
            printf("Error Unlocking Mutex\n");
}

void *loop_with_flag(void *argument)
{
    int  count = 0;
    BOOL flag;

    if(NULL == argument)
        return NULL;
    while(flag)
    {
        count++;
        printf("Count = %d\n",count);
        sleep(1);

        if(pthread_mutex_lock(&lock) != 0)
            printf("Error Locking Mutex\n");

        flag = *(BOOL *) argument;

        if(pthread_mutex_unlock(&lock) != 0)
            printf("Error Unlocking Mutex\n");   
    }
    return NULL;
}

BOOL multi_thread_share_flag_7()
{
    pthread_t sub_tid;
    BOOL      share_flag = TRUE;

    if(pthread_mutex_init(&lock, NULL) !=0 )
    {
        puts("Error Initializing The Mutex Lock");
        return FALSE;
    }
    if(pthread_create(&sub_tid, NULL, loop_with_flag, (void *)&share_flag) != 0)
    {
        puts("Error Creating The Sub Thread");
        return FALSE;
    }

    set_flag(&share_flag);

    if(pthread_join(sub_tid, NULL) != 0)
    {
        puts("Error Joining The Sub Thread");
        return FALSE;
    }
    return TRUE;
}

void *show_arg(void *argument)
{
    if(NULL == argument)
        return NULL;
    
    printf("New Thread Argument = %d\n", *(int *)argument);
    return NULL;
}

BOOL multi_thread_show_arg_8()
{
    pthread_t sub_tid;
    int       sub_arg = rand()%10;

    if(pthread_mutex_init(&lock, NULL) !=0)
    {
        puts("Error Initializing The Mutex Lock");
        return FALSE;
    }

    if(pthread_create(&sub_tid, NULL, show_arg, (void *)&sub_arg) != 0)
    {
        puts("Error Creating The Sub Thread");
        return FALSE;
    }

    if(pthread_join(sub_tid, NULL) != 0)
    {
        puts("Error Joining The Sub Thread");
        return FALSE;
    }
    return TRUE;
}
