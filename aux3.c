/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:12:26 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/04/01 12:21:02 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*check_dinner_status(t_philo *ph)
{
	while (DINNER)
	{
		pthread_mutex_lock(&ph->table->food);
		if (ph->ate == ph->table->m_eat)
		{
			pthread_mutex_unlock(&ph->table->food);
			return (NULL);
		}
		pthread_mutex_unlock(&ph->table->food);
		pthread_mutex_lock(&ph->table->dead);
		if (ph->table->died == 1)
			break ;
		pthread_mutex_unlock(&ph->table->dead);
		take_fork(ph);
		eat(ph);
		dreams(ph);
		think(ph);
	}
	pthread_mutex_unlock(&ph->table->dead);
	return (NULL);
}

void	*dinner(void *t)
{
	t_philo	*ph;

	ph = (t_philo *)t;
	if (ph->table->n_philo == 1)
	{
		one_dinner(ph);
		return (NULL);
	}
	check_menu(ph);
	return (check_dinner_status(ph));
}

static void	update_meal_status(t_philo *ph)
{
	pthread_mutex_lock(&ph->table->food);
	ph->ate += 1;
	pthread_mutex_unlock(&ph->table->food);
	smart_sleep(ph->table->time_eat, ph);
	pthread_mutex_lock(&ph->table->l_meal);
	ph->last_meal = time_now(ph);
	pthread_mutex_unlock(&ph->table->l_meal);
}

void	eat(t_philo *ph)
{
	print(EAT, ph);
	update_meal_status(ph);
	if (ph->id % 2 && ph->index != ph->table->n_philo)
	{
		pthread_mutex_unlock(&ph->table->m_fork[ph->l_fork]);
		pthread_mutex_unlock(&ph->table->m_fork[ph->r_fork]);
	}
	else
	{
		pthread_mutex_unlock(&ph->table->m_fork[ph->r_fork]);
		pthread_mutex_unlock(&ph->table->m_fork[ph->l_fork]);
	}
}
