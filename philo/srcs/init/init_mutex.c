#include "../../includes/philo.h"

void    init_mutex_for_each_fork(t_table *table)
{
    int u;

    u = 0;
    pthread_mutex_init(&table->print_mutex, NULL);
    while (u < table->num_philosophers)
        pthread_mutex_init(&table->forks[u++] , NULL);

}
