#include "../header/header.h"

int	count_variables(char **environ)
{
	int	count;

	count = 0;
	while (environ[count] != NULL)
		count++;
	return (count);
}

void	get_path(t_vars *vars)
{
	int	i;
	int	len;
	char	*equal_sign;

	i = 0;
	vars->path = "nothing";
	while (vars->variables[i] != NULL)
	{
		equal_sign = ft_strchr(vars->variables[i], '=');
		if (equal_sign != NULL)
		{
			len = equal_sign - vars->variables[i];
			if (ft_strncmp(vars->variables[i], "PATH", len) == 0 && len == 4)
			{
				if (vars->path != NULL && ft_strcmp(vars->path, "nothing") != 0)
					free(vars->path);
				vars->path = ft_strdup(equal_sign + 1);
				return ;
			}
		}
		i++;
	}
}

void	get_variables(t_vars *vars, char **environ)
{
	int	i;
	int	count;

	count = count_variables(environ);
	vars->variables = malloc((count + 1) * sizeof(char *));
	if (!vars->variables)
	{
		perror("Erro ao alocar memoria");
		exit(1);
	}
	i = 0;
	while (i < count)
	{
		vars->variables[i] = ft_strdup(environ[i]);
		if (!vars->variables[i])
		{
			perror("Erro ao alocar memoria para variavel");
			exit(1);
		}
		i++;
	}
	vars->variables[count] = NULL;
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

void	remove_variable(t_vars *vars, const char *var_name)
{
	int	i;
	int	j;
	int	found;
	int	len;
	char	*equal_sign;

	i = 0;
	found = 0;
	while (vars->variables[i] != NULL)
	{
		equal_sign = ft_strchr(vars->variables[i], '=');
		if (equal_sign != NULL)
		{
			len = equal_sign - vars->variables[i];
			if (ft_strncmp(vars->variables[i], var_name, len) == 0 && var_name[len] == '\0')
			{
				free(vars->variables[i]);
				j = i;
				while (vars->variables[j] != NULL)
				{
					vars->variables[j] = vars->variables[j + 1];
					j++;
				}
				found = 1;
				break ;
			}
		}
		i++;
	}
	if (!found)
		printf("Variavel %s nao encontrada\n", var_name);
}

void	add_variables(t_vars *vars, char *new_var)
{
	int	count;
	int	i;
	char	**new_array;

	count = count_variables(vars->variables);
	new_array = malloc((count + 2) * sizeof(char *));
	if (!new_array)
	{
		perror("Erro ao alocar memoria para nova variavel\n");
		return ;
	}
	i = 0;
	while (i < count)
	{
		new_array[i] = vars->variables[i];
		i++;
	}
	new_array[count] = ft_strdup(new_var);
	new_array[count + 1] = NULL;

	free(vars->variables);
	vars->variables = new_array;
}
