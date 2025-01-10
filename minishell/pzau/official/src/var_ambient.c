#include "../header/header.h"

int	get_exit_status(t_vars *vars)
{
	t_env	*current;

	if (!vars->env_ref)
		init_env(vars);
	current = vars->env_ref;
	while (current)
	{
		if (ft_strcmp(current->var, "?") == 0)
			return (1);
		current = current->next;
	}
	return (0);
}

void	ensure_term_variable(t_vars *vars)
{
	t_env	*current;

	current = vars->env_ref;
	while (current)
	{
		if (ft_strncmp(current->var, "TERM", 4) == 0)
			return ;
		current = current->next;
	}
	add_and_update(&vars->env_ref, "TERM", "xterm-256color", 0);
}

int	count_env_list(t_env *env_list)
{
	int		count;
	t_env	*current;

	count = 0;
	current = env_list;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

char	*create_env_entry(t_env *node)
{
	char	*temp;
	char	*env_entry;

	temp = ft_strjoin(node->var, "=");
	if (!temp)
		return (NULL);
	env_entry = ft_strjoin(temp, node->value);
	free(temp);
	return (env_entry);
}

char	**convert_env_list(t_env *env_list)
{
	char	**env;
	t_env	*current;

	env_list->count = count_env_list(env_list);
	env = malloc(sizeof(char *) * (env_list->count + 1));
	if (!env)
		return (NULL);
	current = env_list;
	env_list->index = 0;
	while (current)
	{
		env[env_list->index] = create_env_entry(current);
		if (!env[env_list->index])
		{
			while (--env_list->index >= 0)
				free(env[env_list->index]);
			free(env);
			return (NULL);
		}
		current = current->next;
		env_list->index++;
	}
	env[env_list->index] = NULL;
	return (env);
}
