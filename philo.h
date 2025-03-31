/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:22:00 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/03/31 15:42:46 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_rules {
    int	num_philos;         // Número total de filósofos
    int	time_to_die;        // Tempo máximo que um filósofo pode ficar sem comer antes de morrer (ms)
    int	time_to_eat;        // Tempo que um filósofo leva para comer (ms)
    int	time_to_sleep;      // Tempo que um filósofo leva para dormir (ms)
    pthread_mutex_t	*forks; // Array de mutexes representando os garfos
    pthread_mutex_t	write_mutex; // Mutex para evitar condições de corrida na impressão
    int	someone_died;       // Flag para indicar se um filósofo morreu (1 = morreu, 0 = continua)
} t_rules;

typedef struct s_philo {
    int	id;                // ID do filósofo (vai de 0 a num_philos - 1)
    long	last_meal_time;   // Timestamp da última refeição do filósofo (usado para monitorar a fome)
    int	meals_eaten;       // Contador de quantas vezes o filósofo já comeu
    pthread_mutex_t	*left_fork;  // Ponteiro para o mutex do garfo à esquerda
    pthread_mutex_t	*right_fork; // Ponteiro para o mutex do garfo à direita
    pthread_mutex_t	meal_mutex;  // Mutex para proteger o acesso ao tempo da última refeição
    t_rules	*rules;        // Ponteiro para acessar as regras e configurações globais do programa
} t_philo;

int	ft_atoi(char *nptr);
int	error(int fd);
int	valid_inputs(char *av);

#endif
