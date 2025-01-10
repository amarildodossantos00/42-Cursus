#include "../header/header.h"

void	free_command_args(t_vars *vars)
{
	size_t	j;

	j = 0;
	while (j < vars->cargs)
	{
		free(vars->args[j]);
		j++;
	}
	free(vars->args);
}

void	handle_child_processs(t_vars *vars)
{
	signal(SIGINT, SIG_DFL);
	execute_command(vars, vars->args[0]);
	execute_path(vars);
	trigger_promp(2);
	printf("%s: command2 not found\n", vars->args[0]);
	exit(127);
}

void	handle_parent_process(t_vars *vars, pid_t pid)
{
	waitpid(pid, &vars->exit_status, 0);
	if (WIFEXITED(vars->exit_status))
		vars->exit_status = WEXITSTATUS(vars->exit_status);
	else if (WIFSIGNALED(vars->exit_status))
		vars->exit_status = 128 + WTERMSIG(vars->exit_status);
	else
		vars->exit_status = 1;
}

void	all_commands(t_vars *vars)
{
	pid_t	pid;

	vars->cargs = count_args(vars->input);
	vars->args = create_args(vars, vars->input, 0);
	trigger_promp(1);
	vars->exit_status = 0;
	pid = fork();
	if (pid < 0)
		perror("Error\n");
	else if (pid == 0)
		handle_child_processs(vars);
	else
		handle_parent_process(vars, pid);
	trigger_promp(1);
	free_command_args(vars);
}

void	only_comands(t_vars *vars)
{
	if (cheack_build_builtins(vars))
		build_builtins(vars);
	else
		all_commands(vars);
}
