#include "../header/header.h"

void	get_variables(t_vars *vars, char **environ)
{
	vars->variables = environ;
	return ;
}

void	print_variables(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->variables[i] != NULL)
	{
		printf("%s\n", vars->variables[i]);
		i++;
	}
	return ;
}
