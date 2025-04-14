#include "../../includes/philo.h"


static void join_threads_and_cleanup(t_table *table)
{
    int u;

    u = 0;
    while (u++ < table->num_philosophers)
        pthread_join(table->philos[u].th, NULL);
    
    free(table->philos);
    u = 0;
    while (u++ < table->num_philosophers)
        pthread_mutex_destroy(&table->forks[u]);
    pthread_mutex_destroy(&table->print_mutex);
    free(table->forks);
    free(table);
}

void init_philosophers(int ac, char *av[])
{
    t_table *table;

    table = (t_table *) malloc(sizeof(t_table));
    if (!table)
        return ;
    if (!parse_arguments_and_check(ac, av, table))
        return (free(table)); // free
    table->philos = malloc(table->num_philosophers * sizeof(t_philo));
    if (!table->philos)
        return (free(table));
    table->forks  = malloc(table->num_philosophers * sizeof(pthread_mutex_t));
    if (!table->forks)
        return (free(table->philos), free(table)); 
    table->all_ate_enough = 0;
    table->finish = 0;
    init_mutex_for_each_fork(table);
    dining_philos_problem(table);
    join_threads_and_cleanup(table);
    
}
