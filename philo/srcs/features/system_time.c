#include "../../includes/philo.h"

long long   start_time(void)
{
    long long   sec_to_mill;
    long long   micro_within_to_mill;

    struct timeval cur_time;
    gettimeofday(&cur_time, NULL);
    
    sec_to_mill = cur_time.tv_sec * 1000;
    micro_within_to_mill = cur_time.tv_usec / 1000;
    return (sec_to_mill + micro_within_to_mill);
}

long long   current_time(t_philo *philo)
{
    return (start_time() - philo->info_table->start_time);
}
