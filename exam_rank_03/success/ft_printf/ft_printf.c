/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:21:18 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/18 14:38:41 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putstr(char *str, int *count)
{
	if (!str)
		str = "(null)";
	while (*str)
		ft_putchar(*str++, count);
}

void	ft_putnbr(long num, int *count)
{
	if (num < 0)
	{
		ft_putchar('-', count);
		num = -num;
		ft_putnbr(num, count);
	}
	else if (num > 9)
	{
		ft_putnbr(num / 10, count);
		ft_putnbr(num % 10, count);
	}
	else
		ft_putchar(num + '0', count);
}

void	ft_print_hexa(long num, int *count)
{
	char *base;

	base = "0123456789abcdef";
	if (num > 15)
		ft_print_hexa(num / 16, count);
	ft_putchar(base[num % 16], count);
}

int	ft_printf(char *format, ...)
{
	va_list	args;
	int	count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if ((*format == '%') && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
		{
			format++;
			if (*format == 's')
				ft_putstr(va_arg(args, char *), &count);
			else if (*format == 'd')
				ft_putnbr((long)va_arg(args, int), &count);
			else if (*format == 'x')
				ft_print_hexa((long)va_arg(args, unsigned int), &count);
		}
		else
			ft_putchar(*format, &count);
		format++;
	}
	va_end(args);
	return (count);
}

/*int	main(void)
{
	ft_printf("%s\n", "toto");
	ft_printf("Magic %s is %d\n", "number", 42);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);

	return (0);
}*/
