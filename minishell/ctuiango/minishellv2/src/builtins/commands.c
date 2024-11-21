#include "../../header/header.h"

static void	get_home(t_vars *vars)
{
	int	i;
	char	*equal;
	
	i = 0;
	while(vars->env[i] != NULL)
	{
		equal = ft_strchr(vars->env[i], '=');
		if (equal != NULL && strncmp(vars->env[i], "HOME",
			equal - vars->env[i]) == 0 && (equal - vars->env[i]) == 4)
		{
			vars->home = equal + 1;
			return ;
		}
		i++;
	}
	vars->home = NULL;
}

void	cd(t_vars *vars)
{
	if (vars->matrix[1] == NULL)	
		get_home(vars);
	else if (ft_strncmp(vars->matrix[1], "..", 2) == 0)
		vars->home = vars->matrix[1];
	else
		vars->home = vars->matrix[1];
    	if (vars->home != NULL && chdir(vars->home) != 0)
    		perror("cd");
}

void	pwd(t_vars *vars)
{
	vars->input = getcwd(NULL, 0);

	if (vars->input == NULL)
		perror("Caminho não encontrado\n");
	printf("%s\n", vars->input);
}

void	env(t_vars *vars)
{
	int		i;

	i = 0;
	while (vars->env[i] != NULL)
	{
		printf("%s\n", vars->env[i]);
		i++;
	}
	return ;
}

void	ft_exit(t_vars *vars)
{
	printf("exit\n");
	exit(0);
}
