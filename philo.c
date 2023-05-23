/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:45:02 by ooussaad          #+#    #+#             */
/*   Updated: 2023/05/23 23:26:59 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	size_t			i;
	size_t			result;

	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		return (-1);
	while (str[i] >= 48 && str[i] <= 57 && str[i])
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		(write(2, "Error\n", 6), exit(0));
	return (result);
}

int check_numbers(char **argv)
{
	int j =	1;
    while (argv[j])
	{
		if (ft_atoi(argv[j]) == -2)
			(write(2, "Error SIGN\n", 12), exit(0));		
		j++;
	}
	return (0);
}

int main(int argc,char **argv)
{
    if (argc == 5 || argc == 6)
    {
        if (!check_numbers(argv))
			write(1,"good\n",5);
	}
	else
		(write(2, "Error args\n",11), exit(0));
}