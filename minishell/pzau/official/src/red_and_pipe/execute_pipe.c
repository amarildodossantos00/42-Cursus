#include "../../header/header.h"

char	**split_pipe(char *input)
{
	return (ft_split_del(input, "|"));
}

static void	setup_pipe(t_vars *vars)
{
	if (pipe(vars->fd) == -1)
	{
		perror("pipe");
		exit(1);
	}
}

static void	file_pipes(t_vars *vars, int num_cmds)
{
	wait_for_children(num_cmds);
	free_split(vars->commands);
}

static void	vars_pipes(t_vars *vars)
{
	vars->commands = split_pipe(vars->input);
	vars->input_fd = STDIN_FILENO;
}

void	execute_pipe(t_vars *vars)
{
	int	num_cmds;
	int	i;

	vars_pipes(vars);
	num_cmds = count_commands(vars->commands);
	i = 0;
	while (i < num_cmds)
	{
		if (!handle_redirection(vars, i))
		{
			setup_pipe(vars);
			vars->pid = fork();
			if (vars->pid == 0)
				execute_child(vars, i);
			else if (vars->pid < 0)
			{
				perror("fork");
				exit(1);
			}
			close(vars->fd[1]);
			vars->input_fd = vars->fd[0];
		}
		i++;
	}
	file_pipes(vars, num_cmds);
}
