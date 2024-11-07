/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:04:58 by pzau              #+#    #+#             */
/*   Updated: 2024/11/06 11:59:38 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

int	main(void)
{
	//t_vars vars;
	char *input = readline("minishell% ");

	rl_replace_line("novo_comando", 1);
	rl_redisplay();

	free(input);
	return (0);
}
