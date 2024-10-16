/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:46:56 by ctuiango          #+#    #+#             */
/*   Updated: 2024/10/16 13:47:04 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define EAT 1
# define SLEEP 2
# define THINK 3
# define DEAD 4
# define FORK 5

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_vars	t_vars;

typedef struct s_all_mutexs
{
	pthread_mutex_t	mutex_last_eat;
	pthread_mutex_t	mutex_on_routine;
	pthread_mutex_t	mutex_print_sms;
	pthread_mutex_t	mutex_one;
	pthread_mutex_t	mutex_have_eaten;
}	t_all_mutexs;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	size_t			time_init;
	size_t			time_last;
	int				eat_cont;
	int				meals_eaten;
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
	int				*all_eat;
	int				on_routine;
	t_philo			*philosophers;
	t_all_mutexs	all_mutexs;
	pthread_mutex_t	*forks;
	pthread_t		monitoring;
}	t_vars;

void	ft_initialize_args(int ac, char **av, t_vars *vars);
void	one_philosopher(t_philo *philo);
void	print_all_messagers(t_philo *philo, int n);
void	*philo_monitoring(void *param);
void	*philos_action(void *param);
void	ft_dispose_all(t_vars *vars);
void	print_forks(t_philo *philo);
int		ft_initialize_rest(t_vars *vars, int i);
int		ft_check_error(int ac, char **av);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
long	current_time(void);

#endif
