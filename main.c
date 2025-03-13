/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:38:23 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/03/13 16:04:13 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// tratar "./philo 1 2 4 5+ 6" esse tipo de coisa

int	main(int ac, char **av)
{
	t_philo	*p;

	p = malloc(sizeof(t_philo));
	if (ac != 6)
	{
		error(2);
		exit(0);
	}
	p->philosophers = ft_atoi(av[1]);
	p->time_die = ft_atoi(av[2]);
	p->time_eat = ft_atoi(av[3]);
	p->time_sleep = ft_atoi(av[4]);
	p->philo_must_eat = ft_atoi(av[5]);

	printf("1: %d\n", p->philosophers);
	printf("2: %d\n", p->time_die);
	printf("3: %d\n", p->time_eat);
	printf("4: %d\n", p->time_sleep);
	printf("5: %d\n", p->philo_must_eat);

	free(p);
	return (0);
}
