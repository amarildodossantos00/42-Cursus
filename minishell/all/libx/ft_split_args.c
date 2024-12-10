#include "libx.h"

int ft_strlen2(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


static void	handle_quotes(const char **s)
{
	if (**s == '\'')
	{
		(*s)++;
		while (**s != '\'')
			(*s)++;
	}
	if (**s == '\"')
	{
		(*s)++;
		while (**s != '\"')
			(*s)++;
	}
}
int	ft_count_args(const char *s)
{
	int	count;
	count = 0;
	while (*s)
	{
		while (*s == 32)
			++s;
		while (*s > 32 && *s < 127)
		{
			handle_quotes(&s);
			++s;
		}
		count++;
	}
	return (count);
}

static void	handle_quote(const char **s, int *point)
{
	if (**s == '\'')
	{
		(*s)++;
		(*point)++;
		while (**s != '\'')
		{
			(*s)++;
			(*point)++;
		}
	}
	if (**s == '\"')
	{
		(*s)++;
		(*point)++;
		while (**s != '\"')
		{
			(*s)++;
			(*point)++;
		}
	}
}

static int	ft_next_point(const char *s)
{
	int	point;

	point = 0;
	while (*s)
	{
		while (*s == 32)
			++s;
		while (*s > 32 && *s < 127)
		{
			handle_quote(&s, &point);
			++s;
			++point;
		}
		if (*s == 32)
			return (point);
	}
	return (point);
}

char	**ft_split_args(char *str)
{
	t_split_token	t;

	t.i = 0;
	t.j = 0;
	t.size = ft_count_args(str);
	t.mtx = (char **)malloc(sizeof(char *) * (t.size + 1));
	while (t.j < t.size)
	{
		t.point = ft_next_point(str);
		t.tmp = ft_substr(str, 0, t.point);
		t.mtx[t.i++] = ft_strtrim(t.tmp, " ");
		str += t.point;
		str++;
		t.j++;
		free(t.tmp);
	}
	t.mtx[t.i] = NULL;
	return (t.mtx);
}