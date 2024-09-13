/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 03:53:33 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/13 09:41:52 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	t_vars	vars;

	if (ac == 2)
	{
		vars.map = print_map(av[1]);
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, 500, 500, "so_long");
		mlx_loop(vars.mlx);
	}
	return (0);
}
