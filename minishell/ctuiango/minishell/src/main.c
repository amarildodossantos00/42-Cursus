/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:59:59 by ctuiango          #+#    #+#             */
/*   Updated: 2024/10/30 15:12:43 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	main(void)
{
	char	*rl;

	while (1)
	{
		rl = readline("minishell% ");
		if (rl == NULL)
		{
			exit(0);
			free(rl);
		}
		else
			printf("zsh command not found: %s\n", rl);
		add_history(rl);
		free(rl);
	}
	rl_clear_history();
}
