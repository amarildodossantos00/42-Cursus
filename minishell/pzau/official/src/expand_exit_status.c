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
		// Verifica se há "$?" sem exigir espaço após
		if (vars->input[i] == '$' && vars->input[i + 1] == '?')
		{
			count++;
			i += 2; // Pula os caracteres '$' e '?'
		}
		else
			i++;
	}
	return (count > 0 ? count : 1);
}

void	execute_command(t_vars *vars, char *command)
{
	vars->exit_status = 0;
	//printf("\n\n\n%s\n\n\n", command);
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

	pos = ft_strstr(vars->input, "$?");
	//add_and_update(&vars->env_ref, "?", "0", 0);
	if (!pos)
		return ;
	vars->exit_status %= 256;
	if (vars->exit_status < 0 || vars->exit_status > 255)
		vars->exit_status %= 256;
	exit = ft_itoa(vars->exit_status);
	if (!exit)
		return ;
	//add_and_update(&vars->env_ref, "?", exit, 0);
	new_input = malloc(ft_strlen(vars->input) - 2 + ft_strlen(exit) + 1);
	if (!new_input)
	{
		free(exit);
		return ;
	}
	ft_strncpy(new_input, vars->input, pos - vars->input);
	new_input[pos - vars->input] = '\0';
	new_input = ft_strcat(new_input, exit);
	new_input = ft_strcat(new_input, pos + 2);
	//if (check_on(vars))
	//	new_input = ft_itoa(ft_atoi(exit) * count_dollar(vars));
	free(exit);
	free(vars->input);
	vars->input = new_input;
}
