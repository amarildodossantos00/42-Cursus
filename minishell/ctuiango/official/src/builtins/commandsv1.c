#include "../../header/header.h"

static void	freev1(t_vars *vars, int aux)
{
	free_env(vars->env_ref);
	free_convert_env_list(vars->env);
	free_split(vars->matrix);
	exit(aux);
}

void	ft_exit(t_vars *vars)
{
	int	aux;
	int	i;

	i = 0;
	aux = 0;
	printf("exit\n");
	if (vars->matrix[1] != NULL)
	{
		while (vars->matrix[1][i] != '\0')
		{
			if (!ft_isdigit(vars->matrix[1][i])
				&& vars->matrix[1][i] != '-')
			{
				if (!ft_isdigit(vars->matrix[1][i])
					&& vars->matrix[1][i] != '-')
					printf("minishell: exit: %s: numeric argument required\n",
						vars->matrix[1]);
				exit(2);
			}
			i++;
		}
		aux = (ft_atoi(vars->matrix[1]));
	}
	freev1(vars, aux);
}
