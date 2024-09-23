/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:44:23 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/23 09:48:08 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_philo{
	int	id;
	long	time_dead;
	long	time_eat;
	long	time_sleep;
	pthread_t thread;
	pthread_mutex_t *left;
	pthread_mutex_t *right;
}	t_philo;

void *process_thread(void *arg);

#endif
