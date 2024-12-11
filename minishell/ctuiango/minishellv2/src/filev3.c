#include "../header/header.h"

static int  cheack_build_builtins(t_vars *vars)
{
	if (ft_strncmp(vars->input, "echo", 4) == 0 &&
		(vars->input[4] == '\0' || vars->input[4] == ' '))
		return (1);
	if (ft_strncmp(vars->input, "cd", 2) == 0 &&
		(vars->input[2] == '\0' || vars->input[2] == ' '))
		return (1);
	if (ft_strncmp(vars->input, "pwd", 3) == 0 &&
		(vars->input[3] == '\0' || vars->input[3] == ' '))
		return (1);
	if (ft_strncmp(vars->input, "export", 6) == 0 &&
		(vars->input[6] == '\0' || vars->input[6] == ' '))
		return (1);
	if (ft_strncmp(vars->input, "unset", 5) == 0 &&
		(vars->input[5] == '\0' || vars->input[5] == ' '))
		return (1);
	if (ft_strncmp(vars->input, "env", 3) == 0 &&
		(vars->input[3] == '\0' || vars->input[3] == ' '))
		return (1);
	if (ft_strncmp(vars->input, "exit", 4) == 0 &&
		(vars->input[4] == '\0' || vars->input[4] == ' '))
		return (1);
	return (0);
}

void    build_builtins(t_vars *vars)
{
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
	pid = fork();
	j = 0;
	if (pid < 0)
		perror("Error\n");
	else if (pid == 0)
	{
		trigger_promp(2);
		signal(SIGINT, SIG_DFL);
		execute_path(vars);
		printf("%s: command not found\n", vars->input);
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);
	while (j++ < vars->cargs)
		free(vars->args[j]);
	trigger_promp(1);
	free(vars->args);
}

void    only_comands(t_vars *vars)
{
    if (cheack_build_builtins(vars))
        build_builtins(vars);
    else
        all_commands(vars);
}