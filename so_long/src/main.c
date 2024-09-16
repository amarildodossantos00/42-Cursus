/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:34:57 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/16 08:59:42 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac == 2)
	{
		extantion(av[1]);
		vars.map = print_map(av[1]);
		vars.map_copy = print_map(av[1]);
		open_get_size(av[1], &vars);
		validations(&vars);
		is_retangle(&vars);
		playable(&vars);
		game_start();
		vars.count_steps = 0;
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, vars.width * PIXEL,
		vars.height * PIXEL, "so_long");
		mlx_hook(vars.win, 17, 0, close_exit, &vars);
		count_collect(&vars);
		set_images(&vars);
		render_map(&vars, vars.map);
		mlx_hook(vars.win, 2, 1L << 0, move_player, &vars);
		mlx_loop(vars.mlx);
		free_split(vars.map);
		destroy_image(&vars);
		mlx_destroy_window(vars.mlx, vars.win);
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
	}
	return (0);
}
