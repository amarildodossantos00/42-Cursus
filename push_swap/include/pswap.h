/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:07:13 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/08/23 03:10:16 by amdos-sa         ###   ########.fr       */
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

void	sa(t_stack **s_a, int f);
void	pa(t_stack **s_a, t_stack **s_b);
void	ra(t_stack **s_a, int f);
void	rra(t_stack **s_a, int f);
void	sb(t_stack **s_b, int f);
void	pb(t_stack **s_a, t_stack **s_b);
void	rb(t_stack **s_b, int f);
void	rrb(t_stack **s_b, int f);
void	ss(t_stack **s_a, t_stack **s_b);
void	rr(t_stack **s_a, t_stack **s_b);
void	rrr(t_stack **s_a, t_stack **s_b);
void	_creat_stack(t_stack **stack);
void	exit_error(char **matrix);
void	ft_error(void);
void	print_stack(t_stack *stack);
void	free_stack(t_stack *stack);
void	ft_start(char **matrix);
int		check_order(t_stack *stack);
int		ft_strlen(char **str);
int		ft_isdigit(int c);
int		ft_atoi(char *str);
int		check_digit(char *str);
int		ft_printf(const char *str, ...);
void	_push(t_stack **stack, int value);

#endif
