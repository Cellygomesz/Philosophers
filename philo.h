/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:22:00 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/03/12 15:59:07 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>

typedef struct s_philo
{
	int	philosophers;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	philo_must_eat;

} t_philo;

#endif
