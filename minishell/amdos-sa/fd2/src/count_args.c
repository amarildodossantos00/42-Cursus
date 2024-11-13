#include "../header/header.h"

int	count_args(char *input)
{
	char *aux;
	char input_copy[256];
	size_t qnt;

	sncat(input_copy, input, ft_strlen(input));
	aux = ft_strtok(input_copy, " ");
	qnt = 0;
	while (aux)
	{
		qnt++;
		aux = ft_strtok(NULL, " ");
	}
	return qnt;
}

char	**create_args(char *input)
{
	size_t i;
	size_t j;
	size_t k;
	char *aux;
	char input_copy[256];

	i = 0;
	k = 0;
	j = count_args(input);
	char **args = malloc((j + 1) * sizeof(char *));
	if (!args)
		return NULL;
	ft_strcpy(input_copy, input);
	aux = ft_strtok(input_copy, " ");
	while (aux)
	{
		args[i] = malloc(ft_strlen(aux) + 1);
		if (!args[i])
		{
			while (k++ < i)
				free(args[k]);
			free(args);
			return NULL;
		}
		ft_strcpy(args[i], aux);
		aux = ft_strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;
	return (args);
}
