/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:41:24 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/10/01 14:47:24 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*monitor_thread(void *arg)
{
	int			i;
	int			num_philos;
	long		current_time;
	t_philo		*philos;
	t_monitor	*monitor;

	i = 0;
	monitor = (t_monitor *)arg;
	num_philos = monitor->num_philos;
	philos = monitor->philos;
	while (1)
	{
		while (i < num_philos)
		{
			i = 0;
			current_time = get_timestamp();
			if ((current_time - philos[i].last_meal) > philos[i].time_dead)
			{
				printf("%d morreu\n", philos[i].id);
				exit(0);
			}
			i++;
		}
	}
	return (NULL);
}
