/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:29:13 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/10/08 14:41:28 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

void	initial_aux(t_vars *vars)
{
	vars->philosophers = malloc(sizeof(t_philo) * (vars->num_philo));
	vars->forks = malloc(sizeof(pthread_mutex_t) * (vars->num_philo));
	return ;
}

void	print_sms(t_philo *philo, int n, long start_time)
{
	pthread_mutex_lock(&philo->p_vars->routine);
	if (philo->p_vars->on_routine == 0)
	{
		pthread_mutex_unlock(&philo->p_vars->routine);
		return ;
	}
	pthread_mutex_unlock(&philo->p_vars->routine);

	pthread_mutex_lock(&philo->p_vars->print);
	if (n == EAT)
		printf("[%ld] %d is eating\n", get_elapsed_time(start_time), philo->id);
	else if (n == THINK)
		printf("[%ld] %d is thinking\n", get_elapsed_time(start_time), philo->id);
	else if (n == NOTHING)
		printf("[%ld] %d dropped the forks\n", get_elapsed_time(start_time), philo->id);
	else if (n == SLEEP)
		printf("[%ld] %d is sleeping\n", get_elapsed_time(start_time), philo->id);
	else if (n == FORK)
		printf("[%ld] %d has taken a fork\n", get_elapsed_time(start_time), philo->id);
	else if (n == DIE)
		printf("[%ld] %d died\n", get_elapsed_time(start_time), philo->id);
	pthread_mutex_unlock(&philo->p_vars->print);
}
