/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 10:12:40 by pzau              #+#    #+#             */
/*   Updated: 2024/10/10 13:08:48 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

static void	pick_forks(t_philo *philo, long start_time)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right);
		print_sms(philo, FORK, start_time);
		pthread_mutex_lock(philo->left);
		print_sms(philo, FORK, start_time);
	}
	else
	{
		pthread_mutex_lock(philo->left);
		print_sms(philo, FORK, start_time);
		pthread_mutex_lock(philo->right);
		print_sms(philo, FORK, start_time);
	}
}

static void	eat_and_sleep(t_philo *philo, long start_time)
{
	philo->time_last = get_timestamp();
	print_sms(philo, EAT, start_time);
	usleep(philo->p_vars->time_eat * 1000);
//	pthread_mutex_lock(&philo->p_vars->time_eat_cont);
	philo->time_eat_cont++;
//	pthread_mutex_unlock(&philo->p_vars->time_eat_cont);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	print_sms(philo, NOTHING, start_time);
	print_sms(philo, SLEEP, start_time);
	usleep(philo->p_vars->time_sleep * 1000);
}

void	*philos_action(void *param)
{
	long	start_time;
	t_philo	*philo;

	philo = (t_philo *)param;
	start_time = get_timestamp();
	while (1)
	{
		pthread_mutex_lock(&philo->p_vars->routine);
		if (philo->p_vars->on_routine != 1)
		{
			pthread_mutex_unlock(&philo->p_vars->routine);
			break ;
		}
		pthread_mutex_unlock(&philo->p_vars->routine);
		print_sms(philo, THINK, start_time);
		pick_forks(philo, start_time);
		eat_and_sleep(philo, start_time);
	}
	return (NULL);
}
