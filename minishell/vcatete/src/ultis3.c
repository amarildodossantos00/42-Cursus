/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultis3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcatete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 07:57:12 by vcatete           #+#    #+#             */
/*   Updated: 2024/10/19 07:57:14 by vcatete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	ft_access(const char *filename)
{
	int	i;

	i = 0;
	if (access(filename, F_OK) != 0)
	{
		printf("Caminho não encontrado!\n");
		return (0);
	}
	if (filename[i] == '/')
		return (2);
	return (1);
}

int	is_executable(char *path)
{
	return (access(path, X_OK) == 0);
}

void	handle_replace_line(char *entrada)
{
	(void)entrada;
	rl_replace_line("linha substituída", 1);
	rl_redisplay();
}

void	handle_clear_history(char *entrada)
{
	(void)entrada;
	printf("você deletou o history \n");
	rl_clear_history();
}
