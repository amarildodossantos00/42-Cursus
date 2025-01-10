#include "../header/header.h"

int	count_variables(char **environ)
{
	int	count;

	count = 0;
	while (environ[count] != NULL)
		count++;
	return (count);
}

int	count_args(char *input)
{
	char	*aux;
	char	input_copy[256];
	size_t	qnt;

	ft_memset(input_copy, 0, sizeof(input_copy));
	sncat(input_copy, input, ft_strlen(input));
	aux = ft_strtok(input_copy, " ");
	qnt = 0;
	while (aux)
	{
		qnt++;
		aux = ft_strtok(NULL, " ");
	}
	return (qnt);
}

char	**create_args(t_vars *vars, char *input, size_t k)
{
	vars->i = 0;
	vars->argss = malloc((count_args(input) + 1) * sizeof(char *));
	if (!vars->argss)
		return (NULL);
	vars->input_copy = malloc(ft_strlen(input) + 1);
	ft_strcpy(vars->input_copy, input);
	vars->aux = ft_strtok(vars->input_copy, " ");
	while (vars->aux)
	{
		vars->argss[vars->i] = malloc(ft_strlen(vars->aux) + 1);
		if (!vars->argss[vars->i])
		{
			while (k++ < vars->i)
				free(vars->argss[k]);
			free(vars->argss);
			return (NULL);
		}
		ft_strcpy(vars->argss[vars->i], vars->aux);
		vars->aux = ft_strtok(NULL, " ");
		vars->i++;
	}
	vars->argss[vars->i] = NULL;
	free(vars->input_copy);
	return (vars->argss);
}
