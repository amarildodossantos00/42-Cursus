/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcatete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:29:10 by vcatete           #+#    #+#             */
/*   Updated: 2024/10/13 10:29:13 by vcatete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*t_philosopherhread_func(void *arg)
{
	t_philosopher	*phil;

	phil = (t_philosopher *)arg;
	while (phil->params->someone_died != 1)
	{
		if (phil->params->num_philosophers == 1)
			break ;
		philosopher_think(phil);
		if (phil->params->someone_died)
		{
			pthread_mutex_unlock(phil->left_fork);
			pthread_mutex_unlock(phil->death_mutex);
			return (NULL);
		}
		if (!auxiliary(phil))
			return (NULL);
		if (phil->must_eat != -1 && phil->meals_eaten >= phil->must_eat)
		{
			pthread_mutex_lock(phil->death_mutex);
			phil->params->someone_died = 1;
			pthread_mutex_unlock(phil->death_mutex);
			return (NULL);
		}
	}
	return (NULL);
}

void	*death_monitor_func(void *arg)
{
	t_philosopher	*phil;

	phil = (t_philosopher *)arg;
	while (1)
	{
		pthread_mutex_lock(phil->death_mutex);
		if (phil->params->someone_died)
		{
			pthread_mutex_unlock(phil->death_mutex);
			break ;
		}
		if (get_time_in_ms() - phil->last_meal >= phil->time_to_die)
		{
			printf("%ld %d died\n", get_time_in_ms() - phil->start_time,
				phil->id);
			phil->params->someone_died = 1;
			pthread_mutex_unlock(phil->death_mutex);
			break ;
		}
		pthread_mutex_unlock(phil->death_mutex);
		usleep(1000);
	}
	return (NULL);
}

void	create_t_philosopherhreads(t_params *params, t_philosopher *phil_data,
		t_thread *threads)
{
	int	v;

	v = 0;
	while (v < params->num_philosophers)
	{
		pthread_create(&threads[v].philosopher_thread, NULL,
			t_philosopherhread_func, &phil_data[v]);
		pthread_create(&threads[v].monitor_thread, NULL, death_monitor_func,
			&phil_data[v]);
		v++;
	}
	v = 0;
	while (v < params->num_philosophers)
	{
		pthread_join(threads[v].philosopher_thread, NULL);
		pthread_join(threads[v].monitor_thread, NULL);
		v++;
	}
}

int	main(int argc, char **argv)
{
	t_params		params;
	t_philosopher	*phil_data;
	t_thread		*threads;
	int				v;

	v = 0;
	memset(&phil_data, 0, sizeof(t_philosopher));
	if (!initial_checker(argc, argv))
		return (1);
	initialize_params(&params, argv, argc);
	phil_data = malloc(params.num_philosophers * sizeof(t_philosopher));
	threads = malloc(params.num_philosophers * sizeof(t_thread));
	params.start_time = get_time_in_ms();
	initialize_philosophers(&params, phil_data);
	create_t_philosopherhreads(&params, phil_data, threads);
	while (v < params.num_philosophers)
	{
		pthread_mutex_destroy(&params.forks[v]);
		v++;
	}
	pthread_mutex_destroy(&params.death_mutex);
	free(params.forks);
	free(phil_data);
	free(threads);
	return (0);
}
