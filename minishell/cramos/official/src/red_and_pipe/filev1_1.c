#include "../../header/header.h"

int	cheack_red(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '>')
		{
			if (str[i + 1] == '>')
				return (1);
			return (2);
		}
		if (str[i] == '<')
		{
			if (str[i + 1] == '<')
				return (3);
			return (4);
		}
		i++;
	}
	return (0);
}

int	check_one_red(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (cheack_red(str[i]) != 3)
			return (0);
		i++;
	}
	return (1);
}

char	*concatenar_strs(char *str, char **commandv2)
{
	char	*new_str;
	int		j;

	j = 1;
	while (commandv2[j])
	{
		new_str = ft_strjoin(ft_strjoin(str, " "), commandv2[j]);
		free(str);
		str = new_str;
		j++;
	}
	return (str);
}

char	*processar_redirecionamento(char *input, char **redic)
{
	char	**command;
	char	**commandv2;
	char	*str;
	int		i;

	i = 0;
	command = ft_split_red(redic[0]);
	str = ft_strdup(command[0]);
	free_split(command);
	while (redic[i])
	{
		commandv2 = ft_split_red(redic[i]);
		if (count_words(commandv2[1]) > 1)
		{
			commandv2 = ft_split(commandv2[1]);
			str = concatenar_strs(str, commandv2);
			free_split(commandv2);
		}
		free_split(commandv2);
		i++;
	}
	return (str);
}

void	atualizar_input(t_vars *vars, char **redic)
{
	char	*str;

	str = processar_redirecionamento(vars->input, redic);
	free(vars->input);
	vars->input = str;
}
