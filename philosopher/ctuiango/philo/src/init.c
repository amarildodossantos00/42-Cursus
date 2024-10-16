/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:52:30 by ctuiango          #+#    #+#             */
/*   Updated: 2024/10/16 13:52:38 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

void	ft_initialize_args(int ac, char **av, t_vars *vars)
{
	vars->num_philo = ft_atoi(av[1]);
	vars->time_die = ft_atoi(av[2]);
	vars->time_eat = ft_atoi(av[3]);
	vars->time_sleep = ft_atoi(av[4]);
	vars->num_philo_aux = 0;
	vars->on_routine = 1;
	if (ac == 6)
		vars->num_philo_aux = ft_atoi(av[5]);
	pthread_mutex_init(&vars->all_mutexs.mutex_last_eat, NULL);
	pthread_mutex_init(&vars->all_mutexs.mutex_on_routine, NULL);
	pthread_mutex_init(&vars->all_mutexs.mutex_print_sms, NULL);
	pthread_mutex_init(&vars->all_mutexs.mutex_one, NULL);
	pthread_mutex_init(&vars->all_mutexs.mutex_have_eaten, NULL);
}

static int	allocate_resources(t_vars *vars)
{
	vars->philosophers = malloc(sizeof(t_philo) * vars->num_philo);
	vars->forks = malloc(sizeof(pthread_mutex_t) * vars->num_philo);
	vars->all_eat = malloc(sizeof(int) * vars->num_philo);
	if (vars->philosophers == NULL || vars->forks == NULL
		|| vars->all_eat == NULL)
	{
		printf("Failed to allocate memory.\n");
		return (1);
	}
	return (0);
}

int	ft_initialize_rest(t_vars *vars, int i)
{
	if (allocate_resources(vars))
		return (1);
	while (i < vars->num_philo)
	{
		pthread_mutex_init(&vars->forks[i], NULL);
		vars->all_eat[i] = 0;
		i++;
	}
	i = 0;
	while (i < vars->num_philo)
	{
		vars->philosophers[i].id = i + 1;
		vars->philosophers[i].time_init = current_time();
		vars->philosophers[i].time_last = current_time();
		vars->philosophers[i].eat_cont = 0;
		vars->philosophers[i].left = &vars->forks[(i + 1) % vars->num_philo];
		vars->philosophers[i].right = &vars->forks[i];
		vars->philosophers[i].p_vars = vars;
		pthread_create(&vars->philosophers[i].thread, NULL,
			&philos_action, &vars->philosophers[i]);
		i++;
	}
	if (vars->num_philo > 1)
		pthread_create(&vars->monitoring, NULL, &philo_monitoring, vars);
	return (0);
}
