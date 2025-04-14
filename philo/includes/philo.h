/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:04:53 by ajelloul          #+#    #+#             */
/*   Updated: 2025/04/14 11:33:20 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>


# define RED     "\033[0;31m"
# define GREEN   "\033[0;32m"
# define YELLOW  "\033[0;33m"
# define BLUE    "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN    "\033[0;36m"
# define RESET   "\033[0m"

# define BOLD    "\033[1m"

typedef struct  s_philo t_philo;

typedef enum e_status
{
    alive,
    dead
}   t_status;

typedef struct t_table
{
    int             time_to_die;         // Max time without eating
    int             time_to_eat;         // Time for eating
    int             time_to_sleep;       // Time for sleeping
    int             num_philosophers;    // Number of philosophers
    int             times_each_philosopher_must_eat;  //  number_of_times_each_philosopher_must_eat;    // Meals needed to finish
    bool             finish;
    int             all_ate_enough;
    long long       start_time; // creation_time; // When simulation started
    t_philo         *philos;
    pthread_mutex_t *forks;
    pthread_mutex_t print_mutex; // finish_lock
}   t_table;

typedef struct s_philo
{
    int          philo_id;
    bool         is_die; // should die
    int         meals_eaten;// ate   // how many times philosopher has eaten
    long long   last_meal;  //  When philosopher last ate
    t_table     *info_table; // info
    pthread_t   th; // threadddd
}   t_philo;
 // left and right fork 



int ft_putstr_fd2(char *str_err);
int ft_strlen(const char *s);
int ft_atoi(const char *str);


void init_philosophers(int ac, char *av[]);
int   parse_arguments_and_check(int ac, char **av, t_table *table);
void    init_mutex_for_each_fork(t_table *table);
void    dining_philos_problem(t_table *table);
long long   current_time(t_philo *philo);
long long   start_time(void);

void    display_status(t_philo *philo, char *content, t_status status);
void    *routine(void *philo_arg);
void    pick_up_fork(t_philo *philo, int pos);
void    eating(t_philo *philo);
void    put_down_fork(t_philo *philo, int right, int left);
void    sleep_and_think(t_philo *philo);


#endif