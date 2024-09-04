/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 06:28:09 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/04 09:33:34 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pswap.h"

static void	check_digit_and_free(const char *str, t_stack ***s_a,
	char ***matrix)
{
	if (!ft_isdigit(*str))
	{
		if (matrix)
			free_str(*matrix);
		free_stack(*s_a);
		ft_error();
	}
}

static void	handle_overflow(long long int i, int mod,
	t_stack ***s_a, char ***matrix)
{
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
	{
		if (matrix)
			free_str(*matrix);
		free_stack(*s_a);
		ft_error();
	}
}

static void	skip_whitespace_and_sign(const char **str, int *mod)
{
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str)++;
	if (**str == '-')
	{
		*mod = -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
}

int	ft_atoi(const char *str, t_stack ***s_a, char ***matrix)
{
	int				mod;
	long long int	i;

	i = 0;
	mod = 1;
	skip_whitespace_and_sign(&str, &mod);
	while (*str)
	{
		check_digit_and_free(str, s_a, matrix);
		i = i * 10 + (*str - '0');
		str++;
	}
	handle_overflow(i, mod, s_a, matrix);
	return (mod * i);
}
