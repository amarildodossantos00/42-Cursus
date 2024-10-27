/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcatete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 07:56:41 by vcatete           #+#    #+#             */
/*   Updated: 2024/10/19 07:56:43 by vcatete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	count_spaces(char *str)
{
	int	i;
	int	count;
	int	control;

	i = 0;
	count = 0;
	control = 0;
	while (str[i] == 32 || str[i] == '\t')
		i++;
	while (str[i])
	{
		if (str[i] == 32 || str[i] == 9)
			control = 1;
		else
		{
			if (control == 1)
				count++;
			control = 0;
			count++;
		}
		i++;
	}
	return (count);
}

char	*ft_copiar(char *str2, char *str)
{
	int	i;
	int	j;
	int	control;

	i = 0;
	control = 0;
	while (str[i] == 32 || str[i] == '\t')
		i++;
	j = 0;
	while (str[i])
	{
		if (str[i] == 32 || str[i] == 9)
			control = 1;
		if (str[i] != 32 && str[i] != 9)
		{
			if (control == 1)
				str2[j++] = ' ';
			control = 0;
			str2[j] = str[i];
			j++;
		}
		i++;
	}
	str2[j] = '\0';
	return (str2);
}

char	*epur(char *str)
{
	char	*str2;
	int		len;

	len = count_spaces(str);
	str2 = (char *)malloc(sizeof(char) * len + 1);
	if (!str2)
		return (0);
	str2 = ft_copiar(str2, str);
	return (str2);
}

int	main(void)
{
	t_Command	commands[11];
	char		*entrada;

	command_init(commands);
	entrada = NULL;
	handle_signal_shell(entrada);
	if (fork() == 0)
	{
		while (1)
		{
			entrada = readline(
					"\033[32m\033[1m🤗mini_shell\033[0m\033[33m\033[1m$\033[0m> ");
			if (!entrada)
				break ;
			if (*entrada)
				add_history(entrada);
			entrada = epur(entrada);
			execute_command(entrada, commands);
			free(entrada);
		}
	}
	else
		wait(NULL);
	return (0);
}
