/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:58:30 by ooussaad          #+#    #+#             */
/*   Updated: 2023/06/04 02:19:00 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_atoi(char *str)
{
	size_t	i;
	size_t	result;

	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		return (0);
	while (str[i] >= 48 && str[i] <= 57 && str[i] && result <= INT32_MAX)
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (0);
	if (result > INT32_MAX)
		return (0);
	return (result);
}

int	check_numbers(char **argv)
{
	int	j;

	j = 1;
	while (argv[j])
	{
		if (ft_atoi(argv[j]) == 0)
			(write(2, "Error NUMBER\n", 14), exit(0));
		j++;
	}
	return (0);
}
