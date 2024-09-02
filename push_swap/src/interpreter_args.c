/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 08:10:52 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/02 06:33:53 by amdos-sa         ###   ########.fr       */
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

t_stack	*interpreter_two_args(char **av)
{
	t_stack	*s_a;
	char	**aux;
	int		i;
	int		j;

	s_a = NULL;
	i = 0;
	aux = ft_split(av[1], 32);
	while (aux[i])
	{
		j = ft_atoi2(aux[i]);
		ft_add_back(&s_a, ft_stack_new(j));
		i++;
	}
	free_str(aux);
	free(aux);
	return (s_a);
}

t_stack	*interpreter_args(int ac, char **av)
{
	t_stack	*s_a;
	int		i;
	int		j;

	i = 1;
	s_a = NULL;
	if (ac < 2)
		ft_error();
	if (ac == 2)
		s_a = interpreter_two_args(av);
	else
	{
		while (i < ac)
		{
			j = ft_atoi2(av[i]);
			ft_add_back(&s_a, ft_stack_new(j));
			i++;
		}
	}
	return (s_a);
}
