/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:12:13 by pzau              #+#    #+#             */
/*   Updated: 2024/10/10 13:05:23 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_vars	t_vars;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	long			time_init;
	long			time_last;
	long				time_eat_cont;
	int				death_occurred;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	t_vars			*p_vars;
}	t_philo;

typedef struct s_vars
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_philo_aux;
	int				on_routine;
	t_philo			*philosophers;
	pthread_mutex_t	*forks;
}	t_vars;

void	ft_initialize_args(int ac, char **av, t_vars *vars);
void	*philos_action(void *param);
void	ft_dispose_all(t_vars *vars);
void	initial_aux(t_vars *vars);
void	*monitor_philo(void *arg);
int		ft_initialize_rest(t_vars *vars, int i);
int		ft_check_error(int ac, char **av);
int		ft_atoi(char *str);
int		is_digit(char str);
long	get_timestamp(void);
long	get_elapsed_time(long start_time);

#endif
