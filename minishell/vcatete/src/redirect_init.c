/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcatete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 07:56:56 by vcatete           #+#    #+#             */
/*   Updated: 2024/10/19 07:56:57 by vcatete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	handle_fork_2(pid_t pid, char *filename, char *argv[4])
{
	int	status;

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		handle_input_redirection(filename);
		execve("/bin/bash", argv, NULL);
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
			perror("waitpid");
	}
}

void	handle_fork_3(pid_t pid, char *filename, char *argv[4])
{
	int	status;

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		handle_heredoc(filename);
		execve("/bin/bash", argv, NULL);
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
			perror("waitpid");
	}
}

void	redirect_function(int pid,
char *filename, char **argv, char *cmd)
{
	char	*redirect;

	redirect = ft_strstr(cmd, " << ");
	if (redirect)
	{
		*redirect = '\0';
		filename = redirect + 4;
		handle_fork_3(pid, filename, argv);
	}
}

void	init_args(char	**argv, char *cmd)
{
	argv[0] = "bash";
	argv[1] = "-c";
	argv[2] = cmd;
	argv[3] = NULL;
}

void	execute_command_with_redirection(char *cmd)
{
	char	*filename;
	char	*argv[4];
	pid_t	pid;

	pid = fork();
	init_args(argv, cmd);
	filename = ft_strstr(cmd, " >> ");
	if (filename)
		handle_fork(pid, filename + 4, argv, 1);
	else
	{
		filename = ft_strstr(cmd, " > ");
		if (filename)
			handle_fork(pid, filename + 3, argv, 0);
		else
		{
			filename = ft_strstr(cmd, " < ");
			if (filename)
				handle_fork_2(pid, filename + 3, argv);
			else
				redirect_function(pid, filename, argv, cmd);
		}
	}
}
