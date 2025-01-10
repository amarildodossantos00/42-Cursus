#include "../../header/header.h"

t_env	*creat_node(char *var, char *value)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
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

void	add_and_update(t_env **env_list, char *var, char *value, int exported)
{
	t_env	*current;
	t_env	*new;

	current = *env_list;
	while (current)
	{
		if (ft_strcmp(current->var, var) == 0)
		{
			free(current->value);
			current->value = ft_strdup(value);
			if (current->exported == 1)
				current->exported = 1;
			return ;
		}
		if (current->next == NULL)
			break ;
		current = current->next;
	}
	new = creat_node(var, value);
	new->exported = exported;
	if (current == NULL)
		*env_list = new;
	else
		current->next = new;
}

static void	swap_nodes(t_env *a, t_env *b)
{
	char	*var;
	char	*value;

	var = a->var;
	value = a->value;
	a->var = b->var;
	a->value = b->value;
	b->var = var;
	b->value = value;
}

t_env	*sort_list(t_env *list)
{
	t_env	*current;
	t_env	*next;

	current = list;
	if (!list || !list->next)
		return (list);
	while (current)
	{
		next = current->next;
		while (next)
		{
			if (ft_strcmp(current->var, next->var) > 0)
				swap_nodes(current, next);
			next = next->next;
		}
		current = current->next;
	}
	return (list);
}
