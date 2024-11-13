#include "../header/header.h"

static void	free_variables(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->variables[i] != NULL)
	{
		free(vars->variables[i]);
		i++;
	}
	free(vars->variables);
}

void	liberar(t_vars *vars)
{
	size_t	j;

	j = 0;
	free_variables(vars);
	if (ft_strncmp(vars->path, "nothing", ft_strlen(vars->path)) != 0)
		free(vars->path);
}
