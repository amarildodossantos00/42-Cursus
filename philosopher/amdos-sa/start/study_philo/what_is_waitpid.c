/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_is_waitpid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:06:28 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/25 13:34:58 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char *av[])
{
	int	pid1;
	int	pid2;
	int	pid1_res;
	int	pid2_res;

	pid1 = fork();
	if (pid1 == -1)
	{
		printf("Error creating process\n");
		return (1);
	}
	if (pid1 == 0)
	{
		sleep(4);
		printf("1Finished execution (%d)\n", getpid());
		return (0);
	}
	pid2 = fork();
	if (pid2 == -1)
	{
		printf("Error creating process\n");
		return (2);
	}
	if (pid2 == 0)
	{
		sleep(1);
		printf("2Finished execution (%d)\n", getpid());
		return (0);
	}
	pid1_res = waitpid(pid1, NULL, 0);
	printf("1Waited for %d\n", pid1_res);
	pid2_res = waitpid(pid2, NULL, 0);
	printf("2Waited for %d\n", pid2_res);
	return (0);
}
