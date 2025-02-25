/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:10:29 by pzau              #+#    #+#             */
/*   Updated: 2024/10/10 10:15:58 by amdos-sa         ###   ########.fr       */
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
	vars->stop = 0;
	if (ac == 6)
		vars->num_philo_aux = ft_atoi(av[5]);
}

int	ft_initialize_rest(t_vars *vars, int i)
{
	initial_aux(vars);
	if (vars->philosophers == NULL || vars->forks == NULL)
		return (1);
	pthread_mutex_init(&vars->routine, NULL);
	pthread_mutex_init(&vars->print, NULL);
	pthread_mutex_init(&vars->time_last, NULL);
	pthread_mutex_init(&vars->time_eat_cont, NULL);
	while (i < vars->num_philo)
	{
		pthread_mutex_init(&vars->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < vars->num_philo)
	{
		vars->philosophers[i].id = i + 1;
		vars->philosophers[i].time_init = get_timestamp();
		vars->philosophers[i].time_last = get_timestamp();
		vars->philosophers[i].time_eat_cont = 0;
		vars->philosophers[i].left = &vars->forks[(i + 1) % vars->num_philo];
		vars->philosophers[i].right = &vars->forks[i];
		vars->philosophers[i].p_vars = vars;
		pthread_create(&vars->philosophers[i].thread, NULL, &philos_action,
			&vars->philosophers[i]);
		i++;
	}
	return (0);
}
