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
	if (vars->input == NULL)
	{
		printf("sssss\n\n");
		printf("exit\n");
		liberar(vars);
		exit(0);
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
		if(vars->input[0] == '\0')
		{
			free(vars->input);
			continue ;
		}
		ft_exit(vars);
		if (crtl_all(vars))
			break ;
		if (ft_strlen(vars->input) > 0)
			add_history(vars->input);
		//pzau
		if (ft_strncmp(vars->input, "env", ft_strlen(vars->input)) == 0)
			print_variables(vars);
		//cc
		vars->matrix = ft_split(vars->input);
		if (ft_strncmp(vars->matrix[0], "cd", 2) == 0)
            		cd(vars);
		if (ft_strncmp(vars->input, "pwd", ft_strlen(vars->input)) == 0)
			pwd(vars);
		if (ft_strncmp(vars->matrix[0], "echo", ft_strlen(vars->matrix[0])) == 0)
			echo(vars);
		//cc

		if(ft_strncmp(vars->input, "unset", ft_strlen(vars->input)) == 0)
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
