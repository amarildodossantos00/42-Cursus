/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:33:31 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/13 10:16:41 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	int	len;

	len = 0;
	while (src[len])
		len++;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	len = 0;
	while (src[len])
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	return (dest);
}
