/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:52:46 by cramos            #+#    #+#             */
/*   Updated: 2024/09/05 01:59:32 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	close_window(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	free_split(vars->map);
	free_split(vars->new_map);
	free_img(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

void	close_e(t_vars *vars)
{
	free_split(vars->map);
	free_split(vars->new_map);
	free_img(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

int	close_map(t_vars *vars, int key)
{
	if (key == 65288 || key == 65307)
		close_e(vars);
	return (0);
}
