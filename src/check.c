/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:15:13 by cdiks             #+#    #+#             */
/*   Updated: 2022/11/23 14:07:17 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	check_if_dead(t_data *data)
{
	int		i;
	long	diff_meal;

	while (stop_sim(&data->philosopher[0]))
	{
		if (data->times_to_eat && (check_if_ate(data)))
			return ;
		while (i < data->amount_philo)
		{
			diff_meal = get_time() - read_meal_time(&data->philosopher[i]);
			if (diff_meal > data->die_time)
			{
				set_stop_sim(data);
				printf(RED"%ld %i died\n"NC,
					time_diff(data->start_time), data->philosopher[i].id);
				return ;
			}
			i++;
		}
		usleep(DEATH_TIME);
		i = 0;
	}
	return ;
}

int	check_digit(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

bool	check_if_ate(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->amount_philo)
	{
		if (read_amount_eaten(&data->philosopher[i]) < data->times_to_eat)
			return (false);
		i++;
	}
	set_stop_sim(data);
	return (true);
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
