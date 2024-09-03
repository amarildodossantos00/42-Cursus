/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double_number.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 06:08:09 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/03 10:44:43 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pswap.h"

int	check_double_number(t_stack *stack)
{
	t_stack	*current;
	t_stack	*aux;

	current = stack;
	while (current)
	{
		aux = current->next;
		while (aux)
		{
			if (current->value == aux->value)
				return (0);
			aux = aux->next;
		}
		current = current->next;
	}
	return (1);
}
