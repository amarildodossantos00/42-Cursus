#include "../../header/header.h"

void	remove_deli(char *s)
{
	int	i;
	int	j;
	char	deli;
	
	i = 0;
	j = 0;
	deli = '\0';
	while (s[i])
	{
		if ((s[i] == '\'' || s[i] == '"') && s[i] != '\0')
			deli = s[i];
		else if (s[i] == deli)
			deli = '\0';
		else
			s[j++] = s[i];
		i++;
	}
	s[j] = '\0';
}

static int	ignore(char **s)
{
	int	i;
	
	i = 1;
	while (s[i])
	{
		if (s[i][0] == '-' && s[i][1] == 'n')
		{
			int	j;
			
			j = 2;
			while (s[i][j] == 'n')
				j++;
			if (s[i][j] == '\0')
				i++;
			else
				break ;
		}
		else
			break ;
	}
	return (i);
}

void	echo(t_vars *vars)
{
	int	i;
	int	nl;

	i = ignore(vars->matrix);
	nl = 1;
	if (i > 1)
		nl = 0;
	while (vars->matrix[i] != NULL)
	{
		remove_deli(vars->matrix[i]);
		printf("%s", vars->matrix[i]);
		if (vars->matrix[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (nl)
		printf("\n");
	//vars->exit_status = 0;
}
