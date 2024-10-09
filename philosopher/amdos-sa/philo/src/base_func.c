/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 10:12:40 by pzau              #+#    #+#             */
/*   Updated: 2024/10/09 13:52:28 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

static void	pick_forks(t_philo *philo, long start_time)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right);
		printf("[%ld] %d has taken a fork(right)\n",
			get_elapsed_time(start_time), philo->id);
		pthread_mutex_lock(philo->left);
		printf("[%ld] %d has taken a fork(left)\n",
			get_elapsed_time(start_time), philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->left);
		printf("[%ld] %d has taken a fork(left)\n",
			get_elapsed_time(start_time), philo->id);
		pthread_mutex_lock(philo->right);
		printf("[%ld] %d has taken a fork(right)\n",
			get_elapsed_time(start_time), philo->id);
	}
}

static void	eat_and_sleep(t_philo *philo, long start_time)
{
	philo->time_last = get_timestamp();
	printf("[%ld] %d is eating\n",
		get_elapsed_time(start_time), philo->id);
	usleep(philo->p_vars->time_eat * 1000);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	printf("[%ld] %d dropped the forks\n",
		get_elapsed_time(start_time), philo->id);
	printf("[%ld] %d is sleeping\n",
		get_elapsed_time(start_time), philo->id);
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
		printf("[%ld] %d is thinking\n",
			get_elapsed_time(start_time), philo->id);
		pick_forks(philo, start_time);
		eat_and_sleep(philo, start_time);
	}
	return (NULL);
}
