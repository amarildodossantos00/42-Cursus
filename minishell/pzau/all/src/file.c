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

void    call_prompt(t_vars *vars)
{
	pid_t		pid;
	size_t		j;
	signal(SIGINT, control_c);
	signal(SIGQUIT, SIG_IGN);

	while (1)
	{
		get_path(vars);
		//update_last_comand(vars);
		vars->input = readline("minishell% ");
		if (crtl_all(vars))
			break ;
		if(vars->input[0] == '\0')
		{
			free(vars->input);
			continue ;
		}
		ft_exit(vars);
		vars->cargs = count_args(vars->input);
		vars->args = create_args(vars->input);
		if (ft_strlen(vars->input) > 0)
			add_history(vars->input);
		//pzau
		if (filter_commands(vars))
			vars->ok = 1;
		else
		{
			//amdos-sa
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
			while (j++ < vars->cargs)
				free(vars->args[j]);
			free(vars->args);
		}
		//amdos-sa
		free(vars->input);
	}
	return ;
}
