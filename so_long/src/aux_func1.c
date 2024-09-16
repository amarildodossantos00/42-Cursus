/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_func1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:38:05 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/16 03:43:37 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strdup(char *str)
{
	int		len;
	char	*new;

	len = 0;
	while (str[len])
		len++;
	new = malloc(sizeof(char) * (len + 1));
	len = 0;
	while (str[len])
	{
		new[len] = str[len];
		len++;
	}
	new[len] = '\0';
	return (new);
}

char	*ft_strcat(char *dest, char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (dest[len])
		len++;
	while (str[i])
	{
		dest[len] = str[i];
		len++;
		i++;
	}
	dest[len] = '\0';
	return (dest);
}
