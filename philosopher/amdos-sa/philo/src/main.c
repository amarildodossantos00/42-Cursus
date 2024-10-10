/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:10:29 by pzau              #+#    #+#             */
/*   Updated: 2024/10/10 10:51:42 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

int	main(int ac, char **av)
{
	int			error;
	int			i;
	t_vars		vars;
	pthread_t	monitor;

	error = ft_check_error(ac, av);
	if (error)
	{
		printf("Usage: <num_philo> <time_die> <time_eat>");
		printf(" <time_sleep> <n_time_philo_eat>\n");
		return (1);
	}
	ft_initialize_args(ac, av, &vars);
	ft_initialize_rest(&vars, 0);
	if (pthread_create(&monitor, NULL, monitor_philo, (void *)&vars) != 0)
	{
		perror("Falha ao criar a thread de monitoramento");
		while (i++ < vars.num_philo)
			pthread_mutex_destroy(&vars.forks[i]);
		free(vars.forks);
		free(vars.philosophers);
		return (-1);
	}
	ft_dispose_all(&vars);
	return (0);
}
