/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:13:42 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/08/21 12:30:35 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pswap.h"

int	interpreter_arg(char **matrix)
{
	ft_start(matrix);
	return (0);
}

int	main(int ac, char *av[])
{
	char	*matrix;

	if (ac == 2)
	{
		ft_printf("Wait!\n");
	}
	else if (ac > 2)
		interpreter_arg(av + 1);
	return (0);
}
