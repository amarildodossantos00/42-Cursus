/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 08:10:52 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/03 09:33:51 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pswap.h"

int	ft_atoi2(const char *str)
{
	int				mod;
	long long int	i;

	i = 0;
	mod = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		mod = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483647)
		ft_error();
	return (mod * i);
}

static	void	process_arguments(char *arg, t_stack **s_a)
{
	char	**aux;
	int		j;
	int		value;

	aux = ft_split(arg, ' ');
	if (!aux || aux[0] == NULL)
	{
		free_str(aux);
		ft_error();
	}
	j = 0;
	while (aux[j])
	{
		if (!check_is_number(aux[j]))
		{
			free_str(aux);
			free_stack(s_a);
			ft_error();
		}
		value = ft_atoi2(aux[j]);
		ft_add_back(s_a, ft_stack_new(value));
		j++;
	}
	free_str(aux);
}

t_stack	*interpreter_args(int ac, char **av)
{
	t_stack	*s_a;
	int		i;

	i = 1;
	s_a = NULL;
	if (ac < 2)
		exit(0);
	while (i < ac)
	{
		process_arguments(av[i], &s_a);
		i++;
	}
	return (s_a);
}
