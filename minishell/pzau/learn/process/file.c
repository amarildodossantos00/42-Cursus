/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:53:18 by pzau              #+#    #+#             */
/*   Updated: 2024/11/04 11:05:02 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

int	main()
{
	int pid = fork();
	if (pid == 0)
	{
		char *args[] = {"/bin/ls", NULL};
		execve(args[0], args, NULL);
		printf("Esta linha nunca sera executada se o execve() for bem sucedido!\n");
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	return (0);
}
