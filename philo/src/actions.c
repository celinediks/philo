/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:40:22 by cdiks             #+#    #+#             */
/*   Updated: 2022/11/16 14:42:14 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	action_eating(t_philosopher *philo)
{
	pick_up_forks(philo);
	pthread_mutex_lock(&(philo->data->eating));
	philo->last_meal = get_time();
	print_action(philo->data, philo, GREEN"is eating"NC);
	philo->amount_eaten++;
	pthread_mutex_unlock(&(philo->data->eating));
	if (start_action(philo->data->eat_time, philo) == false)
	{
		pthread_mutex_unlock(&philo->data->fork[philo->right_fork]);
		pthread_mutex_unlock(&philo->data->fork[philo->left_fork]);
		return (false);
	}
	pthread_mutex_unlock(&philo->data->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->fork[philo->right_fork]);
	return (true);
}

bool	action_sleeping(t_philosopher *philo)
{
	print_action(philo->data, philo, BLUE"is sleeping"NC);
	return (start_action(philo->data->sleep_time, philo));

}

bool	action_thinking(t_philosopher *philo)
{
	print_action(philo->data, philo, BLUE"is thinking"NC);
	return (start_action(0, philo));
}

void	pick_up_forks(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->data->fork[philo->left_fork]);
		print_action(philo->data, philo, YELLOW"has taken a fork"NC);
		pthread_mutex_lock(&philo->data->fork[philo->right_fork]);
		print_action(philo->data, philo, YELLOW"has taken a fork"NC);
	}
	else
	{
		pthread_mutex_lock(&philo->data->fork[philo->right_fork]);
		print_action(philo->data, philo, YELLOW"has taken a fork"NC);
		pthread_mutex_lock(&philo->data->fork[philo->left_fork]);
		print_action(philo->data, philo, YELLOW"has taken a fork"NC);
	}
}
