/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:44:23 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/10/03 10:43:52 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo{
	int				id;
	long			time_dead;
	long			time_eat;
	long			time_sleep;
	long			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}	t_philo;

typedef struct s_monitor{
	t_philo *philos;
	int		num_philos;
}	t_monitor;

void	*process_thread(void *arg);
void	*monitor_thread(void *arg);
long	get_timestamp(void);
long	get_elapsed_time(long start_time);

#endif
