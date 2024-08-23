/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 07:16:45 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/08/23 03:12:28 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pswap.h"

void	small_stack(t_stack ***s_a)
{
	if (!s_a || !**s_a)
		return ;
	if ((**s_a)->value > (**s_a)->next->value)
		sa(*s_a, 0);
}

void	_chose_algorithm(t_stack **s_a, /*t_stack **s_b,*/ int size)
{
	if (size == 1)
	{
		free_stack(*s_a);
		return ;
	}
	else if (size == 2)
		small_stack(&s_a);
/*	else if (size == 3)
		three_sort(&s_a);
	else if (size == 4)
		four_sort(&s_a, &s_b);
	else if (size == 5)
		five_sort(&s_a, &s_b);
	else if (size > 5)
		big_sort(&s_a, &s_b);*/
}

void	ft_start(char **matrix)
{
	int		len;
	int		size;
	t_stack	*s_a;
	t_stack	*s_b;

	_creat_stack(&s_a);
	_creat_stack(&s_b);
	len = ft_strlen(matrix);
	len--;
	size = len;
	while (len >= 0)
	{
		_push(&s_a, ft_atoi(matrix[len]));
		len--;
	}
	size++;
	if (check_order(s_a) == 0)
	{
		free_stack(s_a);
		return ;
	}
	_chose_algorithm(&s_a, /*&s_b,*/ size);
	print_stack(s_a);
	free_stack(s_a);
	//free_stack(s_b);
}