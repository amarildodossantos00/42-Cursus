#include "../header/header.h"

int	trigger_promp(int val)
{
	static int	status = 0;

	if (val != -1)
		status = val;
	return (status);
}

static void	control_c(int sig)
{
	(void)sig;
	printf("\n");
	rl_on_new_line();
	if (trigger_promp(-1) > 1)
	{
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

static int	crtl_d(t_vars *vars)
{
	if (!vars->input)
	{
		printf("exit\n");
		return (1);
	}
	return (0);
}

void	start_promp(t_vars *vars)
{
	signal(SIGINT, control_c);
	signal(SIGQUIT, SIG_IGN);
	trigger_promp(2);
	while (1)
	{
		vars->path = get_path(vars);
		vars->copy_input = readline("minishell% ");
		vars->input = ft_trim(vars->copy_input);
		if (crtl_d(vars))
			break ;
		if (vars->input[0] == '\0')
		{
			free(vars->copy_input);
			free(vars->input);
			continue ;
		}
		if (ft_strlen(vars->input) > 0)
			add_history(vars->copy_input);
		expand_exit_status(vars);
		read_readline(vars);
		trigger_promp(2);
		free(vars->copy_input);
		free(vars->input);
	}
	rl_clear_history();
	return ;
}
