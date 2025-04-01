/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:22:00 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/04/01 12:16:36 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

# define TRUE 1
# define FALSE 0
# define DINNER 42
# define EAT 90
# define THINK 91
# define DREAMS 92
# define DEAD 93
# define FORK 94

typedef struct s_table	t_table;
typedef struct s_philo	t_philo;
typedef pthread_mutex_t	t_mutex;

typedef struct s_philo
{
	int				index;
	int				id;
	long			last_meal;
	int				r_fork;
	int				l_fork;
	int				ate;
	pthread_t		philo;
	t_table			*table;
}	t_philo;

typedef struct s_table
{
	t_mutex		*m_fork;
	t_mutex		print;
	t_mutex		l_meal;
	t_mutex		food;
	t_mutex		dead;

	int			died;
	int			m_eat;
	int			n_philo;
	long		start_clock;
	long		time_eat;
	long		time_die;
	long		time_dream;
	pthread_t	scanner;
	t_philo		*ph;
}	t_table;

// UTILS FUNCTIONS //

int		ft_isdigit(char c);
long	get_milli_time(void);
long	time_now(t_philo *ph);
long	ft_atol(const char *str);
void	smart_sleep(long duration, t_philo *ph);
void	print(int action, t_philo *ph);
void	print_death(t_philo ph);

// ERROR FUNCTIONS //

int		time_philo_meat_error(void);
int		digit_error(int position);
int		signal_error(int position);
int		format_error(void);

// VALIDATES FUNCTIONS //

int		valid_input(int ac, char **av);
int		time_check(t_table *table);
int		str_isdigit(char *str);

// INIT FUNCTIONS //

int		init(t_table *table, int ac, char **av);
void	init_philo(t_table *table, int t_philo);
void	finish_philo(t_table *table, int t_philo);
void	create_fork(t_table *table);

// SCAN FUNCTIONS //

int		scan(t_table *table);

// MUTEX FUNCTIONS //

void	destroy_mutex(t_table *table);

// DINNER FUNCTIONS //

void	one_dinner(t_philo *ph);
void	*dinner(void *t);
void	dreams(t_philo *ph);
void	eat(t_philo *ph);
void	think(t_philo *ph);
void	take_fork(t_philo *ph);
void	check_menu(t_philo *ph);

#endif
