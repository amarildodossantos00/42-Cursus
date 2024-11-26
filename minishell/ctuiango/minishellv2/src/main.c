#include "../header/header.h"

static   void	init_env(t_vars *vars)
{
	t_env	*current;
	char	*var;
	char	*value;
	int	count;

	count = count_variables(vars->env);
	var = ft_strtok(vars->env[--count], "=");
	value = ft_strtok(NULL, "");
	vars->env_ref = creat_node(var, value);
	current = vars->env_ref;
	while (--count)
	{
		var = ft_strtok(vars->env[count], "=");
		value = ft_strtok(NULL, "");
		current->next = creat_node(var, value);
		current = current->next;
	}
}

static  void    init_values(t_vars *vars)
{
    extern char	**environ;

    vars->input = NULL;
    vars->path = NULL;
    vars->home = NULL;
    vars->matrix = NULL;
    vars->args = NULL;
    vars->env = environ;
    vars->cargs = 0;
}

int		main(void)
{
    t_vars  vars;

    init_values(&vars);
    init_env(&vars);
    start_promp(&vars);
    return (0);
}
