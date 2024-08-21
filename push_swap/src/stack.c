/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 04:18:03 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/08/21 12:50:05 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pswap.h"

void	_creat_stack(t_stack *stack)
{
	stack = malloc(sizeof(t_stack));
	stack = NULL;
}

void	_push(t_stack **stack, int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node->value = value;
	new_node->next = *stack;
	*stack = new_node;
}

/*t_node	*_pop(t_stack *stack)
{
	t_node	*aux;

	if (stack && stack->top)
	{
		aux = stack->top;
		stack->top = aux->next;
		return (aux);
	}
	else
		ft_printf("func.: _pop --> Empty Stack\n");
	return (NULL);
}
*/

void	free_stack(t_stack *stack)
{
	t_stack	*aux;

	while (stack)
	{
		aux = stack;
		stack = stack->next;
		free(aux);
	}
}
