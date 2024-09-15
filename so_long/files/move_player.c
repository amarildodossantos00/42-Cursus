/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:57:31 by cramos            #+#    #+#             */
/*   Updated: 2024/09/05 02:24:46 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	find_player(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->res_altura)
	{
		x = 0;
		while (x < vars->res_largura)
		{
			if (vars->map[y][x] == 'P')
			{
				vars->x = x;
				vars->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	count_collets(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	vars->quanty_collets = 0;
	while (y < vars->res_altura)
	{
		x = 0;
		while (x < vars->res_largura)
		{
			if (vars->map[y][x] == 'C')
				vars->quanty_collets += 1;
			x++;
		}
		y++;
	}
	find_player(vars);
}

void	find_keyboard(t_vars *vars, int key, int *x, int *y)
{
	if (key == 119)
	{
		*y -= 1;
		vars->button_step = 1;
	}
	else if (key == 115)
	{
		*y += 1;
		vars->button_step = 1;
	}
	else if (key == 97)
	{
		*x -= 1;
		vars->button_step = 1;
	}
	else if (key == 100)
	{
		*x += 1;
		vars->button_step = 1;
	}
}

void	swap_img(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == 'C')
		vars->quanty_collets--;
	if (vars->map[y][x] == 'E' && vars->quanty_collets == 0)
	{
		vars->count_step++;
		ft_printf("\nstep: %d\n", vars->count_step);
		ft_printf("\nWIN\n");
		close_e(vars);
	}
	else if (vars->map[y][x] == 'E')
	{
		vars->button_step = 0;
		ft_printf("\nTRERE ARE COLLETS\n");
	}
	else
	{
		vars->map[vars->y][vars->x] = '0';
		vars->y = y;
		vars->x = x;
		vars->map[vars->y][vars->x] = 'P';
		set_img(vars, vars->map);
	}
}

int	move_p(int key, t_vars *vars)
{
	int	x;
	int	y;

	y = vars->y;
	x = vars->x;
	if (close_map(vars, key))
		return (0);
	find_keyboard(vars, key, &x, &y);
	if (x >= 0 && x <= vars->res_largura && y >= 0
		&& y <= vars->res_altura && vars->map[y][x] != '1')
	{
		swap_img(vars, x, y);
		if (vars->button_step == 1)
		{
			vars->count_step++;
			ft_printf("\nstep: %d\n", vars->count_step);
			vars->button_step = 0;
		}
	}
}
