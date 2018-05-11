#include <pthread.h>
#include <stdio.h>
#include <wait.h>
#include <unistd.h>

int get_number();   /* Pump number function prototype */
int get_amount();   /* Pump amount function prototype */

void startup(int *number, pthread_t *ptid);
void cleanup(pthread_t tid);

/* Producer and consumer thread function prototype */
void *producer(void *argument);
void *consumer(void *argument);

#define CAPACITY (1000) /* Storage tank refill capacity */
#define QUANTITY (900)   /* Storage tank refill quantity */

#define FILL_RATE (50)  /* Storage tank fill rate */
#define FLOW_RATE (5)   /* Station pump flow rate */

#define PUMPS     (10)  /* Number of pumps available */

#define VERBOSE   (1)   /* Verbose display on (1) or off(0) */

int terminate;
int inventory;
int pump[PUMPS];

pthread_mutex_t lock;   /* Mutual exclusion id */

int main()
{
    int number;

    pthread_t ptid;
    pthread_t ctid;

    startup(&number, &ptid);

    /* Loop until the user sets the pump number to -1 */
    while(number != -1)
    {
        number = get_number();
        if(number != -1)
        {
            if(pthread_mutex_lock(&lock) != 0)
                printf("Error Locking Mutex\n");
                
            pump[number - 1] = get_amount();

            if(pthread_mutex_unlock(&lock) != 0)
                printf("Error Unlocking Mutex\n");
                
            /* Create a new consumer thread passing in pump number */
            if(pthread_create(&ctid, NULL, consumer, &number) != 0)
                printf("Error Creating The Consumer Thread\n");
        }
    }
    cleanup(ptid);

    return 0;
}

void startup(int *pnumber, pthread_t *ptid)
{
    int count;

    /* Initialize the storage fill terminate to FALSE */
    terminate = 0;

    /* Initialize the storage tank inventory to the CAPACITY */
    inventory = CAPACITY;

    /* Initialize the pump amounts to 0 */
    for(count = 0; count < PUMPS; count++)
    {
        pump[count] = 0;
    }

    *pnumber = 0;

    /* Initialize the mutex lock and create the producer thread */
    if(pthread_mutex_init(&lock, NULL) !=0 )
    {
        printf("Error Initializing The Mutex Lock\n");
        *pnumber = -1;
    }
    else if(pthread_create(ptid, NULL, producer, NULL) != 0)
    {
        printf("Error Creating The Producer Thread\n");
        *pnumber = -1;
    }
}

void cleanup(pthread_t ptid)
{
    int checks = 0;
    int number;
    int active;

    do{
        /* Initialize the pump number and active flag */
        number = 0;
        active = 0;

        /* Look for pumps that are active */
        while(number < PUMPS && !active)
        {
            if(pthread_mutex_lock(&lock) != 0 )
                printf("Error Locking Mutex\n");
            
            if(pump[number] > 0)
                active = 1;
            else
                number++;
            
            if(pthread_mutex_unlock(&lock) != 0)
                printf("Error Unlocking Mutex\n");
        }

        if(active)
        {
            /* Increment the checks counter */
            checks++;

            /* Display the active pumps message on the first check */
            if(checks == 1)
                printf("Wait For Active Pump(s) To Finish\n");
        
            /* Sleep for one second before checking again */
            sleep(1);
        }
    }while(active);

    /* Set the terminate flag to cancel the producer thread */
    if(pthread_mutex_lock(&lock) != 0)
        printf("Error Locking Mutex\n");
    
    terminate = 1;

    if(pthread_mutex_unlock(&lock) != 0)
        printf("Error Unlocking Mutex\n");
    
    /* Wait for the producer thread to complete */
    if(pthread_join(ptid, NULL) != 0)
        printf("Error Joining The Producer Thread\n");
}

