#include "../../includes/philo.h"

void    pick_up_fork(t_philo *philo, int pos)
{
    pthread_mutex_lock(&philo->info_table->forks[pos]);
    display_status(philo, "has taken a fork", alive);

}
