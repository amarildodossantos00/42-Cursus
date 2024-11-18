#include "../header/header.h"


static   void	init_env(t_vars *vars)
{
	t_env	*current;
	char	*var;
	char	*value;
	int	count;

	count = count_variables(vars->variables);
	var = strtok(vars->variables[--count], "=");
	value = strtok(NULL, "");
	vars->env_ref = creat_node(var, value);
	current = vars->env_ref;
	while (--count)
	{
		var = strtok(vars->variables[count], "=");
		value = strtok(NULL, "");
		current->next = creat_node(var, value);
		current = current->next;
	}
}


void	print_a(t_env *env_list)
{
	printf("%s\n", env_list->value);
	while (env_list)
	{
		printf("declare -x %s=%s\n", env_list->var, env_list->value);
		env_list = env_list->next;
	}
}
int	main(void)
{
	t_vars vars;
	extern char	**environ;

	//pzau
	get_variables(&vars, environ);
	//pzau
	init_env(&vars);
	call_prompt(&vars);
	return (0);
}
