/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:20:46 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/05/17 16:20:49 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	count;
	size_t	sub_len;
	size_t	lc;
	char	*bbig;

	bbig = (char *)big;
	sub_len = ft_strlen(little);
	if (sub_len == 0)
		return (bbig);
	count = 0;
	while (big[count] != '\0' && count < len)
	{
		lc = 0;
		while (big[count + lc] == little[lc] && count + lc < len)
		{
			if (little[lc + 1] == '\0')
				return (&bbig[count]);
			lc++;
		}
		count++;
	}
	return (NULL);
}
