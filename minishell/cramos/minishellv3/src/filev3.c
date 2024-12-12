#include "../header/header.h"

static int  cheack_build_builtins(t_vars *vars)
{
	char	*space_trim;

	space_trim = ft_trim(vars->input);
	if (!space_trim)
		return (0);
	if (ft_strncmp(space_trim, "echo", 4) == 0 &&
		(space_trim[4] == '\0' || space_trim[4] == ' '))
		return (1);
	if (ft_strncmp(space_trim, "cd", 2) == 0 &&
		(space_trim[2] == '\0' || space_trim[2] == ' '))
		return (1);
	if (ft_strncmp(space_trim, "pwd", 3) == 0 &&
		(space_trim[3] == '\0' || space_trim[3] == ' '))
		return (1);
	if (ft_strncmp(space_trim, "export", 6) == 0 &&
		(space_trim[6] == '\0' || space_trim[6] == ' '))
		return (1);
	if (ft_strncmp(space_trim, "unset", 5) == 0 &&
		(space_trim[5] == '\0' || space_trim[5] == ' '))
		return (1);
	if (ft_strncmp(space_trim, "env", 3) == 0 &&
		(space_trim[3] == '\0' || space_trim[3] == ' '))
		return (1);
	if (ft_strncmp(space_trim, "exit", 4) == 0 &&
		(space_trim[4] == '\0' || space_trim[4] == ' '))
		return (1);
	free(space_trim);
	return (0);
}

void    build_builtins(t_vars *vars)
{
	vars->input = ft_trim(vars->input);
    vars->matrix = ft_split(vars->input);
    if (ft_strncmp(vars->input, "echo", 4) == 0)
        echo(vars);
    if (ft_strncmp(vars->input, "cd", 2) == 0)
        cd(vars);
    if (ft_strncmp(vars->input, "pwd", 3) == 0)
        pwd(vars);
    if (ft_strncmp(vars->input, "export", 6) == 0)
        ft_export(vars, vars->matrix);
    if (ft_strncmp(vars->input, "unset", 5) == 0)
        ft_unset(vars->env_ref, &vars->matrix[1]);
    if (ft_strncmp(vars->input, "env", 3) == 0)
        env(vars);
    if (ft_strncmp(vars->input, "exit", 4) == 0)
        ft_exit(vars);
}

void    all_commands(t_vars *vars)
{
	pid_t		pid;
	size_t		j;

	vars->cargs = count_args(vars->input);
	vars->args = create_args(vars->input);
	trigger_promp(1);
	vars->exit_status = 0;
	pid = fork();
	j = 0;
	if (pid < 0)
		perror("Error\n");
	else if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		execute_command(vars, vars->args[0]); 
		execute_path(vars);
		trigger_promp(2);
		printf("%s: command2 not found\n", vars->args[0]);
		exit(127);
	}
	else
	{
		waitpid(pid, &vars->exit_status, 0);
        if (WIFEXITED(vars->exit_status))
            vars->exit_status = WEXITSTATUS(vars->exit_status);
        else if (WIFSIGNALED(vars->exit_status))
            vars->exit_status = 128 + WTERMSIG(vars->exit_status);
        else
            vars->exit_status = 1;
	}
	trigger_promp(1);
	while (j++ < vars->cargs)
		free(vars->args[j]);
	free(vars->args);
}

void    only_comands(t_vars *vars)
{
	if (export_var(vars, vars->input))
		return ;
	if (cheack_build_builtins(vars))
		build_builtins(vars);
	else
		all_commands(vars);
}
