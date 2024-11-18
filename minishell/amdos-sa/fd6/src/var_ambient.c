#include "../header/header.h"

void	get_path(t_vars *vars)
{
	int	i;
	int	len;
	char	*equal_sign;

	i = 0;
	vars->path = "nothing";
	while (vars->env[i] != NULL)
	{
		equal_sign = ft_strchr(vars->env[i], '=');
		if (equal_sign != NULL)
		{
			len = equal_sign - vars->env[i];
			if (ft_strncmp(vars->env[i], "PATH", len) == 0 && len == 4)
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
