#include "../header/header.h"

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
	if (!pos)
		return ;
	vars->exit_status %= 256;
	if (vars->exit_status < 0 || vars->exit_status > 255)
		vars->exit_status %= 256;
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
	ft_strcat(new_input, exit);
	ft_strcat(new_input, pos + 2);
	free(exit);
	free(vars->input);
	vars->input = new_input;
}
