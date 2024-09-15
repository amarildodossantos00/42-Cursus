/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:55:33 by cramos            #+#    #+#             */
/*   Updated: 2024/06/17 16:55:36 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_specifier(const char *format, va_list args, size_t *i)
{
	if (*format == 'c')
		write_c(va_arg(args, int), i);
	else if (*format == 's')
		write_s(va_arg(args, char *), i);
	else if (*format == 'p')
		write_p(va_arg(args, void *), i);
	else if (*format == 'd' || *format == 'i')
		write_d(va_arg(args, int), i);
	else if (*format == 'u')
		write_u(va_arg(args, unsigned int), i);
	else if (*format == 'x')
		write_x(va_arg(args, unsigned int), i, HEL_LOW_BASE);
	else if (*format == 'X')
		write_xx(va_arg(args, unsigned int), i, HEL_UPP_BASE);
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

void	write_x(unsigned int n, size_t *i, char *base)
{
	char	*str;

	str = auxilary_func(n, base);
	write_s(str, i);
	free(str);
}

void	write_xx(unsigned int n, size_t *i, char *base)
{
	char	*str;

	str = auxilary_func(n, base);
	write_s(str, i);
	free(str);
}
