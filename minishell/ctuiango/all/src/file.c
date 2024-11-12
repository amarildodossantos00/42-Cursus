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
		liberar(vars);
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
		get_path(vars);
		vars->input = readline("minishell% ");
		if (crtl_d(vars))
			break ;
		if (ft_strlen(vars->input) > 0)
			add_history(vars->input);
		//pzau
		if (ft_strncmp(vars->input, "env", ft_strlen(vars->input)) == 0)
			print_variables(vars);
		else if (ft_strncmp(vars->input, "unset", ft_strlen(vars->input)) == 0)
			remove_variable(vars, "PATH");
		else if (ft_strncmp(vars->input, "export", ft_strlen(vars->input)) == 0)
			add_variables(vars, "pzau");
		else if (ft_strncmp(vars->input, "path", ft_strlen(vars->input)) == 0)
			printf("%s\n", vars->path);
		//pzau
		free(vars->input);
	}
	return ;
}
