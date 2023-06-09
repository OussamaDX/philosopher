/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:45:00 by ooussaad          #+#    #+#             */
/*   Updated: 2023/06/04 02:27:58 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data	t_root;

typedef struct s_elm
{
	int					eat_num;
	int					food_num;
	int					philo_position;
	char				*philo_position_str;
	int					front_fork;
	int					side_fork;
	unsigned long		first_eat;
	pthread_t			philo_id;
	unsigned long		last_eat;
	t_root				*data;
}						t_elm;

typedef struct s_data
{
	int					breaking;
	int					max_food;
	int					philo_num;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_of_eat;
	t_elm				*philospher;
	pthread_mutex_t		*forks;
	pthread_mutex_t		meal;
	pthread_mutex_t		eat_time_m;
	pthread_mutex_t		max_eat;
	pthread_mutex_t		msgs;
	pthread_mutex_t		dop;
	unsigned long		start;
}						t_root;

long long				ft_atoi(char *str);
int						check_numbers(char **argv);
void					message_phillo(char *msg, t_elm *philo);
void					ft_usleep(long time);
long					timeoftheday(void);
int						ft_init(t_root *data, char **argv, int argc);
int						init_args(t_root *data, char **argv, int argc);
int						ft_create_thread(t_root *data);
char					*ft_itoa(int n);
long					timeoftheday(void);
void					count_food_max(t_root *data);
void					philo_die(t_root *data);
void					ft_free_philo(t_root *data);

#endif
