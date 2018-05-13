#include "exercise.h"

int main()
{
    puts("Exercise begin!");

    if(FALSE == multi_thread_change_var())
    {
        puts("Test case failed.");
    }
    
    puts("Exercise end!");
    return 0;
}
