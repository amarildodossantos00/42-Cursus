/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:51:52 by ctuiango          #+#    #+#             */
/*   Updated: 2024/10/16 13:51:57 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

static int	is_digit(char str)
{
	if (str >= 48 && str <= 57)
		return (0);
	return (1);
}

static int	cheack_is_number(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == 43)
			j++;
		while (av[i][j])
		{
			if (is_digit(av[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	cheack_num_vals(int ac, char **av)
{
	int	i;
	int	value;

	i = 1;
	while (i < ac)
	{
		value = ft_atoi(av[i]);
		if (value <= 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_error(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		printf("Error: Number of parameters incoreect\n");
		return (1);
	}
	if (cheack_is_number(ac, av))
	{
		printf("Error: Only Allowed posetive numbers\n");
		return (1);
	}
	if (cheack_num_vals(ac, av))
	{
		printf("Error: All values must be greater than zero\n");
		return (1);
	}
	return (0);
}
