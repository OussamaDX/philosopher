/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:51:58 by ooussaad          #+#    #+#             */
/*   Updated: 2023/06/01 16:14:40 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	count_food_max(t_root *data)
{
	int	j;

	j = 0;
	while (data->num_of_eat && j < data->philo_num)
	{
		pthread_mutex_lock(&data->eat_time_m);
		if (data->philospher[j].ate_times >= data->num_of_eat)
		{
			j++;
			pthread_mutex_unlock(&data->eat_time_m);
		}
		else
		{
			pthread_mutex_unlock(&data->eat_time_m);
			break ;
		}
	}
	pthread_mutex_lock(&data->max_eat);
	if (j == data->philo_num)
		data->max_food = j;
	pthread_mutex_unlock(&data->max_eat);
}

void	philo_die(t_root *data)
{
	int		i;

	while (!data->max_food)
	{
		i = -1;
		while (++i < data->philo_num && !data->breaking)
		{
			pthread_mutex_lock(&data->meal);
            if ((int)(timeoftheday() - data->philospher[i].last_eat) >= data->time_to_die)
            {
				message_phillo("is died", &data->philospher[i]);
				pthread_mutex_lock(&data->dop);
				data->breaking = 1;
				pthread_mutex_unlock(&data->dop);
			}
			pthread_mutex_unlock(&data->meal);
		}
		if (data->breaking)
			break ;
		count_food_max(data);
	}
}
