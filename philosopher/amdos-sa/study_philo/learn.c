/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:54:52 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/10/01 09:55:36 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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
}
