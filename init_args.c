/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:17:39 by ooussaad          #+#    #+#             */
/*   Updated: 2023/06/02 19:09:50 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void creat_meutix(t_root *data)
{
	int i = 0;
	while (i < data->philo_num)
	{
		data->philospher[i].ate_times = 0;
		data->philospher[i].front_fork = i;
		data->philospher[i].side_fork = (i + 1) % data->philo_num;
		data->philospher[i].philo_position = i + 1;
		data->philospher[i].philo_position_str = ft_itoa(i + 1);
		i++;
	}
}

int meutix_initialize(t_root *data)
{
	int i;

	i = 0;
	while(i < data->philo_num)
	{
		if(pthread_mutex_init(&data->forks[i++],NULL))
			return(1);
	}
	creat_meutix(data);
	return (1);
}

int	fill_elm(t_root *data)
{
	data->philospher = malloc(sizeof(t_elm) * data->philo_num);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	if (data->forks == NULL)
		return (0);
	meutix_initialize(data);
	return (1);
}

int	init_args(t_root *data, char **argv, int argc)
{
	data->philo_num = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_of_eat = ft_atoi(argv[5]);
	fill_elm(data);
	return (1);
}