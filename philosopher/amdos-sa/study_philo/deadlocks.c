/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deadlocks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:02:22 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/10/01 12:06:33 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

#define THREAD_NUM 8

pthread_mutex_t mutexFuel;
int fuel = 50;
pthread_mutex_t mutexWater;
int water = 10;

void*	routine(void* args)
{
	pthread_mutex_lock(&mutexFuel);
	pthread_mutex_lock(&mutexWater);
	fuel += 50;
	water = fuel;
	printf("Incremented fuel to: +%d set water to +%d\n", fuel, water);
	pthread_mutex_unlock(&mutexFuel);
	pthread_mutex_unlock(&mutexWater);
}

int	main(int ac, char *av[])
{
	pthread_t	thread[THREAD_NUM];
	pthread_mutex_init(&mutexFuel, NULL);
	pthread_mutex_init(&mutexWater, NULL);

	int i;
	for (i = 0; i < THREAD_NUM; i++)
	{
		if (pthread_create(&thread[i], NULL, &routine, NULL) != 0)
			perror("Failed to create thread");
	}

	for (i = 0; i < THREAD_NUM; i++)
	{
		if (pthread_join(thread[i], NULL) != 0)
			perror("Failed to join thread");
	}
	printf("\n");
	printf("Fuel: %d\n", fuel);
	printf("Water: %d\n", water);
	pthread_mutex_destroy(&mutexFuel);
	pthread_mutex_destroy(&mutexWater);
	return (0);
}
