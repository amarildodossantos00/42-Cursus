#include "../header/header.h"

static int		check_on(t_vars *vars)
{
	if (ft_strncmp(vars->input, "expr", 4) == 0)
		return (1);
	return (0);
}

static int	count_dollar(t_vars *vars)
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
	return (count > 0 ? count : 1);
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

void	expand_exit_status(t_vars *vars)
{
	char	*new_input;
	char	*pos;
	char	*exit;
	char	*temp;

	pos = ft_strstr(vars->input, "$?");
	if (!pos)
		return ;
	vars->exit_status %= 256;
	if (vars->exit_status < 0)
		vars->exit_status += 256;

	exit = ft_itoa(vars->exit_status);
	if (!exit)
		return ;

	new_input = malloc(ft_strlen(vars->input) - 2 + ft_strlen(exit) + 1);
	if (!new_input)
	{
		free(exit);
		return ;
	}

	ft_strncpy(new_input, vars->input, pos - vars->input);
	new_input[pos - vars->input] = '\0';

	temp = ft_strcat(new_input, exit);
	free(new_input);
	new_input = temp;

	temp = ft_strcat(new_input, pos + 2);
	free(new_input);
	new_input = temp;

	if (check_on(vars))
	{
		free(new_input);
		new_input = ft_itoa(ft_atoi(exit) * count_dollar(vars));
	}

	free(exit);
	free(vars->input);
	vars->input = new_input;
}

