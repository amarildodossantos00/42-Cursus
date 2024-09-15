/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 00:14:26 by cramos            #+#    #+#             */
/*   Updated: 2024/09/05 02:06:13 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	flood_fill(int x, int y, t_vars *vars)
{
	if (x < 0 || x >= vars->res_largura || y < 0 || y >= vars->res_altura)
		return ;
	if (vars->new_map[y][x] == 'V')
		return ;
	if (vars->new_map[y][x] == '1' || vars->new_map[y][x] == 'E')
		return ;
	vars->new_map[y][x] = 'V';
	flood_fill(x + 1, y, vars);
	flood_fill(x - 1, y, vars);
	flood_fill(x, y + 1, vars);
	flood_fill(x, y - 1, vars);
}

void	flood(int x, int y, t_vars *vars)
{
	if (x < 0 || x >= vars->res_largura || y < 0 || y >= vars->res_altura)
		return ;
	if (vars->new_map[y][x] == 'F')
		return ;
	if (vars->new_map[y][x] == '1')
		return ;
	vars->new_map[y][x] = 'F';
	flood(x + 1, y, vars);
	flood(x - 1, y, vars);
	flood(x, y + 1, vars);
	flood(x, y - 1, vars);
}

int	strchr_on_matriz(char **matriz, char c)
{
	int	i;

	i = 0;
	while (matriz[i])
	{
		if (strchr(matriz[i], c))
			return (1);
		i++;
	}
	return (0);
}

int	valid_file(char *str)
{
	int	i;

	i = 0;
	if ((str[0] == '\n'))
		return (0);
	while (str[i])
	{
		if (str[(ft_strlen(str) - 2)] != '1')
			return (0);
		if ((i > 1) && (str[i] == '\n' || str[i] == '\0')
			&& (str[i - 1] != '1'))
			return (0);
		i++;
	}
	return (1);
}

void	rest_read(void)
{
	perror("nothing");
	exit(1);
}
