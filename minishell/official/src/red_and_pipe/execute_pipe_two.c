#include "../../header/header.h"

int	count_commands(char **commands)
{
	int	num_cmds;

	num_cmds = 0;
	while (commands[num_cmds])
		num_cmds++;
	return (num_cmds);
}

int	handle_redirection(t_vars *vars, int index)
{
	if (cheack_red(vars->commands[index]) > 0)
	{
		free(vars->input);
		vars->input = vars->commands[index];
		redirecionamento(vars, 1);
		return (1);
	}
	return (0);
}

void	execute_child(t_vars *vars, int index)
{
	char	*executable;
	char	**args;

	dup2(vars->input_fd, STDIN_FILENO);
	if (vars->commands[index + 1])
		dup2(vars->fd[1], STDOUT_FILENO);
	close(vars->fd[0]);
	close(vars->fd[1]);
	args = ft_split_del(vars->commands[index], " ");
	executable = find_executable(args[0], vars->path, vars);
	if (!executable)
	{
		printf("%s: command not found\n", args[0]);
		exit(127);
	}
	execve(executable, args, vars->env);
	perror("execve");
	exit(1);
}

void	wait_for_children(int num_cmds)
{
	int	i;

	i = 0;
	while (i < num_cmds)
	{
		wait(NULL);
		i++;
	}
}
