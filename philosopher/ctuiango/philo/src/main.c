/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:53:29 by ctuiango          #+#    #+#             */
/*   Updated: 2024/10/16 13:53:32 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

int	main(int ac, char **av)
{
	t_vars	vars;
	int		error;

	error = ft_check_error(ac, av);
	if (error)
	{
		printf("Usage: <num_philo> <time_die> <time_eat>");
		printf(" <time_sleep> <n_time_philo_eat>\n");
		return (1);
	}
	ft_initialize_args(ac, av, &vars);
	ft_initialize_rest(&vars, 0);
	ft_dispose_all(&vars);
	return (0);
}
