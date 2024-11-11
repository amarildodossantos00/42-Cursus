#include "../header/header.h"

static void	control_c(int sig)
{
	(void)sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static int	crtl_all(t_vars *vars)
{
	if (!vars->input)
	{
		printf("exit\n");
		return (1);
	}
	return (0);
}

void    call_prompt(t_vars *vars)
{
	signal(SIGINT, control_c);
	signal(SIGQUIT, SIG_IGN);

	while (1)
	{
		vars->input = readline("minishell% ");
		if (crtl_all(vars))
			break ;
		if (ft_strlen(vars->input) > 0)
			add_history(vars->input);
		if (ft_strncmp(vars->input, "env", ft_strlen(vars->input)) == 0)
			print_variables(vars);
		//cc
		if (ft_strncmp(vars->input, "cd", ft_strlen(vars->input)) == 0)
			cd(vars);
		else if (ft_strncmp(vars->input, "cd ..", ft_strlen(vars->input)) == 0)
			cd(vars);
		if (ft_strncmp(vars->input, "pwd", ft_strlen(vars->input)) == 0)
			pwd(vars);
		//cc
		free(vars->input);
	}
	return ;
}
