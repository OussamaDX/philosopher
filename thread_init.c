/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:33:57 by ooussaad          #+#    #+#             */
/*   Updated: 2023/05/26 21:08:22 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char *ft_itoa(int num) {
    int n = num;
    int len = 0;
    int sign = 0;
    
    if (n == 0) {
        char *str = (char *)malloc(2 * sizeof(char));
        str[0] = '0';
        str[1] = '\0';
        return str;
    }

    if (n < 0) {
        sign = 1;
        n = -n;
    }

    int temp = n;
    while (temp != 0) {
        len++;
        temp /= 10;
    }

    if (sign == 1) {
        len++;
    }

    char *str = (char *)malloc((len + 1) * sizeof(char));

    int i = 0;
    while (n != 0) {
        str[i] = n % 10 + '0';
        n /= 10;
        i++;
    }

    if (sign == 1) {
        str[i] = '-';
        i++;
    }

    str[i] = '\0';

    // Reverse the string
    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }

    return str;
}

long	timeoftheday(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	message_phillo(char *msg, t_elm *philo)
{
    philo = NULL;
    printf("%ld",timeoftheday());
    //char *timeprint;
    //int n = timeoftheday() - philo->data->start;
	//timeprint = ft_itoa(n);
    printf("%s\n",msg);
}

void eating(t_elm *philo)
{
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
    int i = 0;
    data->start = timeoftheday();
    while (i < data->philo_num)
    {
        if (pthread_create(&(data->philospher[i].philo_id), NULL, routine,
			    &data->philospher[i]))
            return (1);
		usleep(1000);
    }
    return 1;
}