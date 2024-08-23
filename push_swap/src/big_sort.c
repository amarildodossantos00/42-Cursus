/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:54:42 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/08/23 14:33:27 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pswap.h"

void	sort_turk(t_stack **s_a, t_stack **s_b)
{
	int		tcase;
	t_stack	*aux;

	while (lst(*s_a) > 3 && !check_order(*s_a))
	{
		aux = *s_a;
		tcase = case_rarb();
	}
}

t_stack	*sort_b(t_stack **s_a)
{
	t_stack	*s_b;

	_creat_stack(s_b);
	if (lst_size(*s_a) > 3 && !check_order(*s_a))
		pb(s_a, &s_b);
	if (lst_size(*s_a) > 3 && !check_order(*s_a))
		pb(s_a, &s_b);
	if (lst_size(*s_a) > 3 && !check_order(*s_a))
		sort_turk(s_a, &s_b);
	if (!check_order(*s_a))
		small_sort(s_a);
	return (s_b);
}

void	big_sort(t_stack ***s_a)
{
	int		index;
	t_stack	*s_b;

	_creat_stack(s_b);
	s_b = sort_b(s_a);
}
