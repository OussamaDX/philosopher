/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:51:58 by ooussaad          #+#    #+#             */
/*   Updated: 2023/06/04 02:25:22 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_die(t_root *data)
{
	int	i;

	while (!data->max_food)
	{
		i = -1;
		while (++i < data->philo_num && !data->breaking)
		{
			pthread_mutex_lock(&data->meal);
			if ((int)(timeoftheday()
				- data->philospher[i].last_eat) >= data->time_to_die)
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
