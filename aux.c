/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:00:43 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/03/13 16:01:28 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(int fd)
{
	write(fd, "Error\n", 6);
	return (1);
}

int	ft_atoi(char *c)
{
	int	i;
	int	neg;
	int	temp;

	i = 0;
	neg = 1;
	temp = 0;
	while (c[i] == ' ' || (c[i] >= 9 && c[i] <= 13))
		i++;
	if (c[i] == '+' || c[i] == '-')
	{
		if (c[i] == '-')
			neg *= -1;
		i++;
	}
	while (c[i] >= '0' && c[i] <= '9')
	{
		temp = (c[i] - '0') + (temp * 10);
		i++;
	}
	return (temp * neg);
}

int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			error(2);
			exit(0);
		}
		i++;
	}
	return (ft_atoi(str));
}
