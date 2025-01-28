/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubgame.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:57:02 by amdos-sa          #+#    #+#             */
/*   Updated: 2025/01/28 12:14:18 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBGAME_H
# define CUBGAME_H
# define WIDTH 1280
# define HEIGHT 720
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <math.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;

	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}	t_game;


#endif
