/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxilary.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:59:12 by cramos            #+#    #+#             */
/*   Updated: 2024/09/05 01:56:16 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	count_words(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && deli(*str))
			str++;
		if (*str && !deli(*str))
		{
			count++;
			while (*str && !deli(*str))
				str++;
		}
	}
	return (count);
}

char	*ft_strdup(char *src)
{
	char	*cpy;
	int		len;

	len = 0;
	while (src[len])
		len++;
	cpy = malloc(sizeof(char) * (len + 1));
	len = 0;
	while (src[len])
	{
		cpy[len] = src[len];
		len++;
	}
	cpy[len] = '\0';
	return (cpy);
}

char	*ft_strcat(char *str, char *s)
{
	int	c;
	int	i;

	c = 0;
	while (str[c])
		c++;
	i = 0;
	while (s[i])
	{
		str[c] = s[i];
		c++;
		i++;
	}
	str[c] = '\0';
	return (str);
}

void	free_split(char **matriz)
{
	int	i;

	i = 0;
	if (matriz)
	{
		while (matriz[i])
		{
			free(matriz[i]);
			i++;
		}
		free(matriz);
	}
	return ;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
