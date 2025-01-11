#include "../header/header.h"

int	g_sig;

static void	free_env_list(t_env *env_ref)
{
	t_env	*current;
	t_env	*next;

	current = env_ref;
	while (current != NULL)
	{
		next = current->next;
		free(current->var);
		free(current->value);
		free(current);
		current = next;
	}
}

t_env	*create_env_node(char *env_entry)
{
	char	*env_copy;
	char	*var;
	char	*value;
	t_env	*node;

	env_copy = ft_strdup(env_entry);
	var = ft_strtok(env_copy, "=");
	value = ft_strtok(NULL, "");
	node = creat_node(var, value);
	if (!env_copy)
		return (NULL);
	free(env_copy);
	return (node);
}

void	append_env_node(t_env **current, char *env_entry)
{
	t_env	*new_node;

	new_node = create_env_node(env_entry);
	if (new_node)
	{
		(*current)->next = new_node;
		*current = new_node;
	}
}

void	init_env(t_vars *vars)
{
	int		count;
	t_env	*current;

	count = count_variables(vars->env);
	if (count <= 0)
		return ;
	vars->env_ref = create_env_node(vars->env[--count]);
	if (!vars->env_ref)
		return ;
	current = vars->env_ref;
	while (--count >= 0)
		append_env_node(&current, vars->env[count]);
	if (current != NULL)
		current->next = NULL;
}

int	main(void)
{
	t_vars	vars;

	init_values(&vars);
	init_env(&vars);
	ensure_term_variable(&vars);
	vars.env = convert_env_list(vars.env_ref);
	start_promp(&vars);
	free_env_list(vars.env_ref);
	free_convert_env_list(vars.env);
	return (0);
}
