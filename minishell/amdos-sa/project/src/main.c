/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:35:34 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/10/31 14:04:16 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(void)
{
	static char	*command;

	while (1)
	{
		command = readline("minishell% ");
		if (!command)
			break ;
		if (ft_strlen(command) > 0)
			add_history(command);
		if (!ft_strncmp(command, "exit", ft_strlen(command)))
		{
			rl_clear_history();
			free(command);
			exit(0);
		}
		execute_path(command);
		printf("Executable not found: %s\n", command);
		free(command);
		command = NULL;
	}
	return (0);
}
