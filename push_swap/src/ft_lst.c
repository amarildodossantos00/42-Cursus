/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 03:27:20 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/08/23 03:34:42 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pswap.h"

int	lst_min(t_stack *stack)
{
	int	min;

	min = 0;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
			stack = stack->next;
	}
	return (min);
}

int	lst_max(t_stack *stack)
{
	int	max;

	max = 0;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			stack = stack->next;
		}
	}
	return (max);
}
