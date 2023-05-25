/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:45:02 by ooussaad          #+#    #+#             */
/*   Updated: 2023/05/25 13:30:50 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_root *init_data(void)
{
	t_root *ptr = malloc(sizeof(t_root));
	if (!ptr)
		return NULL;
	ptr->philo_num = 0;
	ptr->time_to_die = 0;
	ptr->time_to_eat = 0;
	ptr->time_to_sleep = 0;
    ptr->num_of_eat = 0;
	return (ptr);
}

int main(int argc,char **argv)
{
	t_root *data ;
	data = init_data();
    if (argc == 5 || argc == 6)
    {
        if (!check_numbers(argv))
			printf("\e[0;32mcorrect number \n");
		if (init_args(data,argv,argc))
			printf("\e[0;32mcorrect input");
		else
			(write(2, "Error int \n",12), exit(0));
	}
	else
		(write(2, "Error args \n",11), exit(0));
}