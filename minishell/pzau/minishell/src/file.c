/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:54:35 by pzau              #+#    #+#             */
/*   Updated: 2024/11/08 13:57:29 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

void	inicialize_all(t_vars *vars)
{
	while (1)
	{
		vars->input = readline("minishell% ");
		add_history(vars->input);
		free(vars->input);
	}
	return ;
}
