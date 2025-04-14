#include "../../includes/philo.h"

void    sleep_and_think(t_philo *philo)
{
    display_status(philo, "is sleeping", alive);
    usleep(philo->info_table->time_to_sleep * 1000);
    display_status(philo, "is thinking", alive);
}
