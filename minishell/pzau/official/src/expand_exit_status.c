#include "../header/header.h"

int	check_on(t_vars *vars)
{
	if (ft_strncmp(vars->input, "expr", 4) == 0)
		return (1);
	return (0);
}

int	count_dollar(t_vars *vars)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (vars->input[i])
	{
		if (vars->input[i] == '$' && vars->input[i + 1] == '?')
		{
			count++;
			i += 2;
		}
		else
			i++;
	}
	if (count > 0)
		return (count);
	else
		return (1);
}

void	execute_command(t_vars *vars, char *command)
{
	vars->exit_status = 0;
	if (!command || !vars->args || !vars->args[0])
	{
		vars->exit_status = 127;
		return ;
	}
	if (access(command, X_OK) == -1)
	{
		vars->exit_status = 127;
		return ;
	}
	return ;
}
