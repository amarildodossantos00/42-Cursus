/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:13:50 by cramos            #+#    #+#             */
/*   Updated: 2024/06/17 17:13:56 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_c(char word, size_t *i)
{
	write(1, &word, 1);
	(*i)++;
}

void	write_d(int n, size_t *i)
{
	if (n == -2147483648)
	{
		write_d((n / 10), i);
		write_c('8', i);
	}
	else if (n < 0)
	{
		write_c('-', i);
		write_d(-n, i);
	}	
	else
	{
		if (n > 9)
			write_d((n / 10), i);
		write_c(('0' + n % 10), i);
	}
}

void	write_p(void *ptr, size_t *i)
{
	unsigned long	p;
	char			*str;

	if (ptr == NULL)
	{
		write_s("(nil)", i);
		return ;
	}
	p = (unsigned long)ptr;
	write_s("0x", i);
	str = auxilary_func(p, HEL_LOW_BASE);
	write_s(str, i);
	free(str);
}

void	write_s(const char *str, size_t *i)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		write_c(*str, i);
		str++;
	}
}

void	write_u(unsigned int n, size_t *i)
{
	char	*str;

	str = auxilary_func(n, "0123456789");
	write_s(str, i);
	free(str);
}
