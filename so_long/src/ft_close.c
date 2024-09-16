/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:30:01 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/16 03:59:42 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_exit(void *noth)
{
	t_vars	*vars;

	vars = (t_vars *)noth;
	free_split(vars->map);
	free_split(vars->map_copy);
	destroy_image(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

void	close_v(t_vars *vars)
{
	free_split(vars->map);
	free_split(vars->map_copy);
	exit(0);
}

int	close_esc(int keycode, t_vars *vars)
{
	if (keycode == 65288 || keycode == 65307)
		close_exit(vars);
	return (0);
}
