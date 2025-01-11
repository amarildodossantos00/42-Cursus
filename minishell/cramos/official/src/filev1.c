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

void	handle_signals(void)
{
	signal(SIGINT, control_c);
	signal(SIGQUIT, SIG_IGN);
	trigger_promp(2);
}

void	start_promp(t_vars *vars)
{
	handle_signals();
	while (1)
	{
		if (process_input(vars))
			break ;
		free(vars->copy_input);
		free(vars->input);
	}
	rl_clear_history();
	return ;
}
