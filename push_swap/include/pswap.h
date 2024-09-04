/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:07:13 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/04 09:16:43 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWAP_H
# define PSWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

void	ft_sa(t_stack **s_a, int f);
void	ft_pa(t_stack **s_a, t_stack **s_b, int j);
void	ft_ra(t_stack **s_a, int f);
void	ft_rra(t_stack **s_a, int f);
void	ft_sb(t_stack **s_b, int f);
void	ft_pb(t_stack **s_a, t_stack **s_b, int j);
void	ft_rb(t_stack **s_b, int f);
void	ft_rrb(t_stack **s_b, int f);
void	ft_ss(t_stack **s_a, t_stack **s_b, int j);
void	ft_rr(t_stack **s_a, t_stack **s_b, int j);
void	ft_rrr(t_stack **s_a, t_stack **s_b, int j);
void	ft_error(void);
void	free_stack(t_stack **stack);
void	ft_add_back(t_stack **stack, t_stack *stack_new);
void	free_str(char **matrix);
void	algorithm(t_stack **s_a);
char	**ft_split(char *str);
int		find_place_a(t_stack *s_a, int pnum);
int		find_place_b(t_stack *s_b, int pnum);
int		find_index(t_stack *s_a, int num);
int		apply_rarb(t_stack **a, t_stack **b, int c, char s);
int		apply_rrarrb(t_stack **a, t_stack **b, int c, char s);
int		apply_rrarb(t_stack **a, t_stack **b, int c, char s);
int		apply_rarrb(t_stack **a, t_stack **b, int c, char s);
int		rotate_type_ba(t_stack *s_a, t_stack *s_b);
int		rotate_type_ab(t_stack *s_a, t_stack *s_b);
int		case_rrarb_a(t_stack *a, t_stack *b, int c);
int		case_rarrb_a(t_stack *a, t_stack *b, int c);
int		case_rrarrb_a(t_stack *a, t_stack *b, int c);
int		case_rarb_a(t_stack *a, t_stack *b, int c);
int		case_rarrb(t_stack *a, t_stack *b, int c);
int		case_rrarb(t_stack *a, t_stack *b, int c);
int		case_rrarrb(t_stack *a, t_stack *b, int c);
int		case_rarb(t_stack *s_a, t_stack *s_b, int c);
int		lst_size(t_stack *stack);
int		lst_min(t_stack *stack);
int		lst_max(t_stack *stack);
int		find_index(t_stack *s_a, int num);
int		check_order(t_stack *stack);
int		check_double_number(t_stack *stack);
int		ft_isdigit(int c);
int		ft_atoi(const char *str, t_stack ***stack, char ***matrix);
int		check_is_number(char *str);
int		ft_printf(const char *str, ...);
size_t	ft_strlen(char *str);
t_stack	*lst_last(t_stack *stack);
t_stack	*interpreter_args(int ac, char **av);
t_stack	*ft_stack_new(int content);

#endif
