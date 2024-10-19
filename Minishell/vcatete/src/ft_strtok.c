/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcatete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 07:56:34 by vcatete           #+#    #+#             */
/*   Updated: 2024/10/19 07:56:36 by vcatete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char	*skip_delimiters(char *str, const char *delim)
{
	while (*str && ft_strchr((char *)delim, *str))
		str++;
	return (str);
}

char	*find_token_end(char *str, const char *delim)
{
	while (*str && !ft_strchr((char *)delim, *str))
		str++;
	return (str);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*last = NULL;

	if (str == NULL)
		str = last;
	if (str == NULL)
		return (NULL);
	str = skip_delimiters(str, delim);
	if (*str == '\0')
		return (NULL);
	last = find_token_end(str, delim);
	if (*last)
	{
		*last = '\0';
		last++;
	}
	else
		last = NULL;
	return (str);
}
