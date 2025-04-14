#include "../../includes/philo.h"

void display_status(t_philo *philo, char *content, t_status status)
{
    const char *color;

    if (status == dead)
        color = RED;
    else
        color = GREEN;

    pthread_mutex_lock(&philo->info_table->print_mutex);
    if (!philo->info_table->finish)
    {
        printf(CYAN BOLD "\n%lld" RESET "\t" 
               YELLOW BOLD "%i" RESET "\t" 
               "%s" BOLD "%s" RESET "\n\n",
               current_time(philo),
               philo->philo_id + 1,
               color,
               content);
    }
    pthread_mutex_unlock(&philo->info_table->print_mutex);
}
