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

static void     eating_action(t_philo *philo)
{
    printf("[%ld]ms philo %d have eaten\n", current_time() - philo->time_init, philo->id);
    philo->p_vars->philo_eat_cont++;
}

void    print_all_messagers(t_philo *philo, int n)
{
    pthread_mutex_lock(&philo->p_vars->all_mutexs.mutex_on_routine);
    if (!philo->p_vars->on_routine)
    {
        pthread_mutex_unlock(&philo->p_vars->all_mutexs.mutex_on_routine);
        return ;
    }
    pthread_mutex_unlock(&philo->p_vars->all_mutexs.mutex_on_routine);
    pthread_mutex_lock(&philo->p_vars->all_mutexs.mutex_print_sms);
    if (n == EAT)
        eating_action(philo);
    else if (n == SLEEP)
        printf("[%ld]ms philo %d is sleeping\n", current_time() - philo->time_init, philo->id);
    else if (n == THINK)
        printf("[%ld]ms philo %d is thinking\n", current_time() - philo->time_init, philo->id);
    else if (n == DEAD)
        printf("[%ld]ms philo %d died\n", current_time() - philo->time_init, philo->id);
    else if (n == FORK)
        printf("[%ld]ms philo %d take a fork\n", current_time() - philo->time_init, philo->id);
    pthread_mutex_unlock(&philo->p_vars->all_mutexs.mutex_print_sms);
}

static void     print_forks(t_philo *philo)
{
    if ((philo->id % 2) == 0)
    {
        usleep(1000);
        pthread_mutex_lock(philo->left);
        print_all_messagers(philo, FORK);
        pthread_mutex_lock(philo->right);
        print_all_messagers(philo, FORK);
    }
    else
    {
        pthread_mutex_lock(philo->right);
        print_all_messagers(philo, FORK);
        pthread_mutex_lock(philo->left);
        print_all_messagers(philo, FORK);
    }
}

static void     running_messagers(t_philo *philo)
{
    print_forks(philo);
    pthread_mutex_lock(&philo->p_vars->all_mutexs.mutex_last_eat);
    philo->time_last = current_time();
    pthread_mutex_unlock(&philo->p_vars->all_mutexs.mutex_last_eat);
    print_all_messagers(philo, EAT);
    usleep(philo->p_vars->time_eat * 1000);
    pthread_mutex_unlock(philo->right);
    pthread_mutex_unlock(philo->left);
    usleep(philo->p_vars->time_sleep * 1000);
    print_all_messagers(philo, SLEEP);
    print_all_messagers(philo, THINK);
}

void    *philos_action(void *param)
{
    t_philo     *philo;

    philo = (t_philo *)param;
    while (1)
    {
        pthread_mutex_lock(&philo->p_vars->all_mutexs.mutex_on_routine);
        if (philo->p_vars->on_routine != 1)
        {
            pthread_mutex_unlock(&philo->p_vars->all_mutexs.mutex_on_routine);
            break ;
        }
        pthread_mutex_unlock(&philo->p_vars->all_mutexs.mutex_on_routine);
        //function for only one philosopher (put inside of a if and return one to break)
        pthread_mutex_unlock(&philo->p_vars->all_mutexs.mutex_on_routine);
        running_messagers(philo);
        pthread_mutex_unlock(&philo->p_vars->all_mutexs.mutex_on_routine);
    }
}
