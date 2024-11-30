#include "../header/header.h"

char	**split_pipe(char *input)
{
	return (ft_split(input, "|"));
}

void	execute_pipe(char *input, char *path, char **env_ref)
{
	char	*executable;
	char	**args;
	char	**commands;
	char	*cmd;
	int		num_cmds;
	int		i;
	int		fd[2];
	int		input_fd;
	pid_t	pid;

	commands = split_pipe(input);
	num_cmds = 0;
	input_fd = 0;
	while (commands[num_cmds])
		num_cmds++;
	i = 0;
	while (i < num_cmds)
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			dup2(input_fd, STDIN_FILENO);
			if (commands[i + 1])
				dup2(fd[1], STDOUT_FILENO);
			close(fd[0]);
			args = ft_split(commands[i], " ");
			executable = find_executable(args[0], path);
			if (!executable)
			{
				printf("%s: command not found\n", args[0]);
				exit(EXIT_FAILURE);
			}
			execve(executable, args, env_ref);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		close(fd[1]);
		input_fd = fd[0];
		i++;
	}
	i = 0;
	while (i < num_cmds)
	{
		wait(NULL);
		i++;
	}
	free(commands);
}
