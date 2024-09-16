/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:31:06 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/16 04:22:49 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	space_main(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		if (str[len] == ' ')
			return (1);
		len++;
	}
	return (0);
}

int	validate_n(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	if (str[0] == '\n')
		return (1);
	if (str[len - 2] != '1')
		return (1);
	if (space_main(str) == 1)
		return (1);
	len = 0;
	while (str[len])
	{
		if (str[(ft_strlen(str) - 2)] != '1')
			return (1);
		if ((len > 1) && (str[len] == '\n'
				|| str[len] == '\0') && (str[len - 1] != '1'))
			return (1);
		len++;
	}
	return (0);
}

void	is_retangle(t_vars *vars)
{
	int	len;
	int	y;

	if (!vars->map[0] || !vars->map)
	{
		ft_printf("Error\n Invalid Map\n");
		close_v(vars);
	}
	len = ft_strlen(vars->map[0]);
	y = 1;
	while (vars->map[y] != NULL)
	{
		if (ft_strlen(vars->map[y]) != len)
		{
			ft_printf("Error\n Invalid Map\n");
			close_v(vars);
		}
		y++;
	}
}

void	extantion(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			i++;
			if (str[i] == 'b' && str[i + 1] == 'e' && str[i + 2] == 'r')
				return ;
			else
			{
				ft_printf("Error\n Invalid extantion\n");
				exit(0);
			}
		}
		i++;
	}
}
