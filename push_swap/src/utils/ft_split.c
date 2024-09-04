/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 08:23:53 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/04 03:11:07 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pswap.h"

int	delimeter(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char	**ft_split(char *str)
{
	int		x;
	int		y;
	int		len;
	char	**matriz;

	y = 0;
	while (*str && delimeter(*str))
		str++;
	len = ft_strlen(str);
	while (str[len])
		len++;
	matriz = malloc(sizeof(char *) * (len + 1));
	while (*str)
	{
		x = 0;
		matriz[y] = malloc(sizeof(char *) * (len + 1));
		while (*str && !delimeter(*str))
			matriz[y][x++] = *(str++);
		while (*str && delimeter(*str))
			str++;
		matriz[y++][x] = '\0';
	}
	matriz[y] = NULL;
	return (matriz);
}
