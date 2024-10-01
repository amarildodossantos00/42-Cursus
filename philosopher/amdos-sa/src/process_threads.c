/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:10:21 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/10/01 14:49:08 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*process_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal = get_timestamp();
	while (1)
	{
		printf("%d está pensando\n", philo->id);

		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(philo->right);
			printf("%d pegou o outro garfo\n", philo->id);
			pthread_mutex_lock(philo->left);
			printf("%d pegou um garfo\n", philo->id);
		}
		else
		{
			pthread_mutex_lock(philo->left);
			printf("%d pegou um garfo\n", philo->id);
			pthread_mutex_lock(philo->right);
			printf("%d pegou o outro garfo\n", philo->id);
		}
		printf("%d está comendo\n", philo->id);
		usleep(philo->time_eat * 1000);

		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		printf("%d deixou os garfos\n", philo->id);

		printf("%d está dormindo\n", philo->id);
		usleep(philo->time_sleep * 1000);
	}
}
