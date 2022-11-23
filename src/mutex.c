/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:48:08 by cdiks             #+#    #+#             */
/*   Updated: 2022/11/23 12:34:58 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	read_amount_eaten(t_philosopher *philo)
{
	int	amount;

	pthread_mutex_lock(&philo->data->eating);
	amount = philo->amount_eaten;
	pthread_mutex_unlock(&philo->data->eating);
	return (amount);
}

long	read_meal_time(t_philosopher *philo)
{
	long	mealtime;

	pthread_mutex_lock(&philo->data->meal_time);
	mealtime = philo->last_meal;
	pthread_mutex_unlock(&philo->data->meal_time);
	return (mealtime);
}

void	set_amount_eaten(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->data->eating);
	philo->amount_eaten++;
	pthread_mutex_unlock(&philo->data->eating);
}

void	set_meal_time(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->data->meal_time);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->data->meal_time);
}

void	set_stop_sim(t_data *data)
{
	pthread_mutex_lock(&data->state);
	data->sim_running = false;
	pthread_mutex_unlock(&data->state);
}
