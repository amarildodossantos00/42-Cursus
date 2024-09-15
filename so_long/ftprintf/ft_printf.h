/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:20:26 by cramos            #+#    #+#             */
/*   Updated: 2024/06/17 17:20:38 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# define HEL_UPP_BASE "0123456789ABCDEF"
# define HEL_LOW_BASE "0123456789abcdef"

int		ft_printf(const char *str, ...);
void	write_c(char word, size_t *i);
void	write_d(int n, size_t *i);
void	write_p(void *ptr, size_t *i);
void	write_s(const char *str, size_t *i);
void	write_u(unsigned int n, size_t *i);
void	write_x(unsigned int n, size_t *i, char *base);
void	write_xx(unsigned int n, size_t *i, char *base);
char	*auxilary_func(unsigned long long n, char *base);

#endif
