/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:13:42 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/02 03:36:59 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pswap.h"

int	main(int ac, char *av[])
{
	t_stack	*s_a;

	s_a = interpreter_args(ac, av);
	if (!s_a || !check_double_number(s_a))
	{
		free_stack(&s_a);
		ft_error();
	}
	if (!check_order(s_a))
		algorithm(&s_a);
	free_stack(&s_a);
	return (0);
}
