/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:39:17 by cramos            #+#    #+#             */
/*   Updated: 2024/09/05 03:08:52 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define PIXEL 64

# include "../minilibx-linux/mlx.h"
# include "../ftprintf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_vars
{
	t_point		start_point;
	void		*mlx;
	void		*win;
	void		*player;
	void		*exit;
	void		*colecter;
	void		*wall;
	void		*way;
	char		**map;
	char		**new_map;
	int			res_altura;
	int			res_largura;
	int			alt_img;
	int			lar_img;
	int			x;
	int			y;
	int			quanty_collets;
	int			count_step;
	int			button_step;
	int			count_p;
	int			count_e;
	int			count_c;
	int			ver_all;
}	t_vars;

void	fill_matriz(char **matriz, char *s, int words);
void	free_split(char **matriz);
void	screen_value(t_vars *vars, int fd);
void	dimen(t_vars *vars, char *file_name);
void	imagens(t_vars *vars);
void	free_img(t_vars *vars);
void	*ver_img(char c, t_vars *vars);
void	set_x_img(t_vars *vars, int y, int largura, char **map);
void	set_img(t_vars *vars, char **map);
void	find_player(t_vars *vars);
void	count_collets(t_vars *vars);
void	find_keyboard(t_vars *vars, int key, int *x, int *y);
void	swap_img(t_vars *vars, int x, int y);
void	close_e(t_vars *vars);
void	ver_p(t_vars *vars);
void	ver_e(t_vars *vars);
void	ver_c(t_vars *vars);
void	ver_all_arg(t_vars *vars);
void	ver_retangulo(t_vars *vars);
void	finding_start_point(char **matriz, t_vars *vars, char c);
void	sending_to_flood_fill(t_vars *vars);
void	verification(t_vars *vars);
void	func_close(t_vars *vars);
void	flood_fill(int x, int y, t_vars *vars);
void	rest_read(void);
void	flood(int x, int y, t_vars *vars);
char	*new_read(char *new_read, char *buffer);
char	*read_files(char *file_name);
char	**save_maps(char *file_name);
char	*allocate_word(const char *start, int length);
char	**allocate_matriz(int words);
char	**ft_split(char *str);
char	*ft_strdup(char *src);
char	*ft_strcat(char *str, char *s);
int		deli(char c);
int		count_words(char *str);
int		close_window(void *param);
int		move_p(int key, t_vars *vars);
int		ft_strlen(char *str);
int		close_map(t_vars *vars, int key);
int		is_map_closed(char **map, int height, int width);
int		strchr_on_matriz(char **matriz, char c);
int		valid_file(char *str);

#endif
