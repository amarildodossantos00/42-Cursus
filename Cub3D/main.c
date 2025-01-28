/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:56:52 by amdos-sa          #+#    #+#             */
/*   Updated: 2025/01/28 13:51:42 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cubgame.h"

/*void	close_program(void *mlx, void *mlx_win, void *img)
{
	if (img)
		mlx_destroy_image(mlx, img); // Libere a imagem
	if (mlx_win)
		mlx_destroy_window(mlx, mlx_win); // Libere a janela
	mlx_destroy_display(mlx); // Libere o display (Linux)
	free(mlx); // Libere o ponteiro mlx
	exit(0); // Encerre o programa
}

int	handle_close(void *params)
{
	void	**data;

	data = (void **)params; // Data contém mlx, mlx_win, img
	close_program(data[0], data[1], data[2]);
	return (0);
}*/

void	put_pixel(t_game *game, int x, int y, int color)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->size_line + x * game->bpp / 8;
	game->data[index] = color & 0xFF;
	game->data[index + 1] = (color >> 8) & 0xFF;
	game->data[index + 2] = (color >> 16) & 0xFF;
}

void	draw_square(t_game *game, int x, int y, int size, int color)
{
	int	i;

	i = 0;
	while (i < size)
	{
		put_pixel(game, x + i, y, color);
		i++;
	}
	i = 0;
	while (i < size)
	{
		put_pixel(game, x + size, y + i, color);
			i++;
	}
	i = 0;
	while (i < size)
	{
		put_pixel(game, x + i, y + size, color);
		i++;
	}
	i = 0;
	while (i < size)
	{
		put_pixel(game, x, y + i, color);
		i++;
	}
}

void	init_cub3d(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cub3D");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line, &game->endian);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

int	main(void)
{
	t_game	game;

	init_cub3d(&game);
	draw_square(&game, WIDTH / 2, HEIGHT / 2, 77, 0x00FF00);
	mlx_loop(game.mlx);
	return (0);
}
