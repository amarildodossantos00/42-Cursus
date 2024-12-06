/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:28:19 by aliberal          #+#    #+#             */
/*   Updated: 2024/11/10 18:35:12 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

static int	nbnb(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char	*is_zero(int nb, char *str)
{
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	long	nb;

	nb = n;
	i = nbnb(nb);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (is_zero(nb, str))
		return (str);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb != 0)
	{
		str[i--] = '0' + (nb % 10);
		nb = nb / 10;
	}
	return (str);
}
