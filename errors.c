/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 05:19:07 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/04/01 10:01:06 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	time_philo_meat_error(void)
{
	printf("You need at least " \
	"one philosopher or timestamp more than 60 ms " \
	"or at least meat\n");
	return (0);
}

int	signal_error(int position)
{
	printf("Error! Argument [%i] is a negative number\n", position);
	return (0);
}

int	digit_error(int position)
{
	printf("Error! Argument [%i] is not a number\n", position);
	return (0);
}

int	format_error(void)
{
	printf("Error! ");
	printf("Format: <Number_of_philosophers> <time_to_die> " \
	"<time_to_eat> <time_to_sleep> "\
	"[number_of_times_each_philosopher_must_eat]\n");
	return (FALSE);
}
