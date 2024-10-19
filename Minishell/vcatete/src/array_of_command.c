/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_of_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcatete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 07:55:52 by vcatete           #+#    #+#             */
/*   Updated: 2024/10/19 07:55:54 by vcatete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	handle_ls(char *entrada)
{
	if (getenv("PATH"))
		if (ft_strchr(entrada, '|'))
			execute_command_with_pipes(entrada);
}

void	handle_exit(char *entrada)
{
	(void)entrada;
	exit(0);
}

void	handle_signal(int signo)
{
	if (signo == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
}

void	handle_signal_shell(char *entrada)
{
	(void)entrada;
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, SIG_IGN);
}

void	command_init(t_Command commands[])
{
	commands[0] = (t_Command){"replace_line", handle_replace_line, 0};
	commands[1] = (t_Command){"clear_history", handle_clear_history, 0};
	commands[2] = (t_Command){"env", handle_env, 0};
	commands[3] = (t_Command){"setenv", handle_setenv, 1};
	commands[4] = (t_Command){"ls -l |", handle_ls, 1};
	commands[5] = (t_Command){"ls |", handle_ls, 1};
	commands[6] = (t_Command){"cd", handle_cd, 1};
	commands[7] = (t_Command){"exit", handle_exit, 1};
	commands[8] = (t_Command){"unsetenv", handle_unsetenv, 1};
	commands[9] = (t_Command){"echo", handle_echo, 1};
	commands[10] = (t_Command){NULL, NULL, 0};
}
