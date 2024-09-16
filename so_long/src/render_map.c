/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:55:57 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/16 04:09:33 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	*compare_keep(t_vars *vars, char keep)
{
	if (keep == '1')
		return (vars->wall);
	else if (keep == '0')
		return (vars->way);
	else if (keep == 'C')
		return (vars->collect);
	else if (keep == 'P')
		return (vars->player);
	else if (keep == 'E')
		return (vars->exit);
	else
		return (NULL);
}

static void	render_map_x(int y, t_vars *vars, char **map, int width)
{
	void	*img;
	int		x;
	char	keep;

	x = 0;
	while (x < width)
	{
		keep = map[y][x];
		img = compare_keep(vars, keep);
		if (img)
			mlx_put_image_to_window(vars->mlx, vars->win, img, x
				* PIXEL, y * PIXEL);
		x++;
	}
}

void	render_map(t_vars *vars, char **map)
{
	int	y;

	y = 0;
	while (y < vars->height)
	{
		render_map_x(y, vars, map, vars->width);
		y++;
	}
}
