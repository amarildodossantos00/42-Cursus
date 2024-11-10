/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:53:19 by pzau              #+#    #+#             */
/*   Updated: 2024/11/08 13:58:19 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

static void	inicialize_args(t_vars *vars)
{
	const char **commands;
	int num_commands;
	int i;

	i = 0;
	commands = (const char *[]){"echo", "cd", "pwd", "export", "unset", "env", "exit"};
	num_commands = 7;
	vars->bibleoteca = malloc(sizeof(char *) * (num_commands + 1));
	while (i < num_commands)
	{
		vars->bibleoteca[i] = strdup(commands[i]);
		i++;
	}

}

int	main(void)
{
	t_vars vars;
	//extern char **environ;

	inicialize_args(&vars);
	inicialize_all(&vars);
	return (0);
}
