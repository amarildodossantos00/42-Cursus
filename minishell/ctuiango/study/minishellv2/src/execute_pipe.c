#include "../header/header.h"

char	**split_pipe(char *input)
{
	return (ft_split_del(input, "|"));
}

void	execute_pipe(t_vars *vars)
{
	char	*executable;
	char	**args;
	int		num_cmds;
	int		i;

	vars->commands = split_pipe(vars->input);
	num_cmds = 0;
	while (vars->commands[num_cmds])
		num_cmds++;
	i = 0;
	while (i < num_cmds)
	{
		pipe(vars->fd);
		vars->pid = fork();
		if (vars->pid == 0)
		{
			dup2(vars->input_fd, STDIN_FILENO);
			if (vars->commands[i + 1])
				dup2(vars->fd[1], STDOUT_FILENO);
			close(vars->fd[0]);
			args = ft_split_del(vars->commands[i], " ");
			executable = find_executable(args[0], vars->path);
			if (!executable)
			{
				printf("%s: command not found\n", args[0]);
				exit(127);
			}
			execve(executable, args, vars->env);
			perror("execve");
			exit(1);
		}
		else if (vars->pid < 0)
		{
			perror("fork");
			exit(1);
		}
		close(vars->fd[1]);
		vars->input_fd = vars->fd[0];
		i++;
	}
	i = 0;
	while (i < num_cmds)
	{
		wait(NULL);
		i++;
	}
	free(vars->commands);
}
