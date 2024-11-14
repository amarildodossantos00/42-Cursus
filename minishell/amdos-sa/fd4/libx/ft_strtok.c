/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:32:28 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/11/12 11:03:42 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*current_position;
	char		*start;

	if (str != NULL)
		current_position = str;
	else if (current_position == NULL)
		return (NULL);
	while (*current_position && ft_strchr(delim, *current_position))
		current_position++;
	if (*current_position == '\0')
		return (NULL);
	start = current_position;
	while (*current_position && !ft_strchr(delim, *current_position))
		current_position++;
	if (*current_position)
	{
		*current_position = '\0';
		current_position++;
	}
	else
		current_position = NULL;
	return (start);
}
