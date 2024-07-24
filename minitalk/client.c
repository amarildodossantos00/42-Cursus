/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:18:05 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/07/24 13:03:19 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	enviar_sinal(int pid, unsigned char c)
{
	int				i;
	unsigned char	aux;

	i = 8;
	aux = c;
	while (i > 0)
	{
		i--;
		aux = c >> i;
		if (aux % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(50);
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
	while (sms[i])
		enviar_sinal(pid, sms[i++]);
	enviar_sinal(pid, '\0');
	return (0);
}
