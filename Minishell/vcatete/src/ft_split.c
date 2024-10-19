/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcatete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 07:56:27 by vcatete           #+#    #+#             */
/*   Updated: 2024/10/19 07:56:29 by vcatete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	count_tokens(char *str, char delimiter)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == delimiter)
			count++;
		str++;
	}
	return (count);
}

void	fill_tokens(char **result, char *str, char delimiter)
{
	char	*token;
	int		index;

	index = 0;
	token = ft_strtok(str, &delimiter);
	while (token != NULL)
	{
		result[index++] = ft_strdup(token);
		token = ft_strtok(NULL, &delimiter);
	}
	result[index] = NULL;
}

char	**ft_split(char *str, char delimiter)
{
	char	**result;
	int		count;

	count = count_tokens(str, delimiter);
	if (count == -1)
		return (NULL);
	result = (char **)malloc((count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result[count] = NULL;
	fill_tokens(result, str, delimiter);
	return (result);
}
