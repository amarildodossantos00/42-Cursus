/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:35:34 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/10/30 14:01:59 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(void)
{
	//static char	*buff;
	/*
	buff = readline("minishell% ");
	if (ft_strlen(buff) > 0)
		add_history(buff);
	if (!strcmp(buff, "exit"))
	{
		exit(0);
		free(buff);
	}
	else
		printf("%s: command not found\n", buff);
	free(buff);*/
		char *executable = find_executable("clear");
		if (executable)
		{
			printf("Found executable: %s\n", executable);
			free(executable);
		} else
			printf("Executable not found.\n");
	return (0);
}
