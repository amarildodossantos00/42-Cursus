/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcatete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 07:56:04 by vcatete           #+#    #+#             */
/*   Updated: 2024/10/19 07:56:05 by vcatete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

static void	update_previous_dir(t_prev *prev)
{
	char	cwd[PATH_MAX];
	char	*old_dir;

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		old_dir = prev->previous_dir;
		prev->previous_dir = ft_strdup(cwd);
		if (old_dir != NULL)
			free(old_dir);
	}
	else
	{
		perror("getcwd");
		exit(EXIT_FAILURE);
	}
}

char	*handle_specific_dir(char *dir, char *temp_path)
{
	if (ft_access(dir) == 1)
		temp_path = ft_strjoin("./", dir);
	else if (ft_access(dir) == 2)
		temp_path = ft_strjoin("", dir);
	else
		return ("\n");
	return (temp_path);
}

void	handle_cd(char *entrada)
{
	static t_prev	prev;
	char			*caminho;
	char			cwd[PATH_MAX];

	caminho = ft_strdup("");
	if (*(entrada + 3) == '~' || ft_strcmp(entrada, "cd") == 0)
	{
		caminho = getenv("HOME");
		update_previous_dir(&prev);
	}
	else if (*(entrada + 3) == '-')
	{
		caminho = ft_strdup(prev.previous_dir);
		update_previous_dir(&prev);
	}
	else
	{
		if (ft_strcmp(handle_specific_dir((entrada + 3), caminho), "\n") == 0)
			return ;
		caminho = handle_specific_dir((entrada + 3), caminho);
		update_previous_dir(&prev);
	}
	chdir(caminho);
	getcwd(cwd, sizeof(cwd));
}
