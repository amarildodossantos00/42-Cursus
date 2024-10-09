/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:29:13 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/10/08 14:41:28 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

void	initial_aux(t_vars *vars)
{
	vars->philosophers = malloc(sizeof(t_philo) * (vars->num_philo));
	vars->forks = malloc(sizeof(pthread_mutex_t) * (vars->num_philo));
	return ;
}
