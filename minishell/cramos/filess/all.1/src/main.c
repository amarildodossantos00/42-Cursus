#include "../header/header.h"

int	main(char **envp)
{
	t_vars vars;
	extern char	**environ;

	vars.env_list = init_env_list(envp);
	vars.input = NULL;
	vars.matrix = NULL;
	vars.path = NULL;
	//pzau
	get_variables(&vars, environ);
	//pzau
	while (vars.env_list)
	{
		t_env	*temp;

		vars.env_list;
		vars.env_list = vars.env_list->next;
		free_env_node(temp);
	}
	call_prompt(&vars);
	return (0);
}
