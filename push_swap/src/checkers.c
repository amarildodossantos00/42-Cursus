/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 06:08:09 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/02 06:03:23 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pswap.h"

int	check_is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_order(t_stack *stack)
{
	int	i;

	i = stack->value;
	while (stack)
	{
		if (i > stack->value)
			return (0);
		i = stack->value;
		stack = stack->next;
	}
	return (1);
}

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
