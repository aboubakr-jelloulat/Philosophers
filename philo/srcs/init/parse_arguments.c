#include "../../includes/philo.h"



static int  is_valid_argument(int ac, t_table table)
{
    if (table.num_philosophers <= 0)
        return (ft_putstr_fd2("\nERROR: Invalid number of philosophers\n\n"));
    if (table.time_to_die < 0)
        return (ft_putstr_fd2("\nERROR: Invalid time to die value\n\n"));
    if (table.time_to_eat < 0)
        return (ft_putstr_fd2("\nERROR: Invalid time to eat value\n\n"));
    if (table.time_to_sleep < 0)
        return (ft_putstr_fd2("\nERROR: Invalid time to sleep value\n\n"));
    if (ac == 6 && table.times_each_philosopher_must_eat <= 0)
        return (ft_putstr_fd2("\nERROR: Invalid number of time  must eat value\n\n"));
    return (0);
}

int parse_arguments_and_check(int ac, char **av, t_table *table)
{
    table->num_philosophers = ft_atoi(av[1]);
    table->time_to_die = ft_atoi(av[2]);
    table->time_to_eat = ft_atoi(av[3]);
    table->time_to_sleep = ft_atoi(av[4]);
    if (ac == 6)
        table->times_each_philosopher_must_eat = ft_atoi(av[5]);
    else
        table->times_each_philosopher_must_eat = -42;
    return (is_valid_argument(ac, *table));
}
