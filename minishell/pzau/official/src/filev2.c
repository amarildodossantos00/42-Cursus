#include "../header/header.h"

static int	cheak_string(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->input[i])
	{
		if (vars->input[i] == '|')
			return (1);
		i++;
	}
	i = 0;
	while (vars->input[i])
	{
		if (vars->input[i] == '>' || vars->input[i] == '<')
		{
			if ((vars->input[i + 1] && vars->input[i]) == vars->input[i + 1])
				return (2);
			return (3);
		}
		i++;
	}
	return (0);
}

void	read_readline(t_vars *vars)
{
	int	val;

	val = cheak_string(vars);
	expand_var(vars);
	if (cheack_build_builtins(vars))
		build_builtins(vars);
	else if (val == 1)
		execute_pipe(vars);
	else if (val == 2 || val == 3)
		redirecionamento(vars, 0);
	else
		only_comands(vars);
	return ;
}
