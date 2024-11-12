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
		liberar(vars);
		return (1);
	}
	return (0);
}

void	call_prompt(t_vars *vars)
{
	pid_t		pid;
	size_t		j;
	signal(SIGINT, control_c);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		get_path(vars);
		vars->input = readline("minishell% ");
		if (crtl_all(vars))
			break ;
		vars->cargs = count_args(vars->input);
		vars->args = create_args(vars->input);
		/*if (ft_strncmp(vars->input, "exit", 4) == 0)
			exit(0);*/
		if (ft_strlen(vars->input) > 0)
			add_history(vars->input);
		pid = fork();
		if (pid < 0)
			perror("Error\n");
		else if ( pid == 0)
		{
			signal(SIGINT, SIG_DFL);
			execute_path(vars);
			printf("%s: command not found\n", vars->input);
			exit(EXIT_FAILURE);
		}
		else
			wait(NULL);
		free(vars->input);
		while (j++ < vars->cargs)
			free(vars->args[j]);
		free(vars->args);
	}
	return ;
}
