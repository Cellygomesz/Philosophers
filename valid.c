/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 05:16:32 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/04/01 10:56:45 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	time_check(t_table *table)
{
	if (table->time_die < 60 || \
	table->time_eat < 60 || \
	table->time_dream < 60)
		return (time_philo_meat_error());
	return (TRUE);
}

int	valid_input(int ac, char **av)
{
	int	i;

	if (ac != 5 && ac != 6)
		return (format_error());
	else
	{
		i = 0;
		while (av[++i])
		{
			if (av[i][0] == '0')
				return (time_philo_meat_error());
			if (!ft_isdigit(av[i][0]))
			{
				if (av[i][0] == '-')
					return (signal_error(i));
				return (digit_error(i));
			}
		}
	}
	return (TRUE);
}
