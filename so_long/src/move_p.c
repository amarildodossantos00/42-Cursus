/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:18:23 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/16 08:38:53 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	find_player(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			if (vars->map[y][x] == 'P')
			{
				vars->pos_x = x;
				vars->pos_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	count_collect(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	vars->count_collects = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			if (vars->map[y][x] == 'C')
				vars->count_collects++;
			x++;
		}
		y++;
	}
	find_player(vars);
}

static void	press_key(int key, int *x, int *y, t_vars *vars)
{
	if (key == 119)
	{
		*y -= 1;
		vars->b_step = 1;
	}
	else if (key == 115)
	{
		*y += 1;
		vars->b_step = 1;
	}
	else if (key == 100)
	{
		*x += 1;
		vars->b_step = 1;
	}
	else if (key == 97)
	{
		*x -= 1;
		vars->b_step = 1;
	}
}

void	update_positions(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == 'C')
		vars->count_collects--;
	if (vars->map[y][x] == 'E' && vars->count_collects == 0)
	{
		vars->count_steps++;
		ft_printf("\033[37mSTEPS: %d\033[0m\n", vars->count_steps);
		game_win();
		ft_printf("By: Amarildo dos Santos\nUser: amdos-sa\n");
		close_exit(vars);
	}
	else if (vars->map[y][x] == 'E')
	{
		ft_printf("\033[31mSTILL COLLECTS\033[0m\n");
		vars->b_step = 0;
	}
	else
	{
		vars->map[vars->pos_y][vars->pos_x] = '0';
		vars->pos_y = y;
		vars->pos_x = x;
		vars->map[y][x] = 'P';
		render_map(vars, vars->map);
	}
}

int	move_player(int keycode, t_vars *vars)
{
	int	x;
	int	y;

	y = vars->pos_y;
	x = vars->pos_x;
	vars->b_step = 0;
	if (close_esc(keycode, vars))
		return (0);
	press_key(keycode, &x, &y, vars);
	if (x >= 0 && x <= vars->width && y >= 0
		&& y <= vars->height && vars->map[y][x] != '1')
	{
		update_positions(vars, x, y);
		if (vars->b_step == 1)
		{
			vars->count_steps++;
			ft_printf("Steps: %d\n", vars->count_steps);
			vars->b_step = 0;
		}
	}
	return (0);
}
