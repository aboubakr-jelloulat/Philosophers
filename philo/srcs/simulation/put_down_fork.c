#include "../../includes/philo.h"

void    put_down_fork(t_philo *philo, int right, int left)
{
	pthread_mutex_unlock(&philo->info_table->forks[right]);
	pthread_mutex_unlock(&philo->info_table->forks[left]);
}
