/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:19:50 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/05/17 16:19:53 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_count;
	size_t	dest_count;
	size_t	src_len;
	size_t	dest_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	src_count = 0;
	dest_count = dest_len;
	if (size > dest_len)
	{
		while (dest_count < size - 1 && src[src_count] != '\0')
			dst[dest_count++] = src[src_count++];
		dst[dest_count] = '\0';
		return (dest_len + src_len);
	}
	return (src_len + size);
}
