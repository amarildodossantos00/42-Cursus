/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 07:16:45 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/08/23 12:50:22 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pswap.h"

void	small_sort(t_stack ***s_a)
{
	if (lst_min(**s_a) == (**s_a)->value)
	{
		rra(*s_a, 0);
		sa(*s_a, 0);
	}
	else if (lst_max(**s_a) == (**s_a)->value)
	{
		ra(*s_a, 0);
		if (!check_order(**s_a))
			sa(*s_a, 0);
	}
	else
	{
		if (find_index(**s_a, lst_max(**s_a)) == 1)
			rra(*s_a, 0);
		else
			sa(*s_a, 0);
	}
}

void	_chose_algorithm(t_stack **s_a, int size)
{
	if (size == 1)
	{
		free_stack(*s_a);
		return ;
	}
	else if (size <= 3)
		small_sort(&s_a);
	else if (size > 3)
		big_sort(&s_a);
}

void	ft_start(char **matrix)
{
	int		len;
	int		size;
	t_stack	*s_a;

	_creat_stack(&s_a);
	len = ft_strlen(matrix);
	len--;
	size = len;
	while (len >= 0)
	{
		_push(&s_a, ft_atoi(matrix[len]));
		len--;
	}
	size++;
	if (check_order(s_a))
	{
		free_stack(s_a);
		return ;
	}
	_chose_algorithm(&s_a, size);
	print_stack(s_a);
	free_stack(s_a);
}
