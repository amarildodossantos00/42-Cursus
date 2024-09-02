/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 07:16:45 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/02 06:13:54 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pswap.h"

void	sort_three(t_stack **s_a)
{
	if (lst_min(*s_a) == (*s_a)->value)
	{
		ft_rra(s_a, 0);
		ft_sa(s_a, 0);
	}
	else if (lst_max(*s_a) == (*s_a)->value)
	{
		ft_ra(s_a, 0);
		if (!check_order(*s_a))
			ft_sa(s_a, 0);
	}
	else
	{
		if (find_index(*s_a, lst_max(*s_a)) == 1)
			ft_rra(s_a, 0);
		else
			ft_sa(s_a, 0);
	}
}

void	sort_b_till_3(t_stack **s_a, t_stack **s_b)
{
	int		i;
	t_stack	*tmp;

	while (lst_size(*s_a) > 3 && !check_order(*s_a))
	{
		tmp = *s_a;
		i = rotate_type_ab(*s_a, *s_b);
		while (i >= 0)
		{
			if (i == case_rarb(*s_a, *s_b, tmp->value))
				i = apply_rarb(s_a, s_b, tmp->value, 'a');
			else if (i == case_rrarrb(*s_a, *s_b, tmp->value))
				i = apply_rrarrb(s_a, s_b, tmp->value, 'a');
			else if (i == case_rarrb(*s_a, *s_b, tmp->value))
				i = apply_rarrb(s_a, s_b, tmp->value, 'a');
			else if (i == case_rrarb(*s_a, *s_b, tmp->value))
				i = apply_rrarb(s_a, s_b, tmp->value, 'a');
			else
				tmp = tmp->next;
		}
	}
}

t_stack	*sort_stack_b(t_stack **s_a)
{
	t_stack	*s_b;

	s_b = NULL;
	if (lst_size(*s_a) > 3 && !check_order(*s_a))
		ft_pb(s_a, &s_b, 0);
	if (lst_size(*s_a) > 3 && !check_order(*s_a))
		ft_pb(s_a, &s_b, 0);
	if (lst_size(*s_a) > 3 && !check_order(*s_a))
		sort_b_till_3(s_a, &s_b);
	if (!check_order(*s_a))
		sort_three(s_a);
	return (s_b);
}

t_stack	**sort_stack_a(t_stack **s_a, t_stack **s_b)
{
	int		i;
	t_stack	*aux;

	while (*s_b)
	{
		aux = *s_b;
		i = rotate_type_ba(*s_a, *s_b);
		while (i >= 0)
		{
			if (i == case_rarb_a(*s_a, *s_b, aux->value))
				i = apply_rarb(s_a, s_b, aux->value, 'b');
			else if (i == case_rarrb_a(*s_a, *s_b, aux->value))
				i = apply_rarrb(s_a, s_b, aux->value, 'b');
			else if (i == case_rrarrb_a(*s_a, *s_b, aux->value))
				i = apply_rrarrb(s_a, s_b, aux->value, 'b');
			else if (i == case_rrarb_a(*s_a, *s_b, aux->value))
				i = apply_rrarb(s_a, s_b, aux->value, 'b');
			else
				aux = aux->next;
		}
	}
	return (s_a);
}

void	algorithm(t_stack **s_a)
{
	t_stack	*s_b;
	int		i;

	s_b = NULL;
	if (lst_size(*s_a) == 2)
		ft_sa(s_a, 0);
	else
	{
		s_b = sort_stack_b(s_a);
		s_a = sort_stack_a(s_a, &s_b);
		i = find_index(*s_a, lst_min(*s_a));
		if (i < lst_size(*s_a) - i)
		{
			while ((*s_a)->value != lst_min(*s_a))
				ft_ra(s_a, 0);
		}
		else
		{
			while ((*s_a)->value != lst_min(*s_a))
				ft_rra(s_a, 0);
		}
	}
}
