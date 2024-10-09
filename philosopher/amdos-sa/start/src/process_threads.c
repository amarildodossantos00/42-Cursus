/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:10:21 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/10/04 14:03:50 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*process_thread(void *arg)
{
	t_philo	*philo;
	long	timestamp;
	long	start_time;

	philo = (t_philo *)arg;
	start_time  = get_timestamp();

	if (philo->id % 2 == 0)
		usleep(1000);

	philo->last_meal = start_time;

	while (!philo->monitor->death_occurred)
	{
		timestamp = get_elapsed_time(start_time);
		printf("[%ld] %d is thinking\n",timestamp, philo->id);

		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(philo->right);
			printf("[%ld] %d has taken a fork (right)\n",get_elapsed_time(start_time), philo->id);
			pthread_mutex_lock(philo->left);
			printf("[%ld] %d has taken a fork (left)\n",get_elapsed_time(start_time), philo->id);
		}
		else
		{
			pthread_mutex_lock(philo->left);
			printf("[%ld] %d has taken a fork (left)\n",get_elapsed_time(start_time), philo->id);
			pthread_mutex_lock(philo->right);
			printf("[%ld] %d has taken a fork (right)\n",get_elapsed_time(start_time), philo->id);
		}

		philo->last_meal = get_timestamp();
		timestamp = get_elapsed_time(start_time);
		printf("[%ld] %d is eating\n",timestamp, philo->id);
		usleep(philo->time_eat * 1000);

		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		printf("[%ld] %d dropped the forks\n",get_elapsed_time(start_time), philo->id);

		printf("[%ld] %d is sleeping\n",get_elapsed_time(start_time), philo->id);
		usleep(philo->time_sleep * 1000);
	}
	return (NULL);
}
