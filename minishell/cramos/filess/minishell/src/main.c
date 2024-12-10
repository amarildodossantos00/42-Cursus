/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:59:59 by ctuiango          #+#    #+#             */
/*   Updated: 2024/10/30 16:39:31 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int	main(void)
{
	char	*rl;
	char	*pwd;
	pid_t	pid;

	while (1)
	{
		rl = readline("minishell% ");
		if (rl == NULL)
		{
			free(rl);
			exit(0);
		}
		if (strlen(rl) > 0)
			add_history(rl);
		if (strcmp(rl, "exit") == 0 || strcmp(rl, "q") == 0)
		{
			free(rl);
			exit(0);
		}
		//pwd = getcwd(NULL, 0);
		pid = fork();
		if (pid < 0)
			perror("Error");
		else if (pid == 0)
		{
			char	*args[3];
			if (strcmp(rl, "ls") == 0)
			{
				args[0] = "ls";
				args[1] = NULL;
			}
			else if (strcmp(rl, "pwd") == 0)
			{
				args[0] = "pwd";
				args[1] = NULL;
			}
			execvp(args[0], args); // Executa o comando
            		printf("zsh command not found: %s\n", rl); // Se execvp falhar
           		exit(1);
		}
		else
		{
			int status;
            		waitpid(pid, &status, 0);
		}
		/*else
			printf("zsh command not found: %s\n", rl);*/
		free(rl);
	}
	rl_clear_history();
}
