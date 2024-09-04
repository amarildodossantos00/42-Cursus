/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_place_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:55:03 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/04 10:55:16 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pswap.h"

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
