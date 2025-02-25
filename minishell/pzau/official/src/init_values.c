#include "../header/header.h"

static void	init_values_one(t_vars *vars)
{
	vars->i = 0;
	vars->var_len = 0;
	vars->start = NULL;
	vars->var_name = NULL;
	vars->env_value = NULL;
	vars->result = NULL;
	vars->in = 0;
	vars->j = 0;
	vars->in_single_quote = 0;
	vars->in_double_quote = 0;
	vars->dir = NULL;
	vars->executable = NULL;
	vars->path_copy = NULL;
	vars->executablee = NULL;
	vars->new_strr = NULL;
	vars->envv = NULL;
	vars->command = NULL;
	vars->str_space = NULL;
	vars->str_split = NULL;
}

void	init_values(t_vars *vars)
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
	vars->pos = NULL;
	vars->new_input = NULL;
	vars->exit = NULL;
	vars->temp = NULL;
	vars->aux = NULL;
	vars->input_copy = NULL;
	vars->argss = NULL;
	init_values_one(vars);
}
