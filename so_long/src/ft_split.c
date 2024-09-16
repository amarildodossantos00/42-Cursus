/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:00:06 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/16 04:55:36 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_words(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		while (*str && delimeter(*str))
			str++;
		if (*str && !delimeter(*str))
		{
			cnt++;
			while (*str && !delimeter(*str))
				str++;
		}
	}
	return (cnt);
}

char	**alocate_matriz(int word)
{
	char	**matriz;

	matriz = malloc(sizeof(char *) * (word + 1));
	if (!matriz)
		return (NULL);
	matriz[word] = '\0';
	return (matriz);
}

void	fill_matriz(char **matriz, char *s)
{
	int	y;
	int	start;

	y = 0;
	while (*s)
	{
		while (*s && delimeter(*s))
			s++;
		if (*s && !delimeter(*s))
		{
			start = 0;
			while (s[start] && !delimeter(s[start]))
				start++;
			matriz[y] = alocate_word(s, start);
			if (!matriz[y])
			{
				free_split(matriz);
				return ;
			}
			y++;
			s += start;
		}
	}
}

char	**ft_split(char *s)
{
	char	**matriz;
	int		word;

	word = count_words(s);
	matriz = alocate_matriz(word);
	if (!matriz)
		return (NULL);
	fill_matriz(matriz, s);
	return (matriz);
}
