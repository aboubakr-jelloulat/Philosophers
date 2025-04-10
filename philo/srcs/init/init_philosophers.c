#include "../../includes/philo.h"

int init_philosophers(int ac, char *av[], t_table *table)
{
    if (!table)
        return (0);
    if (parse_arguments_and_check(ac, av, table))
        return (0);
    table->philos = malloc(table->num_philosophers * sizeof(t_philo));
    table->forks  = malloc(table->num_philosophers * sizeof(pthread_mutex_t));
    if (!table->philos || !table->forks)
        return (0);
    table->all_ate_enough = 0;
    table->finish = 0;
    init_mutex_for_each_fork(table);
    


    return 1;
}
