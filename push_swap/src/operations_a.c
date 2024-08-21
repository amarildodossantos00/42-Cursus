/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:13:32 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/08/21 13:50:54 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pswap.h"

void	sa(t_stack **s_a)
{
	t_stack	*aux;

	if (!s_a || !*s_a)
		return ;
	aux = (*s_a)->next;
	(*s_a)->next = aux->next;
	aux->next = *s_a;
	*s_a = aux;
	ft_printf("sa\n");
}

void	pa(t_stack **s_a, t_stack **s_b)
{
	t_stack	*aux;

	if (!s_b || !*s_b)
		return ;
	aux = *s_b;
	*s_b = (*s_b)->next;
	aux->next = *s_a;
	*s_a = aux;
	ft_printf("pa\n");
}

void	ra(t_stack **s_a)
{
	t_stack	*first;
	t_stack	*last;

	if (!s_a || !*s_a || !(*s_a)->next)
		return ;
	first = *s_a;
	last = *s_a;
	while (last->next)
		last = last->next;
	*s_a = first->next;
	first->next = NULL;
	last->next = first;
	ft_printf("ra\n");
}

void	rra(t_stack **s_a)
{
	t_stack	*prev;
	t_stack	*last;

	if (!s_a || *s_a || !(*s_a)->next)
		return ;
	prev = NULL;
	last = *s_a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *s_a;
	*s_a = last;
	ft_printf("rra\n");
}
