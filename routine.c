/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 07:14:04 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/04/01 12:20:05 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(int action, t_philo *ph)
{
	pthread_mutex_lock(&ph->table->dead);
	pthread_mutex_lock(&ph->table->print);
	if (action == THINK && ph->table->died == 0)
		printf("%ld\t%i is thinking\n", time_now(ph), ph->index);
	else if (action == DREAMS && ph->table->died == 0)
		printf("%ld\t%i is sleeping\n", time_now(ph), ph->index);
	else if (action == EAT && ph->table->died == 0)
		printf("%lu\t%i is eating\n", time_now(ph), ph->index);
	else if (action == FORK && ph->table->died == 0)
		printf("%ld\t%i has taken a fork\n", time_now(ph), ph->index);
	pthread_mutex_unlock(&ph->table->print);
	pthread_mutex_unlock(&ph->table->dead);
}

void	think(t_philo *ph)
{
	print(THINK, ph);
}

void	dreams(t_philo *ph)
{
	print(DREAMS, ph);
	smart_sleep(ph->table->time_dream, ph);
}
