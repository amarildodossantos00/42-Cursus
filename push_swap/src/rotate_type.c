/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 12:37:53 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/08/31 09:03:42 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pswap.h"

int	rotate_type_ba(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = b;
	i = case_rrarrb_a(a, b, b->value);
	while (tmp)
	{
		if (i > case_rarb_a(a, b, tmp->value))
			i = case_rarb_a(a, b, tmp->value);
		if (i > case_rrarrb_a(a, b, tmp->value))
			i = case_rrarrb_a(a, b, tmp->value);
		if (i > case_rarrb_a(a, b, tmp->value))
			i = case_rarrb_a(a, b, tmp->value);
		if (i > case_rrarb_a(a, b, tmp->value))
			i = case_rrarb_a(a, b, tmp->value);
		tmp = tmp->next;
	}
	return (i);
}

int	rotate_type_ab(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = a;
	i = case_rrarrb(a, b, a->value);
	while (tmp)
	{
		if (i > case_rarb(a, b, tmp->value))
			i = case_rarb(a, b, tmp->value);
		if (i > case_rrarrb(a, b, tmp->value))
			i = case_rrarrb(a, b, tmp->value);
		if (i > case_rarrb(a, b, tmp->value))
			i = case_rarrb(a, b, tmp->value);
		if (i > case_rrarb(a, b, tmp->value))
			i = case_rrarb(a, b, tmp->value);
		tmp = tmp->next;
	}
	return (i);
}
