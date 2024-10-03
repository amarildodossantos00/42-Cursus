/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:10:21 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/10/03 10:51:24 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*process_thread(void *arg)
{
	t_philo	*philo;
	long	timestamp;
	long	start_time;

	philo = (t_philo *)arg;
	start_time = get_(start_time);
	if (philo->id % 2 == 0)
		usleep(1000);
	philo->last_meal = get_elapsed_time(start_time);
	while (1)
	{
		timestamp = get_elapsed_time(start_time);
		printf("%ld %d is thinking\n",timestamp, philo->id);

		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(philo->right);
			timestamp = get_elapsed_time(start_time);
			printf("%ld %d has taken a fork (right)\n",timestamp, philo->id);
			pthread_mutex_lock(philo->left);
			timestamp = get_elapsed_time(start_time);
			printf("%ld %d has taken a fork (left)\n",timestamp, philo->id);
		}
		else
		{
			pthread_mutex_lock(philo->left);
			timestamp = get_elapsed_time(start_time);
			printf("%ld %d has taken a fork (left)\n",timestamp, philo->id);
			pthread_mutex_lock(philo->right);
			timestamp = get_elapsed_time(start_time);
			printf("%ld %d has taken a fork (right)\n",timestamp, philo->id);
		}
		timestamp = get_elapsed_time(start_time);
		printf("%ld %d is eat\n",timestamp, philo->id);
		philo->last_meal = timestamp;
		usleep(philo->time_eat * 1000);

		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		timestamp = get_elapsed_time(start_time);
		printf("%ld %d dropped the forks\n",timestamp, philo->id);

		timestamp = get_elapsed_time(start_time);
		printf("%ld %d is sleeping\n",timestamp, philo->id);
		usleep(philo->time_sleep * 1000);
	}
}
