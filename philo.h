/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:45:00 by ooussaad          #+#    #+#             */
/*   Updated: 2023/05/28 15:53:06 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
#include <stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include <string.h>
# include <sys/time.h>
#include <limits.h>

typedef struct s_data t_root;

typedef struct s_elm
{
	int			eat_num;
	int			philo_position;
	char		*philo_position_str;
	int			front_fork;
	int			side_fork;
	pthread_t	philo_id;
	int			last_ate;
	t_root		*data;
}t_elm;

typedef struct s_data
{
	int					philo_num;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
    int					num_of_eat;
	t_elm				*philospher;
	pthread_mutex_t		*forks;
	unsigned long		start;
}	t_root;

long long	ft_atoi(char *str);
int         check_numbers(char **argv);
int			ft_init(t_root *data, char **argv, int argc);
int			init_args(t_root *data, char **argv, int argc);
int			ft_create_thread(t_root *data);
char		*ft_itoa(int n);
long		timeoftheday(void);


#endif