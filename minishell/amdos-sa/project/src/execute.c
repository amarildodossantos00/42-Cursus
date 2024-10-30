/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:07:32 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/10/30 14:42:07 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <string.h>

char	*find_executable(char *command)
{
	char	*path;
	char	*dir;
	char	executable_path[256];

	path = getenv("PATH");
	dir = ft_strtok(path, ":");
	while (dir)
	{
		executable_path[0] = '\0';
		printf("%s\n", dir);
		sncat(executable_path, dir,
			sizeof(executable_path) - strlen(executable_path) - 1);
		sncat(executable_path, "/", 1);
		sncat(executable_path, command,
			sizeof(executable_path) - strlen(executable_path) - 1);
		printf("\n%s\n", executable_path);
		if (access(executable_path, X_OK) == 0)
			return (ft_strdup(executable_path));
		dir = ft_strtok(NULL, ":");
	}
	return (NULL);
}
