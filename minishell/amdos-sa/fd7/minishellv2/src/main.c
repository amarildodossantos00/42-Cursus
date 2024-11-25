#include "../header/header.h"

void	init_env(t_vars *vars)
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

/*3: Atualizar a inicialização
No início do programa (main), a lista de variáveis de ambiente é inicializada com as variáveis do sistema (usando o environ global). A função ensure_term_variable foi chamada logo após a inicialização para garantir que TERM esteja presente:*/
int		main(void)
{
    t_vars  vars;

    init_values(&vars);
    init_env(&vars);
	ensure_term_variable(&vars);
	vars.env = convert_env_list(vars.env_ref);
    start_promp(&vars);
    return (0);
}
