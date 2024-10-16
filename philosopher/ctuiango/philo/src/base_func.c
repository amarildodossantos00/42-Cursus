/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:51:36 by ctuiango          #+#    #+#             */
/*   Updated: 2024/10/16 13:51:46 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

static void	eating_action(t_philo *philo)
{
	printf("[%ld]ms philo %d have eaten\n",
		current_time() - philo->time_init, philo->id);
	pthread_mutex_lock(&philo->p_vars->all_mutexs.mutex_last_eat);
	philo->time_last = current_time();
	pthread_mutex_unlock(&philo->p_vars->all_mutexs.mutex_last_eat);
	philo->eat_cont++;
	if (philo->p_vars->num_philo_aux)
	{
		if (philo->eat_cont == philo->p_vars->num_philo_aux)
		{
			pthread_mutex_lock(&philo->p_vars->all_mutexs.mutex_have_eaten);
			philo->p_vars->all_eat[philo->id - 1] = 1;
			pthread_mutex_unlock(&philo->p_vars->all_mutexs.mutex_have_eaten);
		}
	}
}

static void	only_print(t_philo *philo, int n)
{
	if (n == EAT)
		eating_action(philo);
	else if (n == SLEEP)
		printf("[%ld]ms philo %d is sleeping\n",
			current_time() - philo->time_init, philo->id);
	else if (n == THINK)
		printf("[%ld]ms philo %d is thinking\n",
			current_time() - philo->time_init, philo->id);
	else if (n == DEAD)
		printf("[%ld]ms philo %d died\n",
			current_time() - philo->time_init, philo->id);
	else if (n == FORK)
		printf("[%ld]ms philo %d take a fork\n",
			current_time() - philo->time_init, philo->id);
}

void	print_all_messagers(t_philo *philo, int n)
{
	if (philo->p_vars->all_eat[philo->id -1])
	{
		return ;
	}
	pthread_mutex_lock(&philo->p_vars->all_mutexs.mutex_on_routine);
	if (!philo->p_vars->on_routine)
	{
		pthread_mutex_unlock(&philo->p_vars->all_mutexs.mutex_on_routine);
		return ;
	}
	pthread_mutex_unlock(&philo->p_vars->all_mutexs.mutex_on_routine);
	pthread_mutex_lock(&philo->p_vars->all_mutexs.mutex_print_sms);
	only_print(philo, n);
	pthread_mutex_unlock(&philo->p_vars->all_mutexs.mutex_print_sms);
}

static void	running_messagers(t_philo *philo)
{
	print_forks(philo);
	print_all_messagers(philo, EAT);
	usleep(philo->p_vars->time_eat * 1000);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
	print_all_messagers(philo, SLEEP);
	usleep(philo->p_vars->time_sleep * 1000);
	print_all_messagers(philo, THINK);
}

void	*philos_action(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	while (1)
	{
		pthread_mutex_lock(&philo->p_vars->all_mutexs.mutex_on_routine);
		if (philo->p_vars->on_routine != 1)
		{
			pthread_mutex_unlock(&philo->p_vars->all_mutexs.mutex_on_routine);
			break ;
		}
		pthread_mutex_unlock(&philo->p_vars->all_mutexs.mutex_on_routine);
		if (philo->p_vars->num_philo == 1)
		{
			one_philosopher(philo);
			break ;
		}
		running_messagers(philo);
	}
}
