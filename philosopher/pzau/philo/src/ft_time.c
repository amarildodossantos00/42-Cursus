/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:21:28 by pzau              #+#    #+#             */
/*   Updated: 2024/10/07 19:21:46 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

long	current_time(void)
{
	struct timeval	time;
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

static int		philo_died(t_philo *philo, long	current)
{
	pthread_mutex_lock(&philo->p_vars->all_mutexs.mutex_died);
	if ((current - philo->time_last) > (size_t)philo->p_vars->time_die)
	{
		print_all_messagers(philo, DEAD);
		pthread_mutex_lock(&philo->p_vars->all_mutexs.mew_mutex_died);
		philo->p_vars->on_routine = 0;
		pthread_mutex_unlock(&philo->p_vars->all_mutexs.mew_mutex_died);
		pthread_mutex_unlock(&philo->p_vars->all_mutexs.mutex_died);
		return (1);
	}
	pthread_mutex_unlock(&philo->p_vars->all_mutexs.mutex_died);
	return (0);
}

void	*philo_monitoring(void *param)
{
	t_vars	*vars;
	int				i;
	long		current;

	vars = (t_vars *)param;
	i = 0;
	while  (1)
	{
		usleep(100);
    	pthread_mutex_lock(&vars->all_mutexs.mutex_on_routine);
		if (!vars->on_routine)
		{
    		pthread_mutex_unlock(&vars->all_mutexs.mutex_on_routine);
			break ;
		}
    	pthread_mutex_unlock(&vars->all_mutexs.mutex_on_routine);
		i = 0;
		while (i < vars->num_philo)
		{
			current = current_time();
			if (philo_died(&vars->philosophers[i], current))
				break ;
			i++;
		}
	}
}
