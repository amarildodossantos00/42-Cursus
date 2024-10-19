/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcatete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 07:56:09 by vcatete           #+#    #+#             */
/*   Updated: 2024/10/19 07:56:10 by vcatete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	handle_echo_2(char *entrada)
{
	char	*value;
	int		i;

	i = 5;
	while (entrada[i])
	{
		if (entrada[i] == 34)
		{
			i++;
			continue ;
		}
		if (entrada[i] == 36)
		{
			value = getenv(&entrada[i + 1]);
			if (value)
				printf("%s ", value);
			else
				printf(" ");
			break ;
		}
		else
			ft_putchar(entrada[i++]);
	}
	printf("\n");
}

void	handle_echo(char *entrada)
{
	if (getenv("PATH"))
	{
		if (ft_strchr(entrada, '|'))
			execute_command_with_pipes(entrada);
		else
		{
			if (ft_strchr(entrada, '>') || ft_strchr(entrada, '<'))
				execute_command_with_redirection(entrada);
			else
				handle_echo_2(entrada);
		}
	}
}
