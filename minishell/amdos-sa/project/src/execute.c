/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:07:32 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/10/31 06:59:08 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <string.h>

char	*find_executable(char *command)
{
	char	*path;
	char	*dir;
	char	executable_path[256];
	char	*path_copy;

	path = getenv("PATH");
	if (!path)
		return (NULL);
	path_copy = ft_strdup(path);
	if (!path_copy)
		return (NULL);
	dir = ft_strtok(path_copy, ":");
	while (dir)
	{
		executable_path[0] = '\0';
		sncat(executable_path, dir,
			sizeof(executable_path) - strlen(executable_path) - 1);
		sncat(executable_path, "/", 1);
		sncat(executable_path, command,
			sizeof(executable_path) - strlen(executable_path) - 1);
		if (access(executable_path, X_OK) == 0)
		{
			free(path_copy);
			return (ft_strdup(executable_path));
		}
		dir = ft_strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
