#include "../header/header.h"

static int  cheack_build_builtins(t_vars *vars)
{
	/*if (ft_strncmp(vars->input, "echo", 4) == 0 &&
		(vars->input[4] == '\0' || vars->input[4] == ' '))
		return (1);*/
	if (ft_strncmp(vars->input, "cd", 2) == 0 &&
		(vars->input[2] == '\0' || vars->input[2] == ' '))
		return (1);
	if (ft_strncmp(vars->input, "pwd", 3) == 0 &&
		(vars->input[3] == '\0' || vars->input[3] == ' '))
		return (1);
	/*if (ft_strncmp(vars->input, "export", 6) == 0 &&
		(vars->input[6] == '\0' || vars->input[6] == ' '))
		return (1);
	if (ft_strncmp(vars->input, "unset", 5) == 0 &&
		(vars->input[5] == '\0' || vars->input[5] == ' '))
		return (1);
	if (ft_strncmp(vars->input, "env", 3) == 0 &&
		(vars->input[3] == '\0' || vars->input[3] == ' '))
		return (1);
	if (ft_strncmp(vars->input, "exit", 4) == 0 &&
		(vars->input[4] == '\0' || vars->input[4] == ' '))
		return (1);*/
	return (0);
}

void    build_builtins(t_vars *vars)
{
    vars->matrix = ft_split_args(vars->input);
    //if (ft_strncmp(vars->input, "echo", 4) == 0)
        //echo(vars);
    if (ft_strncmp(vars->input, "cd", 2) == 0)
        cd(vars);
    if (ft_strncmp(vars->input, "pwd", 3) == 0)
        pwd(vars);
    /*if (ft_strncmp(vars->input, "export", 6) == 0)
        ft_export(vars, vars->matrix);
    if (ft_strncmp(vars->input, "unset", 5) == 0)
        ft_unset(vars->env_ref, &vars->matrix[1]);
    if (ft_strncmp(vars->input, "env", 3) == 0)
        env(vars);
    if (ft_strncmp(vars->input, "exit", 4) == 0)
        ft_exit(vars);*/
}

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
		if (cheack_build_builtins(vars))
        		build_builtins(vars);
		//pzau
		free(vars->input);
	}
	return ;
}
