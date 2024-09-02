/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 08:29:02 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/02 06:34:04 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pswap.h"

void	free_str(char **matrix)
{
	char	*n1;

	if (!matrix)
		return ;
	while (*matrix)
	{
		n1 = *matrix;
		matrix++;
		free(n1);
	}
	matrix = NULL;
}
