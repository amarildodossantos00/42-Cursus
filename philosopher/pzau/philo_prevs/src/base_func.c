/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 10:12:40 by pzau              #+#    #+#             */
/*   Updated: 2024/10/05 10:12:42 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

void    *philos_action(void *param)
{
    t_philo     *philo;

    philo = (t_philo *)param;
    printf("O filosofo %d esta ativo\n", philo->id);
}
