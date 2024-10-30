/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:35:34 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/10/30 16:23:42 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(void)
{
	static char	*buff;
	char *executable = find_executable("ls");
	char *args[] = {executable, NULL};
	while (1)
	{
		buff = readline("minishell% ");
		if (ft_strlen(buff) > 0)
			add_history(buff);
		if (!ft_strncmp(buff, "ls", ft_strlen(buff)))
		{
			free(buff);
			if (executable)
			{
				execv(args[0], args);
				perror("execv falhou");
				free(executable);
			} else
				printf("Executable not found.\n");
		}
		if (!ft_strncmp(buff, "exit", ft_strlen(buff)))
		{
			free(buff);
			exit(0);
		}
		else
			printf("%s: command not found\n", buff);
		free(buff);
	}
/*		if (executable)
		{
			execv(args[0], args);
			perror("execv falhou");
			free(executable);
		} else
			printf("Executable not found.\n");*/
	return (0);
}
