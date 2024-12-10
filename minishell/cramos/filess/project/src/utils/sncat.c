/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sncat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:06:00 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/10/30 14:41:41 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <string.h>

char	*sncat(char *dest, const char *src, size_t n)
{
	char	*original_dest;

	original_dest = dest;
	while (*dest)
		dest++;
	while (n-- > 0 && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (original_dest);
}
