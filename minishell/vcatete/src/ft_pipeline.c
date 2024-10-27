/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipeline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcatete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 07:56:21 by vcatete           #+#    #+#             */
/*   Updated: 2024/10/19 07:56:22 by vcatete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	pipeline(int pipe_fd[], char **commands, int i, int fd_in)
{
	char	*argv[4];

	argv[0] = "/bin/sh";
	argv[1] = "-c";
	argv[2] = commands[i];
	argv[3] = NULL;
	dup2(fd_in, STDIN_FILENO);
	if (commands[i + 1] != NULL)
		dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execve("/bin/sh", argv, NULL);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	execute_pipeline(char **commands)
{
	int	pipe_fd[2];
	int	fd_in;
	int	i;

	i = 0;
	fd_in = 0;
	if (getenv("PATH"))
	{
		while (commands[i] != NULL)
		{
			pipe(pipe_fd);
			if (fork() == 0)
				pipeline(pipe_fd, commands, i, fd_in);
			else
			{
				wait(NULL);
				close(pipe_fd[1]);
				fd_in = pipe_fd[0];
				i++;
			}
		}
	}
	return ;
}

void	execute_command_with_pipes(char *input)
{
	char	**commands;

	commands = ft_split(input, '|');
	if (commands != NULL)
		execute_pipeline(commands);
}
