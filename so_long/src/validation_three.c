/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:57:23 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/16 04:10:56 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_map_closed(char **map, int height, int width)
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

static void	finding_start_point(char **matrix, t_vars *vars, char c)
{
	int	k;
	int	x;

	k = 0;
	while (matrix[k])
	{
		x = 0;
		while (matrix[k][x])
		{
			if (matrix[k][x] == c)
			{
				vars->start_point_x = x;
				vars->start_point_y = k;
				return ;
			}
			x++;
		}
		k++;
	}
}

static void	sending_to_flood_fill(t_vars *vars)
{
	finding_start_point(vars->map_copy, vars, 'P');
	flood_fill(vars->start_point_x, vars->start_point_y, vars);
}

static void	func_close(t_vars *vars)
{
	if (strchr_on_matrix(vars->map_copy, 'C') == 1)
	{
		ft_printf("Error:\nInvalid map\n\n");
		free_split(vars->map_copy);
		free_split(vars->map);
		exit(1);
	}
	if (strchr_on_matrix(vars->map_copy, 'P') == 1)
	{
		ft_printf("Error:\nInvalid map\n\n");
		free_split(vars->map_copy);
		free_split(vars->map);
		exit(1);
	}
}

void	playable(t_vars *vars)
{
	if (!is_map_closed(vars->map,
			vars->height, vars->width))
	{
		ft_printf("Error:\nMap not closed\n\n");
		free_split(vars->map_copy);
		free_split(vars->map);
		exit(1);
	}
	sending_to_flood_fill(vars);
	func_close(vars);
	finding_start_point(vars->map_copy, vars, 'E');
	flood(vars->start_point_x, vars->start_point_y, vars);
	if (strchr_on_matrix(vars->map_copy, 'E') == 1)
	{
		ft_printf("Error:\nInvalid map\n\n");
		free_split(vars->map_copy);
		free_split(vars->map);
		exit(1);
	}
}
