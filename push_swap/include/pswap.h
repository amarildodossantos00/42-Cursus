/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:07:13 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/08/21 12:56:12 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWAP_H
# define PSWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define MAX_INT_VALUE 2147483647
# define MIN_INT_VALUE -2147483647

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

void	_creat_stack(t_stack *stack);
void	exit_error(char **matrix);
void	free_stack(t_stack *stack);
int		check_order(t_stack *stack);
int		ft_strlen(char *str);
int		ft_isdigit(int c);
int		ft_atoi(char *str);
int		check_digit(char *str);
int		ft_printf(const char *str, ...);
void	_push(t_stack *stack, int value);
t_stack	*_pop(t_stack *stack);

#endif
