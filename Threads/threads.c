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

int x = 0;

void *routine2()
{
    
    sleep(2);
    printf ("Value of x routine 2 : %d\n", x);
    //printf ("Hello from Threads : process id : %d\n", getpid());

    return NULL;
}

void *routine()
{
    x = 42; // 🟢 Objective: Show that threads share memory, so a change in one affects the other.
    sleep(2);
    printf ("Value of x routine 1 : %d\n", x);
    //printf ("Hello from Threads : process id : %d\n", getpid());

    return NULL;
}

int main(int ac, char **av)
{
   pthread_t   t1, t2;
    pthread_create(&t1, NULL, &routine, NULL);
    pthread_create(&t2, NULL, &routine2, NULL);

    pthread_join(t1, NULL);

    pthread_join(t2, NULL);

    return 0;
}