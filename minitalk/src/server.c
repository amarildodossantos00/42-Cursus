/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <amdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:13:34 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/07/24 12:56:26 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minitalk.h"

void	conversor_sinal(int sinal)
{
	static unsigned char	c;
	static int				i;

	c |= (sinal == SIGUSR1);
	i++;
	if (i == 8)
	{
		if (c == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", c);
		i = 0;
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	ft_printf("Servidor pronto. PID: %d\n", getpid());
	signal(SIGUSR1, conversor_sinal);
	signal(SIGUSR2, conversor_sinal);
	while (1)
		pause();
	return (0);
}
