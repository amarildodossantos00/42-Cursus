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
	signal(SIGINT, control_c);
	signal(SIGQUIT, SIG_IGN);

	printf("1e");
	while (1)
	{
		get_path(vars);
		printf("1");
		vars->input = readline("minishell% ");
		if (crtl_all(vars))
			break ;
		if(vars->input[0] == '\0')
		{
			free(vars->input);
			continue ;
		}
		printf("2");
		ft_exit(vars);
		if (ft_strlen(vars->input) > 0)
			add_history(vars->input);
			printf("3");
		//pzau
		if (ft_strncmp(vars->input, "env", ft_strlen(vars->input)) == 0)
			print_variables(vars);
		//cc
		printf("4");
		vars->matrix = ft_split(vars->input);
		printf("5");
		if (!vars->matrix || !vars->matrix[0])
		{
			free(vars->input);
			continue ;
		}
		printf("6");
		if (ft_strncmp(vars->matrix[0], "cd", 2) == 0)
            		cd(vars);
		if (ft_strncmp(vars->input, "pwd", ft_strlen(vars->input)) == 0)
			pwd(vars);
		if (ft_strncmp(vars->matrix[0], "echo", 4) == 0)
			echo(vars);
			printf("7");
		if (ft_strncmp(vars->matrix[0], "unset", 5) == 0)
		{
			printf("8");
			if (vars->matrix[1])
				vars->env_list = unset_env(vars->env_list, vars->matrix[1]);
			else
				printf("unset: nenhuma variavel especificada\n");
		}
		printf("8");
		//cc

		/*else if(ft_strncmp(vars->input, "unset", ft_strlen(vars->input)) == 0)
			remove_variable(vars, "PATH");*/
		if (ft_strncmp(vars->input, "export", ft_strlen(vars->input)) == 0)
			add_variables(vars, "pzau");
		else if (ft_strncmp(vars->input, "path", ft_strlen(vars->input)) == 0)
			printf("%s\n", vars->path);
		//pzau
		printf("9");
		free(vars->input);
		free_matrix(vars->matrix);
		printf("10");
	}
	printf("11");
	return ;
}
