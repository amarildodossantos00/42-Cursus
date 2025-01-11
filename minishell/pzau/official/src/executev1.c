#include "../header/header.h"

void	process_ev_aux(t_vars *vars)
{
	vars->var_len = 0;
	while (vars->start[vars->var_len] && (ft_isalnum(vars->start[vars->var_len])
			|| vars->start[vars->var_len] == '_'))
		vars->var_len++;
}

int	process_env_variable(char *input, char **result, int *i, int *j)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	vars->start = &input[*i + 1];
	process_ev_aux(vars);
	if (vars->var_len > 0)
	{
		vars->var_name = malloc(vars->var_len + 1);
		if (!vars->var_name)
			return (0);
		ft_strncpy(vars->var_name, vars->start, vars->var_len);
		vars->var_name[vars->var_len] = '\0';
		vars->env_value = getenv(vars->var_name);
		free(vars->var_name);
		if (vars->env_value)
		{
			ft_strcpy(&(*result)[*j], vars->env_value);
			*j += ft_strlen(vars->env_value);
		}
		*i += vars->var_len + 1;
		return (1);
	}
	return (0);
}

void	remove_qou_aux(t_vars *vars, char *input)
{
	vars->in = 0;
	vars->j = 0;
	vars->in_single_quote = 0;
	vars->in_double_quote = 0;
	vars->result = malloc(ft_strlen(input) + 1);
}

void	remove_qou_aux1(t_vars *vars)
{
	printf("Error: Unclosed quotes\n");
	free(vars->result);
}

char	*remove_quotes(char *input, t_vars *vars)
{
	remove_qou_aux(vars, input);
	if (!vars->result)
		return (NULL);
	while (input[vars->in])
	{
		if (input[vars->in] == '\'' && !vars->in_double_quote)
			vars->in_single_quote = !vars->in_single_quote;
		else if (input[vars->in] == '"' && !vars->in_single_quote)
			vars->in_double_quote = !vars->in_double_quote;
		else if (input[vars->in] == '$' && vars->in_double_quote)
		{
			if (process_env_variable(input, &vars->result, &vars->in, &vars->j))
				continue ;
		}
		else
			vars->result[vars->j++] = input[vars->in];
		vars->in++;
	}
	vars->result[vars->j] = '\0';
	if (vars->in_single_quote || vars->in_double_quote)
	{
		remove_qou_aux1(vars);
		return (NULL);
	}
	return (vars->result);
}
