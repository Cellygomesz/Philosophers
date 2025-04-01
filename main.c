/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:38:23 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/04/01 08:06:44 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->n_philo)
		pthread_mutex_destroy(&table->m_fork[i]);
	pthread_mutex_destroy(&table->creed);
	pthread_mutex_destroy(&table->dead);
	pthread_mutex_destroy(&table->l_meal);
	pthread_mutex_destroy(&table->print);
	free(table->m_fork);
}

void	one_dinner(t_philo *ph)
{
	print(FORK, ph);
	smart_sleep(ph->table->time_die, ph);
	print_death(ph[0]);
}

int	main(int ac, char **av)
{
	t_table	table;

	if (!valid_input(ac, av) || !init(&table, ac, av))
		return (0);
	table.ph = malloc(sizeof(t_philo) * table.n_philo);
	create_fork(&table);
	init_philo(&table, table.n_philo);
	finish_philo(&table, table.n_philo);
	return (0);
}
