/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:32:35 by cdiks             #+#    #+#             */
/*   Updated: 2022/11/23 14:37:40 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

# define NC "\x1B[0m"
# define BLUE "\033[0;34m"
# define RED "\x1B[31m"
# define YELLOW "\x1B[33m"
# define GREEN "\033[1m\033[32m"
# define MAG "\e[0;35m"

# define SLEEP_TIME 250
# define DEATH_TIME 250
# define STDERR		2

typedef struct s_philosopher
{
	int				id;
	int				amount_eaten;
	int				right_fork;
	int				left_fork;
	long			last_meal;
	pthread_t		thread_id;
	struct s_data	*data;
}					t_philosopher;

typedef struct s_data
{
	int						amount_philo;
	int						die_time;
	int						eat_time;
	int						sleep_time;
	int						times_to_eat;
	bool					sim_running;
	long					start_time;
	pthread_mutex_t			*fork;
	pthread_mutex_t			state;
	pthread_mutex_t			meal_time;
	pthread_mutex_t			eating;
	struct s_philosopher	*philosopher;
}					t_data;

// Setup
int		init_philosophers(t_data *data);
int		init_all(t_data *data, char **argv);
int		init_mutex(t_data *data);
void	threading(void);
void	*routine(void *philosopher);
void	start_threads(t_data *data);

// Utils
void	print_action(t_data *data, t_philosopher *philo, char *text);
int		ft_atoi(const char *str);
int		ft_isdigit(int arg);
bool	start_action(long time, t_philosopher *philo);
void	end_process(t_data *data);
int		check_digit(char **argv);

// Time 
long	time_diff(long start);
long	get_time(void);

// Mutex locks
void	set_meal_time(t_philosopher *philo);
long	read_meal_time(t_philosopher *philo);
void	set_amount_eaten(t_philosopher *philo);
int		read_amount_eaten(t_philosopher *philo);

// Actions
bool	action_eating(t_philosopher *philosopher);
bool	action_sleeping(t_philosopher *philosopher);
bool	action_thinking(t_philosopher *philosopher);
void	pick_up_forks(t_philosopher *philo);

// Sim checking
void	check_if_dead(t_data *data);
bool	check_if_ate(t_data *data);
bool	stop_sim(t_philosopher *philo);
void	set_stop_sim(t_data *data);
void	*one_philo_case(t_philosopher *philo);

#endif
