/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:59:18 by cdiks             #+#    #+#             */
/*   Updated: 2022/11/23 12:48:16 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
		if (i > 10 && sign == -1)
			return (0);
		if (i > 10)
			return (-1);
	}
	return (result * sign);
}

void	print_action(t_data *data, t_philosopher *philo, char *text)
{
	pthread_mutex_lock(&data->state);
	if (philo->data->sim_running == true)
	{
		printf("%li"NC, time_diff(data->start_time));
		printf(" %d "NC, philo->id);
		printf("%s\n", text);
	}
	pthread_mutex_unlock(&(data->state));
}

int	ft_isdigit(int arg)
{
	return ((arg >= '0') && (arg <= '9'));
}

void	*one_philo_case(t_philosopher *philo)
{
	print_action(philo->data, philo, YELLOW"has taken a fork"NC);
	set_stop_sim(philo->data);
	return (NULL);
}
