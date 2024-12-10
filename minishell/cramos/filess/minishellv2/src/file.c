#include "../header/header.h"

int	trigger_promp(int val)
{
	static int	status = 0;

	if (val != -1)
		status = val;
	return (status);
}

static int	last_status(int val)
{
	static int	status;

	if (val != 1)
		status = val;
	return (status);
}
static void	control_c(int sig)
{
	(void)sig;
	//last_status(130);
	printf("\n");
	rl_replace_line("", 0);
	if (trigger_promp(-1) > 1)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

static int	crtl_d(t_vars *vars)
{
	if (!vars->input)
	{
		printf("exit\n");
		//liberar(vars);
		return (1);
	}
	return (0);
}

void    start_promp(t_vars *vars)
{
	signal(SIGINT, control_c);
	signal(SIGQUIT, SIG_IGN);

	while (1)
	{
		vars->path = get_path(vars);
		vars->input = readline("minishell% ");
		if (crtl_d(vars))
			break ;
		if(vars->input[0] == '\0')
		{
			free(vars->input);
			continue ;
		}
		if (ft_strlen(vars->input) > 0)
			add_history(vars->input);
		expand_exit_status(vars);
		read_readline(vars);
		free(vars->input);
		trigger_promp(2);
	}
	return ;
}