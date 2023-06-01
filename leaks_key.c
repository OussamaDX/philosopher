/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:32:40 by ooussaad          #+#    #+#             */
/*   Updated: 2023/06/01 18:17:07 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_philo(t_root *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_destroy(&data->forks[i++]);
	}
	pthread_mutex_destroy(&data->meal);
	pthread_mutex_destroy(&data->msgs);
	pthread_mutex_destroy(&data->dop);
	pthread_mutex_destroy(&data->max_eat);
	pthread_mutex_destroy(&data->eat_time_m);
	i = -1;
	while (++i < data->philo_num)
		free(data->philospher[i].philo_position_str);
	free(data->philospher);
	free(data->forks);
}
