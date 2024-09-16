/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:21:35 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/16 04:25:17 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_images(t_vars *vars)
{
	vars->player = mlx_xpm_file_to_image(vars->mlx, "assets/player.xpm",
			&vars->w_img, &vars->h_img);
	vars->way = mlx_xpm_file_to_image(vars->mlx, "assets/way.xpm",
			&vars->w_img, &vars->h_img);
	vars->wall = mlx_xpm_file_to_image(vars->mlx, "assets/wall.xpm",
			&vars->w_img, &vars->h_img);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, "assets/exit.xpm",
			&vars->w_img, &vars->h_img);
	vars->collect = mlx_xpm_file_to_image(vars->mlx, "assets/collect.xpm",
			&vars->w_img, &vars->h_img);
	if (!vars->way)
	{
		ft_printf("Erro\n");
		exit(1);
	}
}

void	destroy_image(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->player);
	mlx_destroy_image(vars->mlx, vars->way);
	mlx_destroy_image(vars->mlx, vars->wall);
	mlx_destroy_image(vars->mlx, vars->exit);
	mlx_destroy_image(vars->mlx, vars->collect);
}
