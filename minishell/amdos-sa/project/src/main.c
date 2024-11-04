/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:35:34 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/11/04 12:09:24 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(void)
{
	static char	*command;
	pid_t		pid;

	signal(SIGINT, control_c);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		command = readline("minishell% ");
		if (!command)
			break ;
		if (ft_strlen(command) > 0)
			add_history(command);
		if (ft_strncmp(command, "exit", ft_strlen(command)) == 0)
		{
			rl_clear_history();
			free(command);
			exit (0);
		}
		pid = fork();
		if (pid < 0)
			perror("Error\n");
		else if (pid == 0)
		{
			execute_path(command);
			printf("%s: command not found\n", command);
		}
		else
			wait(NULL);
		free(command);
		command = NULL;
	}
	return (0);
}
