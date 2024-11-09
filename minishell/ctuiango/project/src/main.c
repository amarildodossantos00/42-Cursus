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
#include <sys/wait.h>

int	main(void)
{
	static char	*command;
	pid_t	pid;
	signal(SIGINT, control_c);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		command = readline("minishell% ");
		if (!command)
		{
			printf("exit\n");
			break ;
		}
		if (ft_strlen(command) > 0)
			add_history(command);
		if (ft_strncmp(command, "exit", ft_strlen(command)) == 0)
		{
			rl_clear_history();
			free(command);
			exit(0);
		}
		pid = fork();
		if (pid < 0)
			perror("Error\n");
		else if (pid == 0)
		{
			signal(SIGINT, SIG_DFL);
			execute_path(command);
			printf("Command not found: %s\n", command);
		}
		else
		{
			//int	status;
			waitpid(pid, NULL, 0);
		}
		free(command);
		command = NULL;
	}
	return (0);
}
