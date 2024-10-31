/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:35:34 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/10/31 07:00:07 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(void)
{
	static char	*buff;
	char *executable;
	char *args[2];
	while (1)
	{
		buff = readline("minishell% ");
		if (!buff)
			break;
		if (ft_strlen(buff) > 0)
			add_history(buff);
		if (!ft_strncmp(buff, "exit", 4))
		{
			free(buff);
			exit(0);
		}
		executable = find_executable(buff);
		if (executable)
		{
			args[0] = executable;
			args[1] = NULL;
			execv(args[0], args);
			perror("execv falhou");
			free(executable);
		}
		else
			printf("Executable not found: %s\n", buff);
		free(buff);
		buff = NULL;
		executable = NULL;
	}
	return (0);
}
