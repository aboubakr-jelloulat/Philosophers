#include "../../includes/philo.h"


void    dining_philos_problem(t_table *table)
{
    pthread_t	monitor;
	int			i;

	i = 0;
    table->start_time = start_time();
    while (i < table->num_philosophers)
    {
        table->philos[i]->philo_id = i;
        table->philos[i].info_table = table;
        table->philos[i].last_meal = table->start_time;
        table->philos[i].is_die = 0;
        table->philos[i].meals_eaten = 0;

    }

}