/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:21:56 by pzau              #+#    #+#             */
/*   Updated: 2024/11/07 12:28:46 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

int	main()
{
	char	*input;

	input = readline("Digite algo: ");

	if (input)
	{
		printf("Voce digitou: %s\n", input);

		rl_redisplay();

		free(input);
	}
	return (0);
}
