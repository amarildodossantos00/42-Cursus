/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 06:34:16 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/08/22 08:12:10 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pswap.h"

void	ss(t_stack **s_a, t_stack **s_b)
{
	sa(s_a, 1);
	sb(s_b, 1);
	ft_printf("ss\n");
}

void	rr(t_stack **s_a, t_stack **s_b)
{
	ra(s_a, 1);
	rb(s_b, 1);
	ft_printf("rr\n");
}

void	rrr(t_stack **s_a, t_stack **s_b)
{
	rra(s_a, 1);
	rrb(s_b, 1);
	ft_printf("rrr\n");
}
