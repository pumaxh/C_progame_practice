#ifndef MULTI_TASK
#define MULTI_TASK

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <wait.h>

#ifndef BOOL
#define BOOL int
#endif

#ifndef TRUE
#define TRUE  (1)
#endif

#ifndef FALSE
#define FALSE (0)
#endif

#ifndef NULL
#define NULL ((void *) 0)
#endif

BOOL create_new_thread_5();
BOOL multi_thread_change_var();

#endif
