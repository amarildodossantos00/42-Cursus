#include "../header/header.h"

static int	check_unclosed_quotes(char *str)
{
	int	single_quote_open;
	int	double_quote_open;

	single_quote_open = 0;
	double_quote_open = 0;
	while (*str)
	{
		if (*str == '\'' && !double_quote_open)
			single_quote_open = !single_quote_open;
		else if (*str == '"' && !single_quote_open)
			double_quote_open = !double_quote_open;
		str++;
	}
	if (single_quote_open)
		return (1);
	if (double_quote_open)
		return (1);
	return (0);
}

static int	cheak_string(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->input[i])
	{
		if (vars->input[i] == '|')
			return (1);
		i++;
	}
	i = 0;
	while (vars->input[i])
	{
		if (vars->input[i] == '>' || vars->input[i] == '<')
		{
			if ((vars->input[i + 1] && vars->input[i]) == vars->input[i + 1])
				return (2);
			return (3);
		}
		i++;
	}
	return (0);
}

static int	cheack_stringv2(char *str)
{
	char	quote_type;
	int		i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '\'' || str[i] == '"')
	{
		quote_type = str[i];
		i++;
		while (str[i] && str[i] != quote_type)
			i++;
		if (str[i] == quote_type)
		{
			i++;
			while (str[i] && ft_isspace(str[i]))
				i++;
			return (str[i] == '\0');
		}
	}
	return (0);
}

void	read_readline(t_vars *vars)
{
	int	val;
	int	val2;

	val = cheak_string(vars);
	val2 = cheack_stringv2(vars->input);
	if (check_unclosed_quotes(vars->input))
	{
		printf("Erro: aspas nao fechadas\n");
		return ;
	}
	expand_var(vars);
	if (val == 1 && val2 == 0)
		execute_pipe(vars);
	else if ((val == 2 || val == 3) && val2 == 0)
		redirecionamento(vars, 0);
	else
		only_comands(vars);
	return ;
}
