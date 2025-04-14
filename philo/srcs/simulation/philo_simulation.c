#include "../../includes/philo.h"

static int  modular_arithmetic(int x, int m)
{
    return (x % m);
}

void    *routine(void *philo_arg)
{
    t_philo *philo;
    int     left_fork;
    int     right_fork;
    int     num_philos;

    philo = (t_philo *)philo_arg;
    num_philos = philo->info_table->num_philosophers;
    while (!philo->is_die && !philo->info_table->finish)
    {
        right_fork = philo->philo_id;
        left_fork =  modular_arithmetic(philo->philo_id + 1, num_philos);
        pick_up_fork(philo, right_fork);
        if (num_philos == 1)
        {
            printf ("edge case");
            break;
        }
        pick_up_fork(philo, left_fork);
        eating(philo);
        put_down_fork(philo, right_fork, left_fork);
        sleep_and_think(philo);
    }
    return (NULL);
}
