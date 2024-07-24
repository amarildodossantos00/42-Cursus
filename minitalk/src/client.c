/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:18:05 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/07/24 17:10:04 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minitalk.h"

int	ft_atoi(const char *str)
{
	int	sinal;
	int	res;

	sinal = 1;
	res = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sinal = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *(str++) - '0';
	return (res * sinal);
}

void	enviar_sinal(int pid, char *c)
{
	int	i;
	int	bit;

	while (*c)
	{
		i = 8;
		while (i--)
		{
			bit = ((*c >> i) & 1);
			if (bit % 2 == 0)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(1000);
		}
		c++;
	}
}

int	main(int ac, char *av[])
{
	const char	*sms;
	int			i;
	int			pid;

	if (ac != 3)
	{
		ft_printf("Uso: <PID do servidor> <mensagem>\n");
		exit(0);
	}
	i = 0;
	pid = ft_atoi(av[1]);
	sms = av[2];
	enviar_sinal(pid, ft_strjoin(sms, "\n"));
	return (0);
}
