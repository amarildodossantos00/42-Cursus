/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vali_jogab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 23:15:11 by cramos            #+#    #+#             */
/*   Updated: 2024/09/05 02:51:02 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_map_closed(char **map, int height, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	finding_start_point(char **matriz, t_vars *vars, char c)
{
	int	k;
	int	x;

	k = 0;
	while (matriz[k])
	{
		x = 0;
		while (matriz[k][x])
		{
			if (matriz[k][x] == c)
			{
				vars->start_point.x = x;
				vars->start_point.y = k;
				return ;
			}
			x++;
		}
		k++;
	}
}

void	sending_to_flood_fill(t_vars *vars)
{
	finding_start_point(vars->new_map, vars, 'P');
	flood_fill(vars->start_point.x, vars->start_point.y, vars);
}

void	verification(t_vars *vars)
{
	if (!is_map_closed(vars->map, vars->res_altura, vars->res_largura))
	{
		ft_printf("\nError\nMAP NOT CLOSED!!\n");
		free_split(vars->map);
		free_split(vars->new_map);
		exit(1);
	}
	sending_to_flood_fill(vars);
	func_close(vars);
	finding_start_point(vars->new_map, vars, 'E');
	flood(vars->start_point.x, vars->start_point.y, vars);
	if (strchr_on_matriz(vars->new_map, 'E') == 1)
	{
		ft_printf("\nError\nINVALID MAP!!\n");
		free_split(vars->map);
		free_split(vars->new_map);
		exit(1);
	}
}

void	func_close(t_vars *vars)
{
	if (strchr_on_matriz(vars->new_map, 'C') == 1)
	{
		ft_printf("\nError\nINVALID MAP!\n");
		free_split(vars->map);
		free_split(vars->new_map);
		exit(1);
	}
	if (strchr_on_matriz(vars->new_map, 'P') == 1)
	{
		ft_printf("\nError\nINVALID MAP!!\n");
		free_split(vars->map);
		free_split(vars->new_map);
		exit(1);
	}
}
