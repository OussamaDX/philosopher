/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:45:02 by ooussaad          #+#    #+#             */
/*   Updated: 2023/06/04 02:13:22 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_root	data;

	data.num_of_eat = 0;
	data.max_food = 0;
	if (argc == 5 || argc == 6)
	{
		check_numbers(argv);
		if (!init_args(&data, argv, argc))
			return (0);
		if (ft_create_thread(&data))
			return (0);
	}
	else
		write(2, "Error args \n", 11);
}
