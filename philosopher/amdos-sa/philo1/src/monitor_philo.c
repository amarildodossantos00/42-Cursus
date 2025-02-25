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
		while (i < monitor->num_philo)
		{
			current_time = get_timestamp();
			if ((current_time - monitor->philosophers[i].time_last)
				> monitor->philosophers[i].p_vars->time_die)
			{
				timetamp = get_elapsed_time(start_time);
				printf("[%ld] %d died\n", timetamp,
					monitor->philosophers[i].id);
				exit(1);
			}
			i++;
		}
		i = 0;
		if (monitor->num_philo_aux)
		{
			while (i < monitor->num_philo)
			{
				if (monitor->philosophers[i].time_eat_cont != monitor->num_philo_aux)
					monitor->num_philo_aux = monitor->num_philo_aux;
				else
					i++;
			}
			if (i == monitor->num_philo)
				exit(1);
		}
		usleep(200);
	}
}
