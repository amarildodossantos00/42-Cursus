/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 04:30:03 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/16 04:30:40 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_split(char **matriz)
{
	int	i;

	i = 0;
	if (matriz)
	{
		while (matriz[i])
		{
			free(matriz[i]);
			i++;
		}
		free(matriz);
	}
}
