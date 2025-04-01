/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 07:15:42 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/04/01 14:11:02 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_death(t_philo ph)
{
	pthread_mutex_lock(&ph.table->food);
	pthread_mutex_lock(&ph.table->print);
	printf("%lu\t%i died\n", time_now(&ph), ph.index);
	pthread_mutex_unlock(&ph.table->print);
	pthread_mutex_unlock(&ph.table->food);
}

static int	check_status(t_table *table, int i)
{
	pthread_mutex_lock(&table->food);
	if (table->ph[i].ate == table->m_eat)
	{
		pthread_mutex_unlock(&table->food);
		return (FALSE);
	}
	pthread_mutex_unlock(&table->food);
	pthread_mutex_lock(&table->l_meal);
	if (time_now(table->ph) - table->ph[i].last_meal > table->time_die)
	{
		pthread_mutex_lock(&table->dead);
		table->died = 1;
		pthread_mutex_unlock(&table->dead);
		print_death(table->ph[i]);
		pthread_mutex_unlock(&table->l_meal);
		return (FALSE);
	}
	pthread_mutex_unlock(&table->l_meal);
	return (TRUE);
}

int	scan(t_table *table)
{
	int	i;

	i = 0;
	usleep(200);
	while (1)
	{
		if (!check_status(table, i))
			break ;
		i = (i + 1) % table->n_philo;
		usleep(200);
	}
	return (TRUE);
}
