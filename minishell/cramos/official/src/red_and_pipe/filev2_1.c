#include "../../header/header.h"

void	redirect_output(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("open");
		return ;
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	append_output(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		perror("open");
		return ;
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

int	redirect_input(char *file)
{
	int	fd;

	if (access(file, F_OK) != 0)
		return (1);
	if (access(file, R_OK) != 0)
		return (1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("open");
		return (2);
	}
	return (0);
}

void	add_operator_space(char *input, char *output, int *i, int *j)
{
	if (*j > 0 && output[*j - 1] != ' ')
		output[(*j)++] = ' ';
	output[(*j)++] = input[*i];
	if (input[*i + 1] == input[*i])
		output[(*j)++] = input[(*i)++];
	if (input[*i + 1] != ' ')
		output[(*j)++] = ' ';
}

char	*add_spaces_around_operators(char *input)
{
	char	*output;
	int		j;
	int		i;

	output = malloc(ft_strlen(input) * 3 + 1);
	if (!output)
		return (NULL);
	j = 0;
	i = 0;
	while (input[i])
	{
		if (ft_strchr("><", input[i]))
			add_operator_space(input, output, &i, &j);
		else
			output[j++] = input[i];
		i++;
	}
	output[j] = '\0';
	return (output);
}
