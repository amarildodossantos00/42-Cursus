/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcatete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 07:55:57 by vcatete           #+#    #+#             */
/*   Updated: 2024/10/19 07:55:59 by vcatete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	executar_comando(char *command, char *const argv[])
{
	char		*path_env;
	char		*path_copy;
	char		*dir;
	char		full_path[1024];
	extern char	**environ;

	path_env = getenv("PATH");
	path_copy = ft_strdup(path_env);
	dir = ft_strtok(path_copy, ":");
	while (dir != NULL)
	{
		ft_strcpy(full_path, dir);
		ft_strcat(full_path, "/");
		ft_strcat(full_path, command);
		if (is_executable(full_path))
			execve(full_path, argv, environ);
		dir = ft_strtok(NULL, ":");
	}
	printf("Comando não encontrado: %s\n", command);
	free(path_copy);
}

char	**parse_input(char *input)
{
	char	**args;
	char	*token;
	int		argc;

	args = malloc(sizeof(char *) * 12);
	if (!args)
		return (NULL);
	argc = 0;
	token = ft_strtok(input, " ");
	while (token != NULL && argc < 11)
	{
		args[argc++] = token;
		token = ft_strtok(NULL, " ");
	}
	args[argc] = NULL;
	return (args);
}

void	command_absolute(char **args)
{
	extern char	**environ;

	if (is_executable(args[0]))
		execve(args[0], args, environ);
	else
		printf("Commando não encontrado\n");
}

void	much_command(char *entrada)
{
	char	**args;
	pid_t	pid;

	args = parse_input(entrada);
	if (args && args[0])
	{
		pid = fork();
		if (pid == 0)
		{
			if (ft_strchr(args[0], '/'))
				command_absolute(args);
			else
			{
				executar_comando(args[0], args);
				exit(0);
			}
		}
		else
			waitpid(pid, NULL, 0);
	}
	free(args);
}

void	execute_command(char *entrada, t_Command commands[])
{
	int	i;

	i = 0;
	while (commands[i].command)
	{
		if (commands[i].require_argument)
		{
			if (ft_strncmp(entrada, commands[i].command,
					ft_strlen(commands[i].command)) == 0)
			{
				commands[i].handler(entrada);
				return ;
			}
		}
		else
		{
			if (ft_strcmp(entrada, commands[i].command) == 0)
			{
				commands[i].handler(entrada);
				return ;
			}
		}
		i++;
	}
	much_command(entrada);
}
