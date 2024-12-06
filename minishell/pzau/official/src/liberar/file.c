/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:15:45 by pzau              #+#    #+#             */
/*   Updated: 2024/12/06 13:22:16 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

static void	free_env(t_env *env)
{
	t_env *tmp;

	while (env)
	{
		tmp = env;
		env = env->next;
		free(tmp->var);
		free(tmp->value);
		free(tmp);
	}
}

static void	free_vars(t_vars *vars)
{
	int	i;

	if (vars->env)
	{
		i = 0;
		while (vars->env[i] != NULL)
		{
			free(vars->env[i]);
			i++;
		}
		free(vars->env);
	}
	if (vars->matrix)
	{
		i = 0;
		while (vars->matrix[i] != NULL)
		{
			free(vars->matrix[i]);
			i++;
		}
		free(vars->matrix);
	}
	if (vars->args)
	{
		i = 0;
		while (vars->args[i] != NULL)
		{
			free(vars->args[i]);
			i++;
		}
		free(vars->args);
	}
	if (vars->redic_filter)
	{
		i = 0;
		while (vars->redic_filter[i] != NULL)
		{
			free(vars->redic_filter[i]);
			i++;
		}
		free(vars->redic_filter);
	}
	if (vars->commands)
	{
		i = 0;
		while (vars->commands[i] != NULL)
		{
			free(vars->commands[i]);
			i++;
		}
		free(vars->commands);
	}
	free(vars->input);
	free(vars->path);
	free(vars->home);
	free_env(vars->env_ref);
}

void	call_free(t_env *env, t_vars *vars)
{
	free_env(env);
	free_vars(vars);
}

