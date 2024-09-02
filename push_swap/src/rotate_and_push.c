/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 03:06:15 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/02 02:59:27 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pswap.h"

int	apply_rarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a) && (*a)->value != c && find_place_b(*b, c) > 0)
			ft_rr(a, b, 0);
		while ((*a) && (*a)->value != c)
			ft_ra(a, 0);
		while ((*b) && find_place_b(*b, c) > 0)
			ft_rb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while ((*b) && (*b)->value != c && find_place_a(*a, c) > 0)
			ft_rr(a, b, 0);
		while ((*b) && (*b)->value != c)
			ft_rb(b, 0);
		while ((*a) && find_place_a(*a, c) > 0)
			ft_ra(a, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

int	apply_rrarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a) && (*a)->value != c && find_place_b(*b, c) > 0)
			ft_rrr(a, b, 0);
		while ((*a) && (*a)->value != c)
			ft_rra(a, 0);
		while ((*b) && find_place_b(*b, c) > 0)
			ft_rrb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while ((*b)->value != c && find_place_a(*a, c) > 0)
			ft_rrr(a, b, 0);
		while ((*b)->value != c)
			ft_rrb(b, 0);
		while ((*a) && find_place_a(*a, c) > 0)
			ft_rra(a, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

int	apply_rrarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a) && (*a)->value != c)
			ft_rra(a, 0);
		while ((*b) && find_place_b(*b, c) > 0)
			ft_rb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while ((*a) && find_place_a(*a, c) > 0)
			ft_rra(a, 0);
		while ((*b) && (*b)->value != c)
			ft_rb(b, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

int	apply_rarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a) && (*a)->value != c)
			ft_ra(a, 0);
		while ((*a) && find_place_b(*b, c) > 0)
			ft_rrb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while ((*a) && find_place_a(*a, c) > 0)
			ft_ra(a, 0);
		while ((*b) && (*b)->value != c)
			ft_rrb(b, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}
