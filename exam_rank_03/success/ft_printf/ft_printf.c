#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void 	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putstr(char *s, int *count)
{
	if (!s)
		s = "(null)";
	while(*s)
		ft_putchar(*s++, count);
}

void	ft_putnbr(long n, int *count)
{
	if (n < 0)
	{
		ft_putchar('-', count);
		n = -n;
		ft_putnbr(n, count);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, count);
		ft_putnbr(n % 10, count);
	}
	else
		ft_putchar(n + 48, count);
}

void	ft_print_hexa(long nbr, int *count)
{
	char 	*base;

	base = "0123456789abcdef";
	if (nbr > 15)
		ft_print_hexa(nbr / 16, count);
	ft_putchar(base[nbr % 16], count);
}

int ft_printf(char *format, ...)
{
	va_list	args;
	int 	count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if ((*format == '%') && ((*(format + 1) == 's') 
			|| (*(format + 1) == 'd') || (*(format + 1) == 'x')))
		{
			format++;
			if (*format == 'd')
				ft_putnbr(((long)va_arg(args, int)), &count);
			else if (*format == 's')
				ft_putstr((va_arg(args, char *)), &count);
			else if (*format == 'x')
				ft_print_hexa((long)va_arg(args, unsigned int), &count);
		}
		else
			ft_putchar(*format, &count);
		format++;
	}
	va_end(args);
	return(count);
}
