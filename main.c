/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:38:23 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/03/21 02:43:12 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_philo info;
    t_philosopher *philosophers;
    pthread_mutex_t *forks;

    // Preenche info com argumentos do programa (exemplo simplificado)
    info.philosophers = 5;
    info.time_die = 800;
    info.time_eat = 200;
    info.time_sleep = 200;
    info.philo_must_eat = -1; // Opcional

    // Inicializa mutexes e filósofos dinamicamente
    forks = init_forks(info.philosophers);
    philosophers = init_philosophers(info.philosophers, forks);

    // Criar as threads depois...

    return (0);
}

/*
int	main(int ac, char **av)
{
	t_philo	*p;

	p = malloc(sizeof(t_philo));
	if (ac != 6)
	{
		error(2);
		exit(0);
	}
	p->philosophers = is_num(av[1]);
	p->time_die = is_num(av[2]);
	p->time_eat = is_num(av[3]);
	p->time_sleep = is_num(av[4]);
	p->philo_must_eat = is_num(av[5]);

	printf("1: %d\n", p->philosophers);
	printf("2: %d\n", p->time_die);
	printf("3: %d\n", p->time_eat);
	printf("4: %d\n", p->time_sleep);
	printf("5: %d\n", p->philo_must_eat);
	free(p);
	return (0);
}
*/

