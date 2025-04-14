#include "../includes/philo.h"

int Usage()
{

    return (ft_putstr_fd2(
        RED BOLD "\nError : Invalid arguments\n\n" RESET YELLOW "Usage : " RESET GREEN "./philo "
                 "<number_of_philosophers> <time_to_die> "
                 "<time_to_eat> <time_to_sleep> " RESET CYAN "[number_of_times_each_philosopher_must_eat]\n\n"));
}

void foo()
{
    system ("leaks -q philo");
}

int main(int ac, char **av)
{
    atexit (foo);
   
    (void) av;
    if (ac != 5 && ac != 6)
        return (Usage());
   init_philosophers(ac, av);

    return (0);
}
