/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 04:01:47 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/13 09:50:35 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "minilibx-linux/mlx.h"
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
}t_vars;

char	*ft_strdup(char *src);
char *ft_strcat(char *s1, char *s2);
char	**print_map(char *str);
char	*alocate_space(char *save, char *buffer);
char	*get_next_line(char *filename);

#endif
