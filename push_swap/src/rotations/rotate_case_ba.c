/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_case_ba.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 12:48:01 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/03 10:38:52 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pswap.h"

int	case_rarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = find_place_a(a, c);
	if (i < find_index(b, c))
		i = find_index(b, c);
	return (i);
}

int	case_rrarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_place_a(a, c))
		i = lst_size(a) - find_place_a(a, c);
	if ((i < (lst_size(b) - find_index(b, c))) && find_index(b, c))
		i = lst_size(b) - find_index(b, c);
	return (i);
}

int	case_rarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_index(b, c))
		i = lst_size(b) - find_index(b, c);
	i = find_place_a(a, c) + i;
	return (i);
}

int	case_rrarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_place_a(a, c))
		i = lst_size(a) - find_place_a(a, c);
	i = find_index(b, c) + i;
	return (i);
}
