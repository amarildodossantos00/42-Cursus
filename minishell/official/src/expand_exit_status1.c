#include "../header/header.h"

static void	expand_aux(t_vars *vars)
{
	vars->exit_status %= 256;
	if (vars->exit_status < 0)
		vars->exit_status += 256;
	vars->exit = ft_itoa(vars->exit_status);
}

static void	expand_aux_one(t_vars *vars)
{
	free(vars->new_input);
	vars->new_input = vars->temp;
	vars->temp = ft_strcat(vars->new_input, vars->pos + 2);
	free(vars->new_input);
	vars->new_input = vars->temp;
}

void	expand_exit_status(t_vars *vars)
{
	vars->pos = ft_strstr(vars->input, "$?");
	if (!vars->pos)
		return ;
	expand_aux(vars);
	if (!vars->exit)
		return ;
	vars->new_input = malloc(len(vars->input) - 2 + len(vars->exit) + 1);
	if (!vars->new_input)
	{
		free(vars->exit);
		return ;
	}
	ft_strncpy(vars->new_input, vars->input, vars->pos - vars->input);
	vars->new_input[vars->pos - vars->input] = '\0';
	vars->temp = ft_strcat(vars->new_input, vars->exit);
	expand_aux_one(vars);
	if (check_on(vars))
	{
		free(vars->new_input);
		vars->new_input = ft_itoa(ft_atoi(vars->exit) * count_dollar(vars));
	}
	free(vars->exit);
	free(vars->input);
	vars->input = vars->new_input;
	expand_exit_status(vars);
}
