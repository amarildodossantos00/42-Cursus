/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:44:59 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/16 03:58:15 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	validate_p(t_vars *vars)
{
	int	x;
	int	y;
	int	p;

	y = 0;
	p = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			if (vars->map[y][x] == 'P')
				p++;
			x++;
		}
		y++;
	}
	if (p != 1)
	{
		ft_printf("Error\n Only allow to open with one Player");
		close_v(vars);
	}
}

static void	validate_c(t_vars *vars)
{
	int	x;
	int	y;
	int	c;

	y = 0;
	c = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			if (vars->map[y][x] == 'C')
				c++;
			x++;
		}
		y++;
	}
	if (c < 1)
	{
		ft_printf("Error\n Only allow to open with one or more Collects");
		close_v(vars);
	}
}

static void	validate_e(t_vars *vars)
{
	int	x;
	int	y;
	int	e;

	y = 0;
	e = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			if (vars->map[y][x] == 'E')
				e++;
			x++;
		}
		y++;
	}
	if (e != 1)
	{
		ft_printf("Error\n Only allow to open with one Exit");
		close_v(vars);
	}
}

static void	validate_all(t_vars *vars)
{
	int		x;
	int		y;
	char	map;

	y = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			map = vars->map[y][x];
			if (map != 'E' && map != 'P' && map != 'C'
				&& map != '1' && map != '0')
			{
				ft_printf("Error\n Strange elemant");
				close_v(vars);
			}
			x++;
		}
		y++;
	}
}

void	validations(t_vars *vars)
{
	validate_p(vars);
	validate_e(vars);
	validate_c(vars);
	validate_all(vars);
}
