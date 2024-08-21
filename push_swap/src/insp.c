/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhabacuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:03:37 by lhabacuc          #+#    #+#             */
/*   Updated: 2024/07/05 14:03:38 by lhabacuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

# define MAX_INT_VALUE 2147483647
# define MIN_INT_VALUE -2147483648

typedef struct s_stack
{
	struct s_stack	*next;
	int				data;
	int				index;
}	t_stack;

void	print_stack(t_stack *node);

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	sa(t_stack **a)
{
	t_stack	*temp;

	if (!a || !*a || !(*a)->next)
		return ;
	temp = (*a)->next;
	(*a)->next = temp->next;
	temp->next = *a;
	*a = temp;
	ft_putstr("sa\n");
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!b || !*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	ft_putstr("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!a || !*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	ft_putstr("pb\n");
}

void	ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	first->next = NULL;
	last->next = first;
	ft_putstr("ra\n");
}

void	rra(t_stack **a)
{
	t_stack	*prev;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	prev = NULL;
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
	ft_putstr("rra\n");
}

void	ft_print_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		printf(" > [%s] ", matrix[i]);
		i++;
	}
	printf("\n");
}

void	free_matrix(char **matriz)
{
	int	i;

	i = 0;

	if (matriz != NULL)
	{
		while (matriz[i])
		{
			free(matriz[i]);
			i++;
		}
		free(matriz);
	}
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	exit_error(char **matriz)
{
	free_matrix(matriz);
	ft_putstr("Error\n");
	exit(0);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	valor_null(char *p)
{
	return (*p != '\0');
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
		if (!(*str >= '0' && *str <= '9'))
			exit_error(NULL);
	}
	while (*str >= '0' && *str <= '9')
	{
		if (result > (MAX_INT_VALUE - (*str - '0')) / 10)
			return (MAX_INT_VALUE);
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	check_duplicates(char **av, int p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		if (!is_number(av[i]) || !valor_null(av[i]))
			exit_error(NULL);
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
			{
				if (p)
					exit_error(av);
				exit_error(NULL);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	three_sort(t_stack **a)
{
	if ((*a)->data > (*a)->next->data && (*a)->next->data
		< (*a)->next->next->data && (*a)->data < (*a)->next->next->data)
		sa(a);
	else if ((*a)->data > (*a)->next->data
		&& (*a)->next->data > (*a)->next->next->data)
	{
		sa(a);
		rra(a);
	}
	else if ((*a)->data > (*a)->next->data
		&& (*a)->next->data < (*a)->next->next->data)
		ra(a);
	else if ((*a)->data < (*a)->next->data && (*a)->next->data
		> (*a)->next->next->data && (*a)->data > (*a)->next->next->data)
		rra(a);
	else if ((*a)->data < (*a)->next->data
		&& (*a)->next->data > (*a)->next->next->data)
	{
		sa(a);
		ra(a);
	}
}

void	small_stack(t_stack **a, t_stack **b)
{
	if (!a || !*a)
		return ;
	if (stack_size(*a) == 2)
	{
		if ((*a)->data > (*a)->next->data)
			sa(a);
	}
	else if (stack_size(*a) == 3)
		three_sort(a);
}

int	ver_limit(char **av, int p)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_atoi(av[i]) == MAX_INT_VALUE)
		{
			if (p)
				exit_error(av);
			exit_error(NULL);
		}
		i++;
	}
	return (0);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	small(t_stack *a)
{
	t_stack	*tmp;
	int		min;

	tmp = a;
	min = tmp->data;
	while (tmp)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

int	find_min(t_stack *a)
{
	t_stack	*tmp;
	int		pos_min;
	int		min;

	tmp = a;
	min = small(a);
	pos_min = 0;
	while (tmp)
	{
		if (tmp->data == min)
			break ;
		pos_min++;
		tmp = tmp->next;
	}
	return (pos_min);
}

void	put_min_to_top(t_stack **a)
{
	int	min_pos;
	int	size;

	size = stack_size(*a);
	min_pos = find_min(*a);
	if (min_pos < stack_size(*a) / 2)
	{
		while (min_pos)
		{
			ra(a);
			min_pos--;
		}
	}
	else if (min_pos >= stack_size(*a) / 2)
	{
		while (min_pos != stack_size(*a))
		{
			rra(a);
			min_pos++;
		}
	}
}

void	sort4(t_stack **a, t_stack **b)
{
	put_min_to_top(a);
	pb(a, b);
	three_sort(a);
	pa(a, b);
	if ((*a)->data > (*a)->next->data)
		sa(a);
	while (*b)
		pa(a, b);
}

void	five_sort(t_stack **a, t_stack **b)
{
	put_min_to_top(a);
	pb(a, b);
	put_min_to_top(a);
	pb(a, b);
	three_sort(a);
	pa(a, b);
	pa(a, b);
}

void    assign_index(t_stack *stack);
int	find_max_bits(t_stack *stack)
{
	int	max;
	int	bits;

	max = 0;
	bits = 0;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	assign_index(t_stack *stack)
{
	t_stack		*current;
	t_stack		*compare;
	int			index;

	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (current->data > compare->data)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;

	size = stack_size(*a);
	max_bits = find_max_bits(*a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}

void	init_stack_valu(t_stack **a, int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node->data = value;
	new_node->next = *a;
	*a = new_node;
}

void	init(char **av, int i, int len)
{
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	while (av[len])
		len++;
	len--;
	i = len;
	while (len >= 0)
	{
		init_stack_valu(&a, ft_atoi(av[len]));
		len--;
	}
	i++;
	assign_index(a);
	if (is_sorted(a) == 0)
	{
		free_stack(a);
		return ;
	}
	if (i == 1)
	{
		free_stack(a);
		return ;
	}
	if (i == 2)
		small_stack(&a, &b);
	else if (i == 3)
		three_sort(&a);
	else if (i == 5)
		five_sort(&a, &b);
	else if (i == 4)
		sort4(&a, &b);
	else if (i > 5)
		sort_stack(&a, &b);
	free_stack(b);
	free_stack(a);
}

int	process_arg(char **av, int p)
{
	check_duplicates(av, p);
	ver_limit(av, p);
	init(av, 0, 0);
	return (0);
}

int	is_space(char *c)
{
	int	j;
	
	j = 0;
	while ((c[j] >= 32 && c[j] <= 47) || (c[j] == '\t'))
		j++;
	return (c[j] == '\0');
}

void	is_digit_validate(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if(s[i] == ' ')
			i++;
		if (((s[i] == '-' || s[i] == '+') &&
			(s[i + 1] == '-' || s[i + 1] == '+')) && s[i] != ' ')
			exit_error(NULL);
		if(s[i] == ' ')
			i++;
		i++;
	}
}

int	check_string(const char *str)
{
	int	i;

	i = 0;
	is_digit_validate(str);
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '-' || str[i] == '+')
			i++;
		if (!(str[i] >= '0' && str[i] <= '9') && (str[i] != '+' || str[i] != '-'))
			exit_error(NULL);
		if ((str[i] >= '0' && str[i] <= '9'))
		{
			if (str[i + 1] == '+' || str[i + 1] == '-')
				exit_error(NULL);
		}
		i++;
	}
	return (1);
}

char	**ft_split(char *str, int i, int j, int l)
{
	char		**split;
	int			k;

	while (str[l] != '\0')
		l++;
	split = malloc(sizeof(char *) * (l + 1));
	if (!split || !str)
		return (NULL);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		k = 0;
		split[j] = malloc(sizeof(char) * (l + 1));
		if (!split[j])
			return (NULL);
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
			split[j][k++] = str[i++];
		split[j++][k] = '\0';
		while (str[i] == ' ' || str[i] == '\t')
			i++;
	}
	split[j] = NULL;
	return (split);
}

int	main(int arc, char **av)
{
	char		**mat;

	if (arc == 2)
	{
		if (check_string(av[1]) == 0)
			return (0);
		if (!valor_null(av[1]) || is_space(av[1]))
			exit_error(NULL);
		mat = ft_split(av[1], 0, 0, 0);
		process_arg(mat, 1);
		free_matrix(mat);
	}
	else if (arc > 2)
		process_arg(av + 1, 0);
	return (0);
}
