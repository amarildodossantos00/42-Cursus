/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:41:24 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/10/03 10:31:58 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*monitor_thread(void *arg)
{
	int			i;
	//int			num_philos;
	long		current_time;
	long		timestamp;
	//t_philo		*philos;
	t_monitor	*monitor;

	monitor = (t_monitor *)arg;
	//num_philos = monitor->num_philos;
	//philos = monitor->philos;
	while (1)
	{
		i = 0;
		while (i < monitor->num_philos)
		{
			current_time = get_timestamp();
			if ((current_time - monitor->philos[i].last_meal) > monitor->philos[i].time_dead)
			{
				timestamp = get_timestamp();
				printf("%ld %d died\n",timestamp, monitor->philos[i].id);
				exit(0);
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
