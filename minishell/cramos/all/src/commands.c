#include "../header/header.h"


static void	get_home(t_vars *vars)
{
	int	i;
	char	*equal;
	
	i = 0;
	while(vars->variables[i] != NULL)
	{
		equal = ft_strchr(vars->variables[i], '=');
		if (equal != NULL && strncmp(vars->variables[i], "HOME",
			equal - vars->variables[i]) == 0 && (equal - vars->variables[i]) == 4)
		{
			vars->path = equal + 1;
			return ;
		}
		i++;
	}
	vars->path = NULL;
}
void	cd(t_vars *vars)
{
	if (vars->matrix[1] == NULL)	
		get_home(vars);
	else if (ft_strncmp(vars->matrix[1], "..", 2) == 0)
		vars->path = vars->matrix[1];
    	chdir(vars->path);
}

void	pwd(t_vars *vars)
{
	vars->input = getcwd(NULL, 0);

	if (vars->input == NULL)
		perror("Caminho não encontrado\n");
	printf("%s\n", vars->input);
}

void	ft_exit(t_vars *vars)
{
	if (ft_strncmp(vars->input, "exit", 4) == 0)
	{
		printf("exit\n");
		exit(0);
	}
	
}
