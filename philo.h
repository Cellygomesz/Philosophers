/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:22:00 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/03/13 15:29:51 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_philo
{
	int	philosophers;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	philo_must_eat;

} t_philo;

int	ft_atoi(char *nptr);
int	error(int fd);
int	is_num(char *str);

#endif
