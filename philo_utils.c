/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 23:16:30 by ooussaad          #+#    #+#             */
/*   Updated: 2023/06/04 02:26:32 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	timeoftheday(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(long time)
{
	long	start;

	start = timeoftheday();
	while (timeoftheday() - start < time)
		usleep(30);
}

void	message_phillo(char *msg, t_elm *philo)
{
	long	time;
	int		max;

	time = timeoftheday() - philo->data->start;
	pthread_mutex_lock(&philo->data->msgs);
	pthread_mutex_lock(&philo->data->max_eat);
	max = philo->data->max_food;
	pthread_mutex_unlock(&philo->data->max_eat);
	pthread_mutex_lock(&philo->data->dop);
	if (!max && !philo->data->breaking)
		printf(" %ld %s %s \n", time, philo->philo_position_str, msg);
	pthread_mutex_unlock(&philo->data->dop);
	pthread_mutex_unlock(&philo->data->msgs);
}
