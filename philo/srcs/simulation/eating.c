#include "../../includes/philo.h"

void    eating(t_philo *philo)
{
    display_status(philo, "is eating", alive);
    usleep(philo->info_table->time_to_eat * 1000);
    /*
        time_to_eat is given in milliseconds, but usleep() works in microseconds.

        So we multiply by 1000 to convert: 1 ms = 1000 µs.

    */
    philo->meals_eaten++;
    philo->last_meal = start_time();
    if (philo->meals_eaten == philo->info_table->times_each_philosopher_must_eat)
        philo->info_table->all_ate_enough++;
}
