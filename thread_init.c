/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:33:57 by ooussaad          #+#    #+#             */
/*   Updated: 2023/06/04 02:27:10 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_elm *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->front_fork]);
	message_phillo("has taken a fork", philo);
	pthread_mutex_lock(&philo->data->forks[philo->side_fork]);
	message_phillo("has taken a fork", philo);
	message_phillo("is eating", philo);
	pthread_mutex_lock(&philo->data->meal);
	philo->last_eat = timeoftheday();
	pthread_mutex_unlock(&philo->data->meal);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_lock(&philo->data->eat_time_m);
	philo->food_num++;
	pthread_mutex_unlock(&philo->data->eat_time_m);
	pthread_mutex_unlock(&philo->data->forks[philo->front_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->side_fork]);
}

void	*routine(void *param)
{
	t_elm	*philo;
	int		max;
	int		stop;

	philo = (t_elm *)param;
	while (1)
	{
		pthread_mutex_lock(&philo->data->max_eat);
		max = philo->data->max_food;
		pthread_mutex_unlock(&philo->data->max_eat);
		pthread_mutex_lock(&philo->data->dop);
		stop = philo->data->breaking;
		pthread_mutex_unlock(&philo->data->dop);
		if (max || stop)
			break ;
		eating(philo);
		message_phillo("is sleeping", philo);
		ft_usleep(philo->data->time_to_sleep);
		message_phillo("is thinking", philo);
	}
	return (NULL);
}

int	ft_create_thread(t_root *data)
{
	int	i;

	i = -1;
	data->start = timeoftheday();
	while (++i < data->philo_num)
	{
		data->philospher[i].data = data;
		data->philospher[i].last_eat = timeoftheday();
		if (pthread_create(&(data->philospher[i].philo_id), NULL, &routine,
				&(data->philospher[i])) != 0)
			return (1);
		usleep(50);
	}
	philo_die(data);
	i = 0;
	if (data->philo_num == 1)
		pthread_detach(data->philospher[0].philo_id);
	else
	{
		while (i < data->philo_num)
			pthread_join(data->philospher[i++].philo_id, NULL);
	}
	ft_free_philo(data);
	return (1);
}
