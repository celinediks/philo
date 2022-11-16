/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:32:35 by cdiks             #+#    #+#             */
/*   Updated: 2022/11/16 14:22:25 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <math.h>
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
	pthread_mutex_t			eating;
	pthread_mutex_t			writing;
	pthread_mutex_t			state;
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
int		ft_atoi(const char *str);
void	print_action(t_data *data, t_philosopher *philo, char *text);
long	get_time(void);
bool	start_action(long time, t_philosopher *philo);
void	end_process(t_data *data);
int		check_digit(char **argv);
int		ft_isdigit(int arg);

// Actions
bool	action_eating(t_philosopher *philosopher);
bool	action_sleeping(t_philosopher *philosopher);
bool	action_thinking(t_philosopher *philosopher);
void	pick_up_forks(t_philosopher *philo);

// Sim checking
void	check_if_dead(t_data *data);
bool	check_if_ate(t_data *data);
bool	double_eat_check(t_data *data);
bool	stop_sim(t_philosopher *philo);
void	set_stop_sim(t_data *data);

#endif
