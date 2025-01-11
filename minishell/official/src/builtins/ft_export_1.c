#include "../../header/header.h"

void	print_env(t_env *env_list)
{
	sort_list(env_list);
	while (env_list)
	{
		if (env_list)
			printf("declare -x %s=\"%s\"\n", env_list->var, env_list->value);
		else
			printf("declare -x %s\n", env_list->var);
		env_list = env_list->next;
	}
}

void	extract_var_value(char *arg, char **var, char **value)
{
	char	*equal;

	equal = ft_strchr(arg, '=');
	if (equal)
	{
		*var = ft_substr(arg, 0, equal - arg);
		*value = ft_strdup(equal + 1);
	}
	else
	{
		*var = ft_strdup(arg);
		*value = ft_strdup("");
	}
}

void	handle_invalid_identifier(t_vars *vars,
	char *arg, char *var, char *value)
{
	printf("bash: export: `%s': not a valid identifier\n", arg);
	vars->exit_status = 1;
	free(var);
	free(value);
}

void	ft_export(t_vars *vars, char **args)
{
	char	*var;
	char	*value;
	int		i;

	i = 1;
	if (!args[1])
		print_env(vars->env_ref);
	else
	{
		while (args[i])
		{
			extract_var_value(args[i], &var, &value);
			if (!is_valid_identifier(var))
			{
				handle_invalid_identifier(vars, args[i], var, value);
				i++;
				continue ;
			}
			add_and_update(&vars->env_ref, var, value, 1);
			free(var);
			free(value);
			i++;
		}
	}
}
