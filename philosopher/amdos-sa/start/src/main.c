/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:41:53 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/10/07 08:48:27 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char *av[])
{
	int			i;
	int			j;
	int			num_philos;
	t_philo		*philos;
	t_monitor	monitor_data;
	pthread_t	monitor;
	pthread_mutex_t	*forks;

	i = 0;
	j = 0;
	monitor_data.death_occurred = 0;

	if (ac < 5 || ac > 6)
	{
		printf("Uso: %s <num_philos> <time_dead> <time_eat> <time_sleep>\n", av[0]);
		return (-1);
	}

	num_philos = atoi(av[1]);
	philos = (t_philo *)malloc(sizeof(t_philo) * num_philos);
	if (!philos)
	{
		perror("Falha ao alocar memória para filósofos");
		return (-1);
	}

	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num_philos);
	if (!forks)
	{
		perror("Falha ao alocar memória para forks");
		return (-1);
	}

	while (i < num_philos)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			perror("Falha ao inicializar o mutex");
			while (--i >= 0)
				pthread_mutex_destroy(&forks[i]);
			free(forks);
			free(philos);
			return (-1);
		}
		i++;
	}

	i = 0;
	while (i < num_philos)
	{
		philos[i].id =  i + 1;
		philos[i].time_dead = atoi(av[2]);
		philos[i].time_eat = atoi(av[3]);
		philos[i].time_sleep = atoi(av[4]);
		philos[i].left = &forks[i];
		philos[i].right = &forks[(i + 1) % num_philos];
		philos[i].last_meal = get_timestamp();
		philos[i].monitor = &monitor_data;

		if (pthread_create(&philos[i].thread, NULL, process_thread, (void *)&philos[i]) != 0)
		{
			perror("Falha ao criar a thread");
			while (j <= i)
				pthread_mutex_destroy(&forks[j++]);
			free(forks);
			free(philos);
			return (-1);
		}
		i++;
	}

	monitor_data.philos = philos;
	monitor_data.num_philos = num_philos;

	if (pthread_create(&monitor, NULL, monitor_thread, (void *)&monitor_data)!= 0)
	{
		perror("Falha ao criar a thread de monitoramento");
		while (i++ < num_philos)
			pthread_mutex_destroy(&forks[i]);
		free(forks);
		free(philos);
		return (-1);
	}

	i = 0;
	while (i < num_philos)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	pthread_join(monitor, NULL);

	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(forks);
	free(philos);
	return (0);
}

