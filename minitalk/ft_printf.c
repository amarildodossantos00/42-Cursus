/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:06:04 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/05/31 18:06:06 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

static void	handle_specifier(const char *format, va_list args, size_t *i)
{
	if (*format == 'c')
		write_c(va_arg(args, int), i);
	else if (*format == 'd' || *format == 'i')
		write_d(va_arg(args, int), i);
	else if (*format == '%')
		write_c(*format, i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;

	i = 0;
	if (!format)
		return (0);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			handle_specifier((char *)format, args, &i);
		}
		else
		{
			write_c(*format, &i);
		}
		format++;
	}
	va_end(args);
	return (i);
}
