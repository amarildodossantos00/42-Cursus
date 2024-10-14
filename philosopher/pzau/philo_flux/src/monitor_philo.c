/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:39:25 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/10/10 13:36:51 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

void	*monitor_philo(void *arg)
{
	int			i;
	long		current_time;
	long		timetamp;
	long		start_time;
	t_vars		*monitor;

	start_time = get_timestamp();
	monitor = (t_vars *)arg;
	while (1)
	{
		i = 0;

		pthread_mutex_lock(&monitor->routine);
		if (monitor->on_routine == 0)
		{
			pthread_mutex_unlock(&monitor->routine);
			break ;
		}
		pthread_mutex_unlock(&monitor->routine);
		while (i < monitor->num_philo)
		{
			current_time = get_timestamp();
	
				printf("first time: %ld ........ second time: %d\n", (current_time - monitor->philosophers[i].time_last), monitor->philosophers[i].p_vars->time_die);
			pthread_mutex_lock(&monitor->time_last);
			if ((current_time - monitor->philosophers[i].time_last)
				> monitor->philosophers[i].p_vars->time_die)
			{
				pthread_mutex_unlock(&monitor->time_last);

				timetamp = get_elapsed_time(start_time);
				print_sms(&monitor->philosophers[i], DIE, start_time);
				pthread_mutex_lock(&monitor->routine);
				monitor->on_routine = 0;
				pthread_mutex_unlock(&monitor->routine);

			}
			pthread_mutex_unlock(&monitor->time_last);
			i++;
		}
		i = 0;
		if (monitor->num_philo_aux)
		{
			while (i < monitor->num_philo)
			{
				//pthread_mutex_lock(&monitor->time_eat_cont);
				if (monitor->philosophers[i].time_eat_cont != monitor->num_philo_aux)
				{
				//pthread_mutex_unlock(&monitor->time_eat_cont);
					monitor->num_philo_aux = monitor->num_philo_aux;
				}
				else
					i++;
				//pthread_mutex_unlock(&monitor->time_eat_cont);
			}
			if (i == monitor->num_philo)
			{

				pthread_mutex_lock(&monitor->routine);
				monitor->on_routine = 0;
				pthread_mutex_unlock(&monitor->routine);
			}
		}
		usleep(200);
	}
	return (NULL);
}
