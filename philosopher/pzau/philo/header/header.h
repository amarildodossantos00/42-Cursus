/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:12:13 by pzau              #+#    #+#             */
/*   Updated: 2024/10/04 17:42:25 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h> 
# include <stdlib.h>
# include <pthread.h>

typedef struct s_vars t_vars;

typedef struct s_philo
{
    int     id;
    pthread_t    thread;
    size_t      time_init;
    size_t      time_last;
    int         time_eat_cont;
    pthread_mutex_t *left;
    pthread_mutex_t *right;
    t_vars      *p_vars;
}   t_philo;

typedef struct s_vars
{
    int     num_philo;
    int     time_die;
    int     time_eat;
    int     time_sleep;
    int     num_philo_aux;
    int     on_routine;
    t_philo *philosophers;
    pthread_mutex_t *forks;
}   t_vars;

void    ft_initialize_args(int ac, char **av, t_vars *vars);
void    *philos_action(void *param);
int     ft_initialize_rest(t_vars vars);
int	    ft_check_error(int ac, char **av);
int     ft_strlen(char *str);
int     ft_atoi(char *str);

#endif
