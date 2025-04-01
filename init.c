/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 05:11:28 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/04/01 12:17:08 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_table *table, int t_philo)
{
	int	i;

	i = -1;
	while (++i < t_philo)
	{
		table->ph[i].index = i + 1;
		table->ph[i].id = i;
		table->ph[i].l_fork = i;
		table->ph[i].table = table;
		table->ph[i].ate = 0;
		table->ph[i].last_meal = 0;
		pthread_create(&table->ph[i].philo, NULL, &dinner, &table->ph[i]);
	}
	if (table->n_philo != 1)
		scan(table);
}

void	finish_philo(t_table *table, int t_philo)
{
	int	i;

	i = 0;
	while (i < t_philo)
		pthread_join(table->ph[i++].philo, NULL);
	free(table->ph);
}

void	create_fork(t_table *table)
{
	int	i;

	i = -1;
	table->m_fork = malloc(sizeof(t_mutex) * table->n_philo);
	pthread_mutex_init(&table->l_meal, NULL);
	pthread_mutex_init(&table->dead, NULL);
	pthread_mutex_init(&table->print, NULL);
	pthread_mutex_init(&table->food, NULL);
	while (++i < table->n_philo)
		pthread_mutex_init(&table->m_fork[i], NULL);
	i = -1;
	while (++i < table->n_philo)
	{
		if (i == (table->n_philo - 1) && table->n_philo > 1)
			table->ph[i].r_fork = 0;
		else
			table->ph[i].r_fork = i + 1;
	}
}

int	init(t_table *table, int ac, char **av)
{
	table->died = 0;
	table->n_philo = ft_atol(av[1]);
	table->time_die = ft_atol(av[2]);
	table->time_eat = ft_atol(av[3]);
	table->time_dream = ft_atol(av[4]);
	table->start_clock = get_milli_time();
	if (ac == 6)
		table->m_eat = ft_atol(av[5]);
	else
		table->m_eat = -1;
	if (time_check(table) == FALSE)
		return (FALSE);
	return (TRUE);
}
