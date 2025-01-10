#include "../header/header.h"

void	handle_empty_input(t_vars *vars)
{
	free(vars->copy_input);
	free(vars->input);
}

int	process_input(t_vars *vars)
{
	vars->path = get_path(vars);
	vars->copy_input = readline("minishell% ");
	if (!vars->copy_input)
		return (1);
	vars->input = ft_trim(vars->copy_input);
	if (vars->input[0] == '\0')
	{
		handle_empty_input(vars);
		return (0);
	}
	if (ft_strlen(vars->input) > 0)
		add_history(vars->copy_input);
	expand_exit_status(vars);
	read_readline(vars);
	trigger_promp(2);
	return (0);
}
