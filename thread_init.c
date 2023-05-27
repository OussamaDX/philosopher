/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:33:57 by ooussaad          #+#    #+#             */
/*   Updated: 2023/05/27 02:49:45 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	timeoftheday(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	message_phillo(char *msg, t_elm *philo)
{
    philo = NULL;
    printf("%s\n",msg);
}

void eating(t_elm *philo)
{
    if (philo == NULL)
        return ;
	pthread_mutex_lock(&philo->data->forks[philo->front_fork]);
    message_phillo("has taken a fork", philo);
    pthread_mutex_lock(&philo->data->forks[philo->side_fork]);
    message_phillo("has taken a fork", philo);
	message_phillo("is eating", philo);
}

void	*routine(void *param)
{
	t_elm	*philo;

	philo = (t_elm *)param;
    while (1)
	{
        eating(philo);
    }
}

int	ft_create_thread(t_root *data)
{
    int i = -1;
    data->start = timeoftheday();
    while (++i < data->philo_num)
    {
        if (pthread_create(&(data->philospher[i].philo_id), NULL, &routine, &data->philospher[i]))
            return (1);
		usleep(100);
    }
    return 1;
}