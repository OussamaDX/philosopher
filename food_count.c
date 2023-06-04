/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   food_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 00:21:34 by ooussaad          #+#    #+#             */
/*   Updated: 2023/06/04 02:15:28 by ooussaad         ###   ########.fr       */
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
		if (data->philospher[j].food_num >= data->num_of_eat)
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
	data->max_food = (j == data->philo_num);
	pthread_mutex_unlock(&data->max_eat);
}
