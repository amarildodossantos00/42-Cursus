/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:06:17 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/07/24 17:06:19 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minitalk.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		l1;
	int		l2;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	join = malloc((l1 + l2 + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while (i < (l1 + l2))
	{
		if (i < l1)
			join[i] = s1[i];
		else
			join[i] = s2[i - l1];
		i++;
	}
	join[i] = '\0';
	return (join);
}
