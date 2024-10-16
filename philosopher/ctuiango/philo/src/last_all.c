/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:53:18 by ctuiango          #+#    #+#             */
/*   Updated: 2024/10/16 13:53:22 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

void	one_philosopher(t_philo *philo)
{
	print_all_messagers(philo, FORK);
	usleep(philo->p_vars->time_die * 1000);
	print_all_messagers(philo, DEAD);
	return ;
}

static void	destroy_all(t_vars *vars)
{
	if (vars->num_philo > 1)
	{
		pthread_mutex_destroy(&vars->all_mutexs.mutex_last_eat);
		pthread_mutex_destroy(&vars->all_mutexs.mutex_on_routine);
		pthread_mutex_destroy(&vars->all_mutexs.mutex_print_sms);
		pthread_mutex_destroy(&vars->all_mutexs.mutex_one);
		pthread_mutex_destroy(&vars->all_mutexs.mutex_have_eaten);
	}
}

void	ft_dispose_all(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->num_philo > 1)
	{
		if (pthread_join(vars->monitoring, NULL) != 0)
			printf("Falhou!\n");
	}
	while (i < vars->num_philo)
	{
		if (pthread_join(vars->philosophers[i].thread, NULL) != 0)
			printf("Falhou!\n");
		i++;
	}
	i = 0;
	while (i < vars->num_philo)
	{
		pthread_mutex_destroy(&vars->forks[i]);
		i++;
	}
	destroy_all(vars);
	free(vars->philosophers);
	free(vars->forks);
	free(vars->all_eat);
}
