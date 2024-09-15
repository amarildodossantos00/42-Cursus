/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_argum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:47:45 by cramos            #+#    #+#             */
/*   Updated: 2024/09/05 02:45:03 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ver_p(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	vars->count_p = 0;
	while (y < vars->res_altura)
	{
		x = 0;
		while (x < vars->res_largura)
		{
			if (vars->map[y][x] == 'P')
			{
				vars->count_p++;
			}
			x++;
		}
		y++;
	}
	if (vars->count_p != 1)
	{
		ft_printf("\nError\nONLY ONE PLAYER IS ALLOWED\n");
		free_split(vars->map);
		free_split(vars->new_map);
		exit(1);
	}
}

void	ver_e(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	vars->count_e = 0;
	while (y < vars->res_altura)
	{
		x = 0;
		while (x < vars->res_largura)
		{
			if (vars->map[y][x] == 'E')
			{
				vars->count_e++;
			}
			x++;
		}
		y++;
	}
	if (vars->count_e != 1)
	{
		ft_printf("\nError\nONLY ONE EXIT IS ALLOWED\n");
		free_split(vars->map);
		free_split(vars->new_map);
		exit(1);
	}
}

void	ver_c(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	vars->count_c = 0;
	while (y < vars->res_altura)
	{
		x = 0;
		while (x < vars->res_largura)
		{
			if (vars->map[y][x] == 'C')
			{
				vars->count_c++;
			}
			x++;
		}
		y++;
	}
	if (vars->count_c < 1)
	{
		ft_printf("\nError\nONLY ONE OR MORE\n");
		free_split(vars->map);
		free_split(vars->new_map);
		exit(1);
	}
}

void	ver_all_arg(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (y < vars->res_altura)
	{
		x = 0;
		while (x < vars->res_largura)
		{
			if (vars->map[y][x] != 'P' && vars->map[y][x] != 'E'
				&& vars->map[y][x] != 'C' && vars->map[y][x] != '0'
				&& vars->map[y][x] != '1')
			{
				ft_printf("\nError\nINVALID MAP!!\n");
				free_split(vars->map);
				free_split(vars->new_map);
				exit(1);
			}
			x++;
		}
		y++;
	}
}

void	ver_retangulo(t_vars *vars)
{
	int	tam_line;
	int	y;

	y = 0;
	if (!vars->map || vars->map[0] == NULL)
	{
		ft_printf("\nError\nINVALID MAP!!\n");
		free_split(vars->new_map);
		free_split(vars->map);
		exit(1);
	}
	tam_line = ft_strlen(vars->map[0]);
	while (vars->map[y] != NULL)
	{
		if (ft_strlen(vars->map[y]) != tam_line)
		{
			ft_printf("\nError\nIS NOT A RETANGLE!!\n");
			free_split(vars->map);
			free_split(vars->new_map);
			exit(1);
		}
		y++;
	}
}
