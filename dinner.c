/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 07:12:24 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/04/01 14:19:28 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_menu(t_philo *ph)
{
	if (ph->id % 2 != 0)
		usleep(100);
}

void	take_fork(t_philo *ph)
{
	if (ph->id % 2 != 0 && ph->index != ph->table->n_philo)
	{
		pthread_mutex_lock(&ph->table->m_fork[ph->l_fork]);
		print(FORK, ph);
		pthread_mutex_lock(&ph->table->m_fork[ph->r_fork]);
		print(FORK, ph);
	}
	else
	{
		pthread_mutex_lock(&ph->table->m_fork[ph->r_fork]);
		print(FORK, ph);
		pthread_mutex_lock(&ph->table->m_fork[ph->l_fork]);
		print(FORK, ph);
	}
}
