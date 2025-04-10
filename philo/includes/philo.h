/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:04:53 by ajelloul          #+#    #+#             */
/*   Updated: 2025/04/10 17:45:28 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>



# define RED     "\033[0;31m"
# define GREEN   "\033[0;32m"
# define YELLOW  "\033[0;33m"
# define BLUE    "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN    "\033[0;36m"
# define RESET   "\033[0m"

# define BOLD    "\033[1m"

typedef struct  s_philo t_philo;

typedef struct s_table
{
    int             time_to_die;         // Max time without eating
    int             time_to_eat;         // Time for eating
    int             time_to_sleep;       // Time for sleeping
    int             num_philosophers;    // Number of philosophers
    int             times_each_philosopher_must_eat;  //  number_of_times_each_philosopher_must_eat;    // Meals needed to finish
    int             finish;
    int             all_ate_enough;
    long long       start_time; // creation_time; // When simulation started
    t_philo         *philos;
    pthread_mutex_t *forks;
    pthread_mutex_t unlock; // finish_lock
}   t_table;

typedef struct s_philo
{
    int         philo_id;
    int         is_die; // should die
    int         meals_eaten;// ate   // how many times philosopher has eaten
    long long   last_meal;  //  When philosopher last ate
    t_table     *table; // info
    pthread_t   th; // threadddd
}   t_philo;




int ft_putstr_fd2(char *str_err);
int ft_strlen(const char *s);
int ft_atoi(const char *str);


int init_philosophers(int ac, char *av[], t_table *table);
int   parse_arguments_and_check(int ac, char **av, t_table *table);
void    init_mutex_for_each_fork(t_table *table);


#endif