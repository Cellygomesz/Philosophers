/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:38:23 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/03/25 15:24:11 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_num(t_philo *p,char **av)
{
	p->philosophers = valid_inputs(av[1]);
	p->time_die = valid_inputs(av[2]);
	p->time_eat = valid_inputs(av[3]);
	p->time_sleep = valid_inputs(av[4]);
	if (av[5])
		p->philo_must_eat = valid_inputs(av[5]);
}

int	main(int ac, char **av)
{
	t_philo	*p;

	p = malloc(sizeof(t_philo));
	if (ac == 5 || ac == 6)
	{
		init_num(p, av);
	}
	else
	{
		error(2);
		free(p);
		exit(0);
	}
	/* printf("1: %d\n", p.philosophers);
	printf("2: %d\n", p.time_die);
	printf("3: %d\n", p.time_eat);
	printf("4: %d\n", p.time_sleep);
	printf("5: %d\n", p.philo_must_eat); */
	return (0);
}


