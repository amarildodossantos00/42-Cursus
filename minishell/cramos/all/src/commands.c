#include "../header/header.h"


static void	get_home(t_vars *vars)
{
	int	i;
	//int	l;
	char	*equal;
	
	i = 0;
	while(vars->variables[i] != NULL)
	{
		equal = ft_strchr(vars->variables[i], '=');
		if (equal != NULL && strncmp(vars->variables[i], "HOME",
			equal - vars->variables[i]) == 0 && (equal - vars->variables[i]) == 4)
		{
			//l = equal - vars->variables[i];
			//if (ft_strncmp(vars->variables[i], "HOME", l) == 0 && l == 4)
			//{
				//if ()
			//}
			vars->path = equal + 1;
			return ;
		}
		i++;
	}
	vars->path = NULL;
}
void cd(t_vars *vars)
{
	if (vars->input == NULL || strcmp(vars->input, "") == 0)
	{
		//char	*home;
		//vars->home = getenv("HOME");
		get_home(vars);
		if (vars->path == NULL)
			fprintf(stderr, "cd: variável HOME não definida\n");
		else if (chdir(vars->path) != 0)
			perror("cd");
	}
    	else 
    	{
    		if (chdir(vars->input) != 0)
    			perror("cd");
    	}
	/*else if (chdir("..") != 0)
		perror("Erro ao mudar de directorio\n");*/
}

void	pwd(t_vars *vars)
{
	vars->input = getcwd(NULL, 0);

	if (vars->input == NULL)
		perror("Caminho não encontrado\n");
	printf("%s\n", vars->input);
}
