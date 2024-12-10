#include "../header/header.h"

char	*get_path(t_vars *vars)
{
    t_env *current;

    if (!vars->env_ref)
    {
        init_env(vars);
    }
    current = vars->env_ref;
    while (current)
    {
        if (strcmp(current->var, "PATH") == 0)
            return current->value;
        current = current->next;
    }
    return "nothing";
}

void ensure_term_variable(t_vars *vars)
{
	t_env *current = vars->env_ref;

	while (current)
	{
		if (ft_strncmp(current->var, "TERM", 4) == 0)
			return;
		current = current->next;
	}
	add_and_update(&vars->env_ref, "TERM", "xterm-256color", 0);
}

char **convert_env_list(t_env *env_list)
{
	int count = 0;
	t_env *current = env_list;
	char **env;
	char *temp;

	while (current)
	{
		count++;
		current = current->next;
	}

	env = malloc(sizeof(char *) * (count + 1));
	if (!env)
		return (NULL);

	current = env_list;
	count = 0;
	while (current)
	{
		temp = ft_strjoin(current->var, "=");
		env[count] = ft_strjoin(temp, current->value);
		free(temp);
		current = current->next;
		count++;
	}
	env[count] = NULL;

	return (env);
}