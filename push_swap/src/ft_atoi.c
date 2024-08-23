/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 06:28:09 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/08/23 03:14:08 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pswap.h"

int	ft_atoi(char *str)
{
	long long int	res;
	int				signal;

	res = 0;
	signal = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signal = -1;
		str++;
	}
	while (*str)
	{
		if (ft_isdigit(*str))
			ft_error();
		res = res * 10 + *str - '0';
		str++;
	}
	if ((res * signal) > 2147483647 || (res * signal) < -2147483647)
		ft_error();
	return (res * signal);
}
