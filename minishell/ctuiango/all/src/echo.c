#include "../header/header.h"

void	echo(t_vars *vars)
{
	int	i;
	int	nl;
	
	i = 1;
	nl = 1;
	while (vars->matrix[i] && ft_strncmp(vars->matrix[i], "-n", 2) == 0)
	{
		nl = 0;
		i++;
	}
	while (vars->matrix[i] != NULL)
	{
		printf("%s", vars->matrix[i]);
		if (vars->matrix[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (nl)
		printf("\n");	
}
