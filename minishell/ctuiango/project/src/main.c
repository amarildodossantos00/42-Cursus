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


void control_c(int sig)
{
	(void)sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

int	main(void)
{
	static char	*command;
	pid_t	pid;
	signal(SIGINT, control_c);
	while (1)
	{
		command = readline("minishell% ");
		if (!command)
			break ;
		if (ft_strlen(command) > 0)
			add_history(command);
		if (strcmp(command, "exit") == 0) // ft_strlen(command)) == 0)
		{
			rl_clear_history();
			free(command);
			exit(0);
		}
		pid = fork();
		if (pid < 0)
		perror("Error");
		else if (pid == 0)
		{
			execute_path(command);
			printf("Executable not found: %s\n", command);
		}
		else
		{
			int	status;
			waitpid(pid, &status, 0);
		}
		free(command);
		command = NULL;
	}
	return (0);
}
