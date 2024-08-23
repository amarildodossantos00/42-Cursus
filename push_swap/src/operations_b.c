/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 05:08:11 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/08/22 06:59:01 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pswap.h"

void	sb(t_stack **s_b, int f)
{
	t_stack	*aux;

	if (!s_b || !*s_b)
		return ;
	aux = (*s_b)->next;
	(*s_b)->next = aux->next;
	aux->next = *s_b;
	*s_b = aux;
	if (f == 1)
		return ;
	ft_printf("sb\n");
}

void	pb(t_stack **s_a, t_stack **s_b)
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

void	rb(t_stack **s_b, int f)
{
	t_stack	*first;
	t_stack	*last;

	if (!s_b || !*s_b || !(*s_b)->next)
		return ;
	first = *s_b;
	last = *s_b;
	while (last->next)
		last = last->next;
	*s_b = first->next;
	first->next = NULL;
	last->next = first;
	if (f == 1)
		return ;
	ft_printf("rb\n");
}

void	rrb(t_stack **s_b, int f)
{
	t_stack	*prev;
	t_stack	*last;

	if (!s_b || *s_b || !(*s_b)->next)
		return ;
	prev = NULL;
	last = *s_b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *s_b;
	*s_b = last;
	if (f == 1)
		return ;
	ft_printf("rra\n");
}
