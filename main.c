/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:38:23 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/03/13 11:08:51 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	*p;

	if (!(av[1] || av[2] || av[3] || av[4] || av[5]))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	p->philosophers = ft_atoi(av[1]);
	p->time_die = ft_atoi(av[2]);
	p->time_eat = ft_atoi(av[3]);
	p->time_sleep = ft_atoi(av[4]);
	p->philo_must_eat = ft_atoi(av[5]);

	return (0);
}
