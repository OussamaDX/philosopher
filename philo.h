/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:45:00 by ooussaad          #+#    #+#             */
/*   Updated: 2023/05/25 16:16:17 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
#include <stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include <limits.h>

	// int					ate_times;
	// int					pos;
	// char				*pos_str;
	// int					ffork;
	// int					sfork;
typedef struct s_elm
{
	int			eat_num;
	int			philo_position;
	char		*philo_position_str;
	int			front_fork;
	int			side_front;
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

}	t_root;

long long	ft_atoi(char *str);
int         check_numbers(char **argv);
int			ft_init(t_root *data, char **argv, int argc);
int			init_args(t_root *data, char **argv, int argc);

#endif