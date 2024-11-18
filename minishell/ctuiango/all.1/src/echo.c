#include "../header/header.h"

/*static void	ignore(char *str)
{
	int	i;
	int	nl;
	char	*token;
	
	i = 0;
	nl = 1;
	token = strtok(str, " ");
	/*while (token && strncmp(token, "-n", 2) == 0)
	{
		nl = 0;
		//token = strtok(NULL, " ");
	}*/ 
//}*/

void	echo(t_vars *vars)
{
	int	i;
	int	nl;

	i = 1;
	nl = 1;
	while (vars->matrix[i] && ft_strncmp(vars->matrix[i], "-n", ft_strlen(vars->matrix[i])) == 0)
	{
		nl = 0;
		//ignore(vars->input);
		i++;
	}
	while (vars->matrix[i] != NULL)
	{
		printf("%s", vars->matrix[i]);
		if (vars->matrix[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (nl)
		printf("\n");
}