int get_number()
{
    int number;

    do{
        /* Get the pump number */
        printf("Enter A Pump Number From 1 To %d or -1 To Quit\n", PUMPS);
        scanf("%d", &number);
        /* Skip processing if the pump number is -1 */
        if(number != -1)
        {
            if(number < 1 || number > PUMPS)
            {
                printf("The Pump Number Must Be From 1 To %d\n", PUMPS);
                number = 0;
            }
            else
            {
                /* Check to see if the pump is available */
                if(pthread_mutex_lock(&lock) != 0)
                    printf("Error Locking Mutex\n");
                
                if(pump[number -1 ] > 0)
                {
                    printf("Pump Number %d Is Already In Use\n", number);
                    number = 0;
                }
                if(pthread_mutex_unlock(&lock) != 0)
                    printf("Error Unlocking Mutex\n");
            }
        }
    }while(0 == number);

    return number;
}

int get_amount()
{
    int amount;

    do{
        printf("Enter The Amount of Gasoline To Pump\n");
        scanf(" %d", &amount);

        /* Validate the amount of gasoline */
        if(amount <= 0)
        {
            printf("The Amount of Gasoline Must Be Greater Than 0\n");
            amount = 0;
        }
    }while(amount == 0);

    return amount;
}

void *producer(void *argument)
{
    int cancel; /* Cancel deliveries */
    int number; /* Pump number count */
    int remain; /* Pump remain count */

    /* Loop until the terminate flag is set to TRUE */
    do{
        if(pthread_mutex_lock(&lock) != 0)
            printf("Error Locking Mutex\n");
        /* Refill storage tank if inventory falls below QUANTITY */
        if(inventory < QUANTITY)
        {
            printf("Taking Pumps Off Line\n");

            /* Consumer threads are blocked when mutex is locked */
            for(number = 1; number <= PUMPS; number++)
            {
                if(pump[number - 1] > 0)
                    printf("Pump Number %d Off Line\n", number);
            }
            printf("Storage Tank Refill Started Inventory %d\n", inventory);

            /* Refill storage tank at FILL_RATE gallons per second */
            while(inventory < CAPACITY)
            {
                if(inventory + FILL_RATE <= CAPACITY)
                    inventory += FILL_RATE;
                else
                    inventory = CAPACITY;
                if(VERBOSE)
                    printf("Storage Tank Inventory %d\n", inventory);
                sleep(1);
            }

            printf("Storage Tank Refill Finished Inventory %d\n", inventory);
            printf("Putting Pump Back On Line\n");
            /* Unlock consumer threads when mutex is unlocked */
            for (number = 1; number <= PUMPS; number++)
            {
                remain = pump[number - 1];
                if(remain > 0)
                    printf("Pump Number %d On Line %d Remain\n", number, remain);
            }
        }
        /* Assign the terminate flag to the local cancel flag
         * used in the while condition outside the mutex lock
         */
        cancel = terminate;
        if(pthread_mutex_unlock(&lock) != 0)
            printf("Error Unlocking Mutex\n");
        
        /* Sleep for one second before checking again */
        sleep(1);
    }while(!cancel);

    printf("Storage Tank Deliveries Canceled\n");

    return NULL;
}

void *consumer(void *argument)
{
    int number;
    int output;
    int amount;

    /* case argument as an int * and assign the contents to number */
    number = *(int *)argument;
    output = 0;
    printf("Pump Number %d Started\n", number);
    do{
        if(pthread_mutex_lock(&lock) != 0)
            printf("Error Locking Mutex\n");
        
        /* Do not dispense more gasoline than requested */
        if(pump[number - 1] < FLOW_RATE)
            amount = pump[number - 1];
        else
            amount = FLOW_RATE;
        
        /* Donot dispense more gasoline than available */
        if(amount > inventory)
            amount = inventory;
        
        /* Redeuce the storage tank inventory and
         * pump amount by the gallons per second amount
         */
        inventory -= amount;
        pump[number - 1] -= amount;

        /* Increment the output by the amount */
        output += amount;

        /* Store the remaining pump amount in the local variable
         * amount for user in the while condition after the mutex
         * has ben unlocked
         */
        amount = pump[number - 1];
        if(VERBOSE)
            printf("Pump Number %d Output %d\n", number ,output);
        if(pthread_mutex_unlock(&lock) != 0)
            printf("Error Unlocking Mutex\n");
        
        sleep(1);
    }while(amount > 0);
    printf("Pump Number %d Finished Output %d\n", number, output);

    return NULL;
}
