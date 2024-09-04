/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_place_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 06:50:02 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/04 10:55:54 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pswap.h"

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
