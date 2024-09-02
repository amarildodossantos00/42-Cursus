/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 06:50:02 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/08/31 09:46:51 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pswap.h"

int	find_index(t_stack *s_a, int num)
{
	int	i;

	i = 0;
	while (s_a->value != num)
	{
		i++;
		s_a = s_a->next;
	}
	return (i);
}

int	find_place_b(t_stack *s_b, int num_push)
{
	int		i;
	t_stack	*aux;

	i = 1;
	if (num_push > s_b->value && num_push < lst_last(s_b)->value)
		i = 0;
	else if (num_push > lst_max(s_b) || num_push < lst_min(s_b))
		i = find_index(s_b, lst_max(s_b));
	else
	{
		aux = s_b->next;
		while (s_b->value < num_push || aux->value > num_push)
		{
			s_b = s_b->next;
			aux = s_b->next;
			i++;
		}
	}
	return (i);
}


int	find_place_a(t_stack *s_a, int num_push)
{
	int		i;
	t_stack	*aux;

	i = 1;
	if (num_push < s_a->value && num_push > lst_last(s_a)->value)
		i = 0;
	else if (num_push > lst_max(s_a) || num_push < lst_min(s_a))
		i = find_index(s_a, lst_min(s_a));
	else
	{
		aux = s_a->next;
		while (s_a->value > num_push || aux->value < num_push)
		{
			s_a = s_a->next;
			aux = s_a->next;
			i++;
		}
	}
	return (i);
}
