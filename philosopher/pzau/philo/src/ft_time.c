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
/* *************************************************************************** */

#include "../header/header.h"

long	current_time(void)
{
	struct timeval	time;
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

static int		philo_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->p_vars->all_mutexs.mutex_last_eat);
	if ((current_time() - philo->time_last) > (size_t)philo->p_vars->time_die + 3)
	{
		pthread_mutex_unlock(&philo->p_vars->all_mutexs.mutex_last_eat);
		print_all_messagers(philo, DEAD);
		pthread_mutex_lock(&philo->p_vars->all_mutexs.mew_mutex_died);
		philo->p_vars->on_routine = 0;
		pthread_mutex_unlock(&philo->p_vars->all_mutexs.mew_mutex_died);
		return (1);
	}
	pthread_mutex_unlock(&philo->p_vars->all_mutexs.mutex_last_eat);
	return (0);
}

static int philo_eat(t_vars *vars)
{
	int		i;

    i = 0;
	while (i < vars->num_philo)
	{
		pthread_mutex_lock(&vars->all_mutexs.mutex_have_eaten);
		if (vars->all_eat[i] == 0)
		{
			pthread_mutex_unlock(&vars->all_mutexs.mutex_have_eaten);
			return (0);
		}
		pthread_mutex_unlock(&vars->all_mutexs.mutex_have_eaten);
		i++;
	}
	pthread_mutex_lock(&vars->all_mutexs.mew_mutex_died);
	vars->on_routine = 0;
	pthread_mutex_unlock(&vars->all_mutexs.mew_mutex_died);
	return (1);
}


void	*philo_monitoring(void *param)
{
	t_vars	*vars;
	int				i;

	vars = (t_vars *)param;
	i = 0;
	pthread_mutex_lock(&vars->all_mutexs.mutex_message);
	while (1)
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
			if (philo_died(&vars->philosophers[i]))
				break ;
			if (vars->num_philo_aux)
			{
				if (philo_eat(vars))
					break ;
			}
			i++;
		}
	}
	pthread_mutex_unlock(&vars->all_mutexs.mutex_message);
}
