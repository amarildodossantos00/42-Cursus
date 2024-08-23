/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 08:23:02 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/08/22 11:23:35 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pswap.h"

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("|%d", stack->value);
		stack = stack->next;
	}
}
