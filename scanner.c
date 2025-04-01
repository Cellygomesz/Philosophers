/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 07:15:42 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/04/01 08:15:52 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	meal(t_philo ph)
{
	int	status;

	status = ph.ate;
	return (status);
}

void	print_death(t_philo ph)
{
	pthread_mutex_lock(&ph.table->print);
	printf("%lu\t%i died\n", time_now(&ph), ph.index);
	pthread_mutex_unlock(&ph.table->print);
}

int	scan(t_table *table)
{
	int	i;

	i = 0;
	usleep(200);
	while (1)
	{
		if (meal(table->ph[i]) == table->m_eat)
			break ;
		pthread_mutex_lock(&table->l_meal);
		if (time_now(table->ph) - table->ph[i].last_meal >= table->time_die)
		{
			pthread_mutex_lock(&table->dead);
			table->died = 1;
			pthread_mutex_unlock(&table->dead);
			print_death(table->ph[i]);
			pthread_mutex_unlock(&table->l_meal);
			break ;
		}
		pthread_mutex_unlock(&table->l_meal);
		i = (i + 1) % table->n_philo;
		usleep(200);
	}
	return (TRUE);
}
