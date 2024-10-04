/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:41:24 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/10/04 13:36:59 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*monitor_thread(void *arg)
{
	//int			num_philos;
	long		current_time;
	long		timestamp;
	long		start_time = get_timestamp();
	//t_philo		*philos;
	t_monitor	*monitor;

	monitor = (t_monitor *)arg;
	//num_philos = monitor->num_philos;
	//philos = monitor->philos;
	while (1)
	{
		for (int i = 0; i < monitor->num_philos; i++)
		{
			current_time = get_timestamp();
			// Verifica se o filósofo ultrapassou o tempo de morte
			if ((current_time - monitor->philos[i].last_meal) > monitor->philos[i].time_dead)
			{
				timestamp = get_elapsed_time(start_time);  // Calcula o tempo decorrido desde o início
				printf("[%ld] %d died\n", timestamp, monitor->philos[i].id);
				monitor->death_occurred = 1;  // Marca que um filósofo morreu
				return NULL;  // Finaliza o monitoramento
			}
		}
		if (monitor->death_occurred)
			return NULL;
		usleep(1000);
	}
}
