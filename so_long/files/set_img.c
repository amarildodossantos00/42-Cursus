/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:13:28 by cramos            #+#    #+#             */
/*   Updated: 2024/09/05 02:58:00 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*ver_img(char c, t_vars *vars)
{
	if (c == '1')
		return (vars->wall);
	else if (c == '0')
		return (vars->way);
	else if (c == 'P')
		return (vars->player);
	else if (c == 'E')
		return (vars->exit);
	else if (c == 'C')
		return (vars->colecter);
	return (NULL);
}

void	set_x_img(t_vars *vars, int y, int largura, char **map)
{
	void	*res_img;
	char	c;
	int		x;

	x = 0;
	while (x < largura)
	{
		c = map[y][x];
		res_img = ver_img(c, vars);
		if (res_img)
			mlx_put_image_to_window(vars->mlx, vars->win,
				res_img, x * PIXEL, y * PIXEL);
		x++;
	}
}

void	set_img(t_vars *vars, char **map)
{
	int	y;

	y = 0;
	while (y < vars->res_altura)
	{
		set_x_img(vars, y, vars->res_largura, map);
		y++;
	}
}
