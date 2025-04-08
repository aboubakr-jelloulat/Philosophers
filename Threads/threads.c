#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h> // For Threads

// void *routine()
// {
//     printf("Test from threads\n");
//     sleep(3);
//     printf ("Ending Thread\n");
//     return NULL;
// }

// int main(int ac, char **av)
// {
//     pthread_t   t1, t2;
//     pthread_create(&t1, NULL, &routine, NULL);
//     pthread_create(&t2, NULL, &routine, NULL);

//     pthread_join(t1, NULL);

//     pthread_join(t2, NULL);

//     return 0;
// }

// int x = 0;

// void *routine2()
// {

//     sleep(2);
//     printf ("Value of x routine 2 : %d\n", x);
//     //printf ("Hello from Threads : process id : %d\n", getpid());

//     return NULL;
// }

// void *routine()
// {
//     x = 42; // 🟢 Objective: Show that threads share memory, so a change in one affects the other.
//     sleep(2);
//     printf ("Value of x routine 1 : %d\n", x);
//     //printf ("Hello from Threads : process id : %d\n", getpid());

//     return NULL;
// }

// int main(int ac, char **av)
// {
//    pthread_t   t1, t2;
//     pthread_create(&t1, NULL, &routine, NULL);
//     pthread_create(&t2, NULL, &routine2, NULL);

//     pthread_join(t1, NULL);

//     pthread_join(t2, NULL);

//     return 0;
// }

/* ************* A Practical Example of Threads ***************** */

// #define NC "\e[0m"
// #define YELLOW "\e[1;33m"

// void *thread_routine(void *data)
// {
//     pthread_t tid;

//     tid = pthread_self();

//     printf("%sThread [%ld]: The heaviest burden is to exist without living.%s\n", YELLOW, tid, NC);
//     return (NULL);
// }

// int main(void)
// {

//     pthread_t tid1;
//     pthread_t tid2;

//     pthread_create(&tid1, NULL, thread_routine, NULL);
//     printf("Main: Created first thread (Main thread) [%ld]\n", tid1);

//     pthread_create(&tid2, NULL, thread_routine, NULL);
//     printf("Main: Created second thread [%ld]\n", tid2);

//     // The main thread waits for the new threads to end
//     // with pthread_join.
//     pthread_join(tid1, NULL);
//     printf("Main: Joining first thread [%ld]\n", tid1);
//     pthread_join(tid2, NULL);
//     printf("Main: Joining second thread [%ld]\n", tid2);

//     return 0;
// }

/*      **************  Synchronization Errors  ****************** */

#define TIMES_TO_COUNT 21000

#define NC "\e[0m"
#define YELLOW "\e[33m"
#define BYELLOW "\e[1;33m"
#define RED "\e[31m"
#define GREEN "\e[32m"

void *thread_routine(void *data)
{
    // Each thread starts here
    pthread_t tid;
    unsigned int *count; // pointer to the variable created in main
    unsigned int i;

    tid = pthread_self();
    count = (unsigned int *)data;
    // Print the count before this thread starts iterating:
    printf("%sThread [%ld]: Count at thread start = %u.%s\n", YELLOW, tid, *count, NC);

    i = 0;
    while (i < TIMES_TO_COUNT)
    {
        // Iterate TIMES_TO_COUNT times && Increment the counter at each iteration
        (*count)++;
        i++;
    }
    // Print the final count when this thread

    printf("%sThread [%ld]: Final count = %u.%s\n", BYELLOW, tid, *count, NC);

    return (NULL);
}

int main(void)
{
    pthread_t tid1;
    pthread_t tid2;
    // Variable to keep track of the threads' counts:
    unsigned int count;

    count = 0;
    // Since each thread counts TIMES_TO_COUNT times and that
    // we have 2 threads, we expect the final count to be
    // 2 * TIMES_TO_COUNT:
    printf("Main: Expected count is %s%u%s\n", GREEN, 2 * TIMES_TO_COUNT, NC);

    pthread_create(&tid1, NULL, thread_routine, &count);
    printf("Main: Created first thread [%ld]\n", tid1);

    pthread_create(&tid2, NULL, thread_routine, &count);
    printf("Main: Created second thread [%ld]\n", tid2);
   
    pthread_join(tid1, NULL);
    printf("Main: Joined first thread [%ld]\n", tid1);
    sleep(2);
    pthread_join(tid2, NULL);
    printf("Main: Joined second thread [%ld]\n", tid2);
    
    
    if (count != (2 * TIMES_TO_COUNT))
        printf("%sMain: ERROR ! Total count is %u%s\n", RED, count, NC);
    else
        printf("%sMain: OK. Total count is %u%s\n", GREEN, count, NC);
    return (0);
}
/*
    The failure occurs because multiple threads are concurrently modifying the count variable,
    but without synchronization. This means both threads are reading and writing to the same count variable at the same time,
    which leads to race conditions.

*/