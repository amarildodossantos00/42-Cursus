#include "../header/header.h"

int	is_special(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

int	is_delimiter(char c)
{
	return (c == ' ' || c == '\t' || c == '\0');
}

char	*ft_var_name(char *str, int n)
{
	char	*res;
	int		i;
	int		len;

	i = n;
	len = 0;
	if (str[n + 1] == '?')
		len++;
	if (!is_special(str[n]) && (isalnum(str[n + 1]) \
	|| str[n + 1] == '_'))
		while (str[++n] && (!is_special(str[n]) \
		&& (isalnum(str[n]) || str[n] == '_')))
			len++;
	else
		len++;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, &str[++i], (len + 1));
	return (res);
}

void	expand_no_env(char **str, char *var_name, int *i)
{
	char	*tmp;
	int		k;
	int		j;

	tmp = ft_strdup(*str);
	if (!tmp)
	{
		free(tmp);
		return ;
	}
	free(*str);
	*str = (char *)malloc(sizeof(char) * (ft_strlen(tmp) \
	- ft_strlen(var_name) + 1));
	if (!(*str))
	{
		free(tmp);
		*str = NULL;
		return ;
	}
	//mudar para ft_bzero
	bzero(*str, ft_strlen(tmp) - ft_strlen(var_name) + 1);
	k = ft_strnfill(*str, tmp, *i);
	j = k + ft_strlen(var_name);
	ft_strcpy(&(*str)[k], &tmp[++j]);
	free(tmp);
}

char	*do_expansion(char *str, char *value, char *var_name, int *i)
{
	char	*res;
	int		l;
	int		j;
	int		k;

	if (!str || !value)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(str) \
	+ ft_strlen(value) - ft_strlen(var_name) + 1));
	if (!res)
		return (NULL);
	l = ft_strnfill(res, str, *i);
	j = ft_strnfill(&res[l], value, ft_strlen(value));
	k = l + ft_strlen(var_name);
	*i = l + j;
	ft_strcpy(&res[l + j], &str[++k]);
	return (res);
}

int	look_for_var(t_vars *minishell, char **str, char *var_name, int *i)
{
	t_env	*head;
	char	*tmp;
	int		res;

	res = 0;
	//if (if_exit_status(minishell, str, var_name, i))
	//	return (1);
	head = minishell->env_ref;
	tmp = ft_strdup(*str);
	while (minishell->env_ref)
	{
		if (ft_strcmp(minishell->env_ref->var, var_name) == 0)
		{
			free(*str);
			*str = do_expansion(tmp, minishell->env_ref->value, var_name, i);
			res = 1;
			break ;
		}
		minishell->env_ref = minishell->env_ref->next;
	}
	free(tmp);
	minishell->env_ref = head;
	return (res);
}

static	void	dollar_sign(t_vars *vars, char **str, int *i)
{
	char	*var_name;

	var_name = ft_var_name(*str, *i);
	if (!look_for_var(vars, str, var_name, i))
		expand_no_env(str, var_name, i);
	free(var_name);
}

void	double_quotes(t_vars *vars, char **str, int *i)
{
	(*i)++;
	while ((*str)[*i] && (*str)[*i] != '"')
	{
		if ((*str)[*i] == '$')
		{
			if ((*str)[*i + 1] == '"' || is_special((*str)[*i + 1]))
			{
				(*i)++;
				continue ;
			}
			dollar_sign(vars, str, i);
			continue ;
		}
		(*i)++;
	}
	++(*i);
}

int	expand_var(t_vars *vars)
{
	int		i;

	i = 0;
	while (vars->input[i])
	{
		if (vars->input[i] == '\'')
		{
			i++;
			while (vars->input[i] && vars->input[i] != '\'')
				i++;
			if (vars->input[i] == '\'')
				i++;
		}
		else if (vars->input[i] == '"' && vars->input[i] != '\0')
			double_quotes(vars, &vars->input, &i);
		if (vars->input[i] == '$' && !is_delimiter(vars->input[i + 1]) && !is_special(vars->input[i + 1]))
			dollar_sign(vars, &vars->input, &i);
		else
			i++;
	}
	return (0);
}
