/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:35:34 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/10/28 18:59:28 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(void)
{
	static char	*buff;

	while (1)
	{
		buff = readline("minishell% ");
		if (ft_strlen(buff) > 0)
			add_history(buff);
		if (!strcmp(buff, "exit") || !strcmp(buff, "quit") || !strcmp(buff, "q"))
			break ;
		else
			printf("zsh command not found: %s\n", buff);
		free(buff);
	}
	return (0);
}
