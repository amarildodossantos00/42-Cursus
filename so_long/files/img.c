/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:13:14 by cramos            #+#    #+#             */
/*   Updated: 2024/09/05 02:54:06 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	imagens(t_vars *vars)
{
	vars->player = mlx_xpm_file_to_image(vars->mlx, "img/player.xpm",
			&vars->alt_img, &vars->lar_img);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, "img/exit2.xpm",
			&vars->alt_img, &vars->lar_img);
	vars->colecter = mlx_xpm_file_to_image(vars->mlx, "img/coletavel.xpm",
			&vars->alt_img, &vars->lar_img);
	vars->wall = mlx_xpm_file_to_image(vars->mlx, "img/box.xpm",
			&vars->alt_img, &vars->lar_img);
	vars->way = mlx_xpm_file_to_image(vars->mlx, "img/way.xpm",
			&vars->alt_img, &vars->lar_img);
}

void	free_img(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->player);
	mlx_destroy_image(vars->mlx, vars->exit);
	mlx_destroy_image(vars->mlx, vars->colecter);
	mlx_destroy_image(vars->mlx, vars->wall);
	mlx_destroy_image(vars->mlx, vars->way);
}
