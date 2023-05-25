/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:45:00 by ooussaad          #+#    #+#             */
/*   Updated: 2023/05/25 13:32:01 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_data
{
	int					philo_num;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
    int                 num_of_eat;
}	t_root;

long long	ft_atoi(char *str);
int         check_numbers(char **argv);
int			ft_init(t_root *data, char **argv, int argc);
int			init_args(t_root *data, char **argv, int argc);
