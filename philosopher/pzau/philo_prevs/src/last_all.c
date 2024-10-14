/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:50:33 by pzau              #+#    #+#             */
/*   Updated: 2024/10/07 15:50:40 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

void   ft_dispose_all(t_vars *vars)
{
    int     i;

    i = 0;
    while (i < vars->num_philo)
    {
        if (pthread_join(vars->philosophers[i].thread, NULL) != 0)
            printf("Falhou!\n");
        i++;
    }
    i = 0;
    while (i < vars->num_philo)
    {
        pthread_mutex_destroy(&vars->forks[i]);
        i++;
    }
    free(vars->philosophers);
    free(vars->forks);
}
