/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:32:32 by cdiks             #+#    #+#             */
/*   Updated: 2022/11/23 12:34:04 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	start_action(long time, t_philosopher *philo)
{
	long	i;

	i = get_time();
	while (get_time() - i < time)
	{
		if (!stop_sim(philo))
			return (false);
		usleep(SLEEP_TIME);
	}
	return (true);
}

void	end_process(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->amount_philo)
	{
		pthread_join(data->philosopher[i].thread_id, NULL);
		i++;
	}
	free(data->philosopher);
	free(data->fork);
}

void	*routine(void *philosopher)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philosopher;
	if (philo->data->amount_philo == 1)
		return (one_philo_case(philo));
	if (!philo->id % 2)
		start_action(10, philo);
	while (stop_sim(philo))
	{
		if (!action_eating(philo))
			return (NULL);
		if (!action_sleeping(philo))
			return (NULL);
		if (!action_thinking(philo))
			return (NULL);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if ((argc != 5 && argc != 6) || (check_digit(argv)))
	{
		write(STDERR, "invalid input\n", 15);
		return (1);
	}
	if (init_all(&data, argv))
		return (1);
	return (0);
}
