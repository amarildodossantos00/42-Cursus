#include "../header/header.h"

static void	free_env_list(t_env *env_ref)
{
	t_env *current = env_ref;
	t_env *next;

	while (current != NULL)
	{
		next = current->next;
		free(current->var);
		free(current->value);
		free(current);
		current = next;
	}
}

void	init_env(t_vars *vars)
{
	char		*var;
	char		*value;
	char		*env_copy;
	int			count;
	t_env		*current;

	count = count_variables(vars->env);
	if (count <= 0)
		return ;
	env_copy = ft_strdup(vars->env[--count]);
	var = ft_strtok(env_copy, "=");
	value = ft_strtok(NULL, "");
	vars->env_ref = creat_node(var, value);
	current = vars->env_ref;
	free(env_copy);
	while (--count >= 0)
	{
		env_copy = ft_strdup(vars->env[count]);
		var = ft_strtok(env_copy, "=");
		value = ft_strtok(NULL, "");
		current->next = creat_node(var, value);
		current = current->next;
		free(env_copy);
	}
	if (current != NULL)
		current->next = NULL;
}

static void	init_values(t_vars *vars)
{
	extern char	**environ;

	vars->input = NULL;
	vars->path = NULL;
	vars->home = NULL;
	vars->matrix = NULL;
	vars->args = NULL;
	vars->copy_input = NULL;
	vars->redic_filter = NULL;
	vars->env = environ;
	vars->cargs = 0;
	vars->redic_filter = NULL;
	vars->commands = NULL;
	vars->terminal = 0;
	vars->exit_status = 0;
	vars->val_red = 0;
	vars->input_fd = 0;
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
