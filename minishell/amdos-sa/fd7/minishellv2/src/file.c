#include "../header/header.h"

static void	control_c(int sig)
{
	(void)sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
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
	read_readline(vars);
	free(vars->input);
	}
	return ;
}
