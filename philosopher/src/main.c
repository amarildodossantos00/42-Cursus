/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:41:53 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/23 09:42:47 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
/*
int	count;
pthread_mutex_t count_mutex;

void	*process_thread(void *arg)
{
	int	i;
	
	(void)arg;
	i = 0;
	while (i < 100000)
	{
		pthread_mutex_lock(&count_mutex);
		count++;
		pthread_mutex_unlock(&count_mutex);
		i++;		
	}
	return (NULL);
}

int	main(int ac, char *av[])
{	
	pthread_t	thread;
	pthread_t	thread1;

	count = 0;
	pthread_mutex_init(&count_mutex, NULL);
	pthread_create(&thread, NULL, process_thread, NULL);
	pthread_create(&thread1, NULL, process_thread, NULL);
	pthread_join(thread, NULL);
	pthread_join(thread1, NULL);
	printf("%d", count);
	pthread_mutex_destroy(&count_mutex);
	return (0);
}*/

void	*process_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;	
	while (1)
	{
		printf("%d está pensando\n", philo->id);
		usleep(1000);
		pthread_mutex_lock(philo->left);
		printf("%d pegou um garfo\n", philo->id);
		pthread_mutex_lock(philo->right);
		printf("%d pegou o outro garfo\n", philo->id);
		printf("%d está comendo\n", philo->id);
		usleep(philo->time_eat * 1000);
		printf("%d pegou o outro garfo\n", philo->id);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		printf("%d deixou os garfos\n", philo->id);
		printf("%d está dormindo\n", philo->id);
		usleep(philo->time_sleep * 1000);
	}
}

int	main(int ac, char *av[])
{
	if (ac < 5)
		exit(1);
	t_philo	*philos;
	pthread_mutex_t	*forks;
	int	num_philos;
	int	i;
	
	i = 0;
	num_philos = atoi(av[1]);
	philos = (t_philo *)malloc(sizeof(t_philo) * num_philos);
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num_philos);
	while (i < num_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
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
		pthread_create(&philos[i].thread, NULL, process_thread, (void *)&philos[i]);
		i++;
	}
	i = 0;
	while (i < num_philos)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	return (0);
}







































