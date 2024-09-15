/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 14:30:55 by cramos            #+#    #+#             */
/*   Updated: 2024/09/05 02:13:20 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	deli(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char	*allocate_word(const char *start, int length)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (length + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < length)
	{
		word[i] = start[i];
		i++;
	}
	word[length] = '\0';
	return (word);
}

char	**allocate_matriz(int words)
{
	char	**matriz;

	matriz = malloc(sizeof(char *) * (words + 1));
	if (!matriz)
		return (NULL);
	matriz[words] = NULL;
	return (matriz);
}

void	fill_matriz(char **matriz, char *s, int words)
{
	int	y;
	int	start;

	y = 0;
	while (*s)
	{
		while (*s && deli(*s))
			s++;
		if (*s && !deli(*s))
		{
			start = 0;
			while (s[start] && !deli(s[start]))
				start++;
			matriz[y] = allocate_word(s, start);
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

char	**ft_split(char *str)
{
	char	**matriz;
	int		words;

	words = count_words(str);
	matriz = allocate_matriz(words);
	if (!matriz)
		return (NULL);
	fill_matriz(matriz, str, words);
	return (matriz);
}
