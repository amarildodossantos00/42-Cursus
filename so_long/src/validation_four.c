/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_four.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:57:16 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/16 08:39:13 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	flood_fill(int x, int y, t_vars *vars)
{
	if (x < 0 || x >= vars->width
		|| y < 0 || y >= vars->height)
		return ;
	if (vars->map_copy[y][x] == 'V')
		return ;
	if (vars->map_copy[y][x] == '1' || vars->map_copy[y][x] == 'E')
		return ;
	vars->map_copy[y][x] = 'V';
	flood_fill(x + 1, y, vars);
	flood_fill(x - 1, y, vars);
	flood_fill(x, y + 1, vars);
	flood_fill(x, y - 1, vars);
}

void	flood(int x, int y, t_vars *vars)
{
	if (x < 0 || x >= vars->width
		|| y < 0 || y >= vars->height)
		return ;
	if (vars->map_copy[y][x] == 'F')
		return ;
	if (vars->map_copy[y][x] == '1')
		return ;
	vars->map_copy[y][x] = 'F';
	// User: amdos-sa
	flood(x + 1, y, vars);
	flood(x - 1, y, vars);
	flood(x, y + 1, vars);
	flood(x, y - 1, vars);
}

int	strchr_on_matrix(char **matrix, char c)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		if (strchr(matrix[i], c))
			return (1);
		i++;
	}
	return (0);
}
