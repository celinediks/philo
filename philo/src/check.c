/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:15:13 by cdiks             #+#    #+#             */
/*   Updated: 2022/11/16 14:37:11 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	check_if_dead(t_data *data)
{
	int	i;

	i = 0;
	while (stop_sim(&data->philosopher[0]))
	{
		if (data->times_to_eat && (double_eat_check(data)))
			return ;
		while (i < data->amount_philo)
		{
			if (get_time() - data->philosopher[i].last_meal > data->die_time)
			{
				pthread_mutex_lock(&data->writing);
				printf(RED"%ld %i died\n"NC,
					(get_time() - data->start_time), data->philosopher[i].id);
				pthread_mutex_unlock(&data->writing);
				set_stop_sim(data);
				return ;
			}
			i++;
		}
		usleep(DEATH_TIME);
		i = 0;
	}
	return ;
}

void	set_stop_sim(t_data *data)
{
	pthread_mutex_lock(&data->state);
	data->sim_running = false;
	pthread_mutex_unlock(&data->state);
}

bool	stop_sim(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->data->state);
	if (philo->data->sim_running == false)
	{
		pthread_mutex_unlock(&philo->data->state);
		return (false);
	}
	pthread_mutex_unlock(&philo->data->state);
	return (true);
}

bool	double_eat_check(t_data *data)
{
	if (check_if_ate(data))
	{
		set_stop_sim(data);
		return (true);
	}
	return (false);
}

bool	check_if_ate(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->amount_philo)
	{
		if (data->philosopher[i].amount_eaten < data->times_to_eat)
			return (false);
		i++;
	}
	return (true);
}
