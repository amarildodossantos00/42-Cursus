#include "../header/header.h"

int	cheack_build_builtins(t_vars *vars)
{
	if (ft_strncmp(vars->input, "echo", 4) == 0
		&& (vars->input[4] == '\0' || vars->input[4] == ' '))
		return (1);
	if (ft_strncmp(vars->input, "cd", 2) == 0
		&& (vars->input[2] == '\0' || vars->input[2] == ' '))
		return (1);
	if (ft_strncmp(vars->input, "pwd", 3) == 0
		&& (vars->input[3] == '\0' || vars->input[3] == ' '))
		return (1);
	if (ft_strncmp(vars->input, "export", 6) == 0
		&& (vars->input[6] == '\0' || vars->input[6] == ' '))
		return (1);
	if (ft_strncmp(vars->input, "unset", 5) == 0
		&& (vars->input[5] == '\0' || vars->input[5] == ' '))
		return (1);
	if (ft_strncmp(vars->input, "env", 3) == 0
		&& (vars->input[3] == '\0' || vars->input[3] == ' '))
		return (1);
	if (ft_strncmp(vars->input, "exit", 4) == 0
		&& (vars->input[4] == '\0' || vars->input[4] == ' '))
		return (1);
	return (0);
}

void	build_builtins(t_vars *vars)
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
	free_split(vars->matrix);
}

char	*get_path(t_vars *vars)
{
	t_env	*current;

	if (!vars->env_ref)
		init_env(vars);
	current = vars->env_ref;
	while (current)
	{
		if (ft_strcmp(current->var, "PATH") == 0)
			return (current->value);
		current = current->next;
	}
	return ("nothing");
}
