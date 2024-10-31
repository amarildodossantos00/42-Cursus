/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:35:34 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/10/31 12:28:41 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(void)
{
	static char	*buff;

	while (1)
	{
		buff = readline("minishell% ");
		if (!buff)
			break ;
		if (ft_strlen(buff) > 0)
			add_history(buff);
		if (!ft_strncmp(buff, "exit", 4))
		{
			free(buff);
			exit(0);
		}
		execute_path(buff);
		printf("Executable not found: %s\n", buff);
		free(buff);
		buff = NULL;
	}
	return (0);
}
