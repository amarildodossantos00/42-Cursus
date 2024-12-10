
#include "../header/header.h"

t_env	*creat_node(char *var, char *value)
{
	t_env	*new = malloc(sizeof(t_env));
	if (!new)
	{
		perror("Erro!");
		return (NULL);
	}
	new->var = ft_strdup(var);
	new->value = ft_strdup(value);
	new->next = NULL;
	return (new);
}

void	add_and_update(t_env **env_list, char *var, char *value)
{
	t_env	*current = *env_list;

	while (current)
	{
		if (ft_strcmp(current->var, var) == 0)
		{
			free(current->value);
			current->value = ft_strdup(value);
			return ;
		}
		if (current->next == NULL)
			break;
		current = current->next;
	}
	t_env *new = creat_node(var, value);

	if (current == NULL)
		*env_list = new;
	else
		current->next = new;
}


void	ft_remove(t_env **env_list, char *var)
{
	t_env	*current = *env_list;
	t_env	*prev = NULL;

	while (current)
	{
		if (ft_strcmp(current->var, var) == 0)
		{
			if (prev)
				prev->next = current->next;
			else
				*env_list = current->next;
			free(current->var);
			free(current->value);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

void	print_env(t_env *env_list)
{
	while (env_list)
	{
		printf("declare -x %s=%s\n", env_list->var, env_list->value);
		env_list = env_list->next;
	}
}

void	ft_export(t_vars *vars, char **args)
{
	if (!args[1])
		print_env(vars->env_ref);
	
	else
	{
		int	i;

		i = 1;
		while (args[i])
		{
			char	*var = strtok(args[i], "=");
			char	*value = strtok(NULL, "");
			if (!var || !value)
				 fprintf(stderr, "export: invalid format '%s'\n", args[i]);
			else
				add_and_update(&vars->env_ref, var, value);
			i++;
		}
		
	}
}
