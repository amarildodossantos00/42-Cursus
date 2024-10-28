/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:20:29 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/05/17 16:20:31 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dest;
	char	*str;
	int		count;

	str = (char *)s;
	dest = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	count = -1;
	while (str[++count] != '\0')
		dest[count] = f(count, str[count]);
	dest[count] = '\0';
	return (dest);
}
