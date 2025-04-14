#include "../../includes/philo.h"


static void *verify_is_dead(void    *info)
{
    t_philo *philo;
    long long	allowed_time;

    philo = (t_philo *)info;
    allowed_time  = philo->last_meal + philo->info_table->time_to_die;
    while (!philo->info_table->finish)
    {
        if (allowed_time < start_time())
        {
            display_status(philo, "died", dead);
            philo->info_table->finish = true;
            philo->is_die = true;
        }
        usleep(10); // subject 
    }
    return (NULL);
}

static void *verify_all_eaten(void  *info)
{
    t_table *table;

    table = (t_table *)info;
    while (!table->finish)
        if (table->all_ate_enough == table->num_philosophers)
            table->finish = true;
    return (NULL);
}

void    dining_philos_problem(t_table *table)
{
    pthread_t	monitor;
	int			i;

	i = 0;
    table->start_time = start_time();
    while (i++ < table->num_philosophers)
    {
        table->philos[i].philo_id = i;
        table->philos[i].info_table = table;
        table->philos[i].meals_eaten = 0;
        table->philos[i].is_die = false;
        table->philos[i].last_meal = table->start_time;
        pthread_create(&table->philos[i].th, NULL, routine , &table->philos[i]);
        pthread_create(&monitor, NULL, verify_is_dead, &table->philos[i]);
        pthread_detach(monitor); // deatch tell join not wait this 
        pthread_detach(monitor);
        usleep(10);
    }
    if (table->times_each_philosopher_must_eat >= 0)
    {
        pthread_create(&monitor, NULL, verify_all_eaten, table);
        pthread_detach(monitor);
    }
}
