/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:33:57 by ooussaad          #+#    #+#             */
/*   Updated: 2023/05/27 21:54:02 by ooussaad         ###   ########.fr       */
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
    long time = timeoftheday() - philo->data->start;
	printf(" %ld %s %s\n", time, philo->philo_position_str, msg);
}

void eating(t_elm *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->front_fork]);
    message_phillo("has taken a ffork", philo);
    pthread_mutex_lock(&philo->data->forks[philo->side_fork]);
    message_phillo("has taken a sfork", philo);
	message_phillo("is eating", philo);
    ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->data->forks[philo->front_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->side_fork]);
}

void	*routine(void *param)
{
	t_elm	*philo;

	philo = (t_elm *)param;
    while (1)
	{
        eating(philo);
	    message_phillo("is sleeping", philo);
        ft_usleep(philo->data->time_to_sleep);
	    message_phillo("is thinking", philo);
    }
}

int	ft_create_thread(t_root *data)
{
    int i = -1;
    data->start = timeoftheday();
    while (++i < data->philo_num)
    {
		data->philospher[i].data = data;
        if (pthread_create(&(data->philospher[i].philo_id), NULL, &routine, &data->philospher[i]))
            return (1);
		usleep(50);
    }
    return 1;
}