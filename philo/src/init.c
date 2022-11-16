/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:44:55 by cdiks             #+#    #+#             */
/*   Updated: 2022/11/16 11:16:13 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_all(t_data *data, char **argv)
{
	data->amount_philo = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	data->sim_running = true;
	data->start_time = get_time();
	if (argv[5])
		data->times_to_eat = ft_atoi(argv[5]);
	if (data->amount_philo < 1 || data->die_time <= 0 || data->eat_time <= 0
		|| data->sleep_time <= 0)
	{
		printf("wrong input\n");
		return (1);
	}
	if (init_mutex(data))
		return (1);
	if (init_philosophers(data))
		return (1);
	start_threads(data);
	return (0);
}

void	start_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->amount_philo)
	{
		data->philosopher[i].last_meal = get_time();
		pthread_create(&(data->philosopher[i].thread_id), NULL,
			routine, &data->philosopher[i]);
		i++;
	}
	check_if_dead(data);
	end_process(data);
}

int	init_philosophers(t_data *data)
{
	int	i;

	i = 0;
	data->philosopher = malloc(data->amount_philo * sizeof(t_philosopher));
	if (!data->philosopher)
		return (1);
	while (i < data->amount_philo)
	{
		data->philosopher[i].id = i + 1;
		data->philosopher[i].data = data;
		data->philosopher[i].amount_eaten = 0;
		data->philosopher[i].left_fork = i;
		data->philosopher[i].last_meal = get_time();
		data->philosopher[i].right_fork = i + 1;
		if (i == data->amount_philo - 1)
			data->philosopher[i].right_fork = 0;
		i++;
	}
	return (0);
}

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->amount_philo);
	if (!data->fork)
	{
		free(data->philosopher);
		return (1);
	}
	while (i < data->amount_philo)
	{
		if (pthread_mutex_init(&data->fork[i], NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&data->eating, NULL))
		return (1);
	if (pthread_mutex_init(&(data->writing), NULL))
		return (1);
	if (pthread_mutex_init(&(data->state), NULL))
		return (1);
	return (0);
}
