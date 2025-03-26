/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:22:00 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/03/26 14:21:17 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo
{
	int	philosophers;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	philo_must_eat;
	pthread_mutex_t	forks;
	t_philosopher	*philosophers;

} t_philo;

typedef struct s_philosopher
{
    int id;                      // ID do filósofo (0 a N-1)
    int meals_eaten;             // Quantidade de vezes que ele já comeu
    pthread_t thread;            // Thread associada ao filósofo
    pthread_mutex_t *left_fork;  // Ponteiro para o garfo à esquerda
    pthread_mutex_t *right_fork; // Ponteiro para o garfo à direita
} t_philosopher;


int	ft_atoi(char *nptr);
int	error(int fd);
int	valid_inputs(char *av);

#endif
