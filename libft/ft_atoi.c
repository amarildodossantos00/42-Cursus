/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:10:25 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/05/17 16:10:29 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	count;
	int	sign;
	int	result;

	count = 0;
	while (nptr[count] == ' ' || (nptr[count] >= 9 && nptr[count] <= 13))
		count++;
	sign = 1;
	if (nptr[count] == '-' || nptr[count] == '+')
	{
		if (nptr[count] == '-')
			sign *= -1;
		count++;
	}
	result = 0;
	while (nptr[count] >= '0' && nptr[count] <= '9')
	{
		result *= 10;
		result += nptr[count] - '0';
		count++;
	}
	return (result * sign);
}
