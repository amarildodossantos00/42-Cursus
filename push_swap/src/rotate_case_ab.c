/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_case_ab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 06:33:08 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/08/31 09:08:14 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pswap.h"

int	case_rarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = find_place_b(b, c);
	if (i < find_index(a, c))
		i = find_index(a, c);
	return (i);
}

int	case_rrarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_place_b(b, c))
		i = lst_size(b) - find_place_b(b, c);
	if ((i < (lst_size(a) - find_index(a, c))) && find_index(a, c))
		i = lst_size(a) - find_index(a, c);
	return (i);
}

int	case_rrarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_index(a, c))
		i = lst_size(a) - find_index(a, c);
	i = find_place_b(b, c) + i;
	return (i);
}

int	case_rarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_place_b(b, c))
		i = lst_size(b) - find_place_b(b, c);
	i = find_index(a, c) + i;
	return (i);
}
