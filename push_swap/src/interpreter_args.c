/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 08:10:52 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/04 09:16:26 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pswap.h"

static	void	process_arguments(char *arg, t_stack **s_a)
{
	char	**aux;
	int		j;
	int		value;

	aux = ft_split(arg);
	if (!aux || aux[0] == NULL)
	{
		free_stack(s_a);
		free_str(aux);
		ft_error();
	}
	j = 0;
	while (aux[j])
	{
		if (!check_is_number(aux[j]))
		{
			free_stack(s_a);
			free_str(aux);
			ft_error();
		}
		value = ft_atoi(aux[j], &s_a, &aux);
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
