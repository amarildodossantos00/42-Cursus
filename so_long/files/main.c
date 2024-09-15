/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:35:07 by cramos            #+#    #+#             */
/*   Updated: 2024/09/05 03:12:32 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ver_tam_map(t_vars *vars)
{
	int	largura;
	int	altura;

	largura = vars->res_largura * PIXEL;
	altura = vars->res_altura * PIXEL;
	if (largura > 1900 || altura > 1000)
	{
		ft_printf("\nError\nMAP TOO BIG!\n");
		free_split(vars->map);
		exit(1);
	}
}

static void	all_validation(t_vars *vars)
{
	ver_tam_map(vars);
	ver_p(vars);
	ver_e(vars);
	ver_c(vars);
	ver_all_arg(vars);
	ver_retangulo(vars);
	verification(vars);
}

static void	rest(t_vars *vars)
{
	free_split(vars->map);
	free_split(vars->new_map);
	free_img(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
}

int	main(int ac, char *av[])
{
	t_vars		vars;

	if (ac == 2)
	{
		vars.map = save_maps(av[1]);
		vars.new_map = save_maps(av[1]);
		dimen(&vars, av[1]);
		all_validation(&vars);
		vars.count_step = 0;
		vars.button_step = 0;
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, vars.res_largura * PIXEL,
				vars.res_altura * PIXEL, "so_long");
		mlx_hook(vars.win, 17, 0, close_window, &vars);
		imagens(&vars);
		set_img(&vars, vars.map);
		count_collets(&vars);
		mlx_hook(vars.win, 2, 1L << 0, move_p, &vars);
		mlx_loop(vars.mlx);
		rest(&vars);
		free(vars.mlx);
	}
	else
		ft_printf("invalid arguments!\n");
	return (0);
}
