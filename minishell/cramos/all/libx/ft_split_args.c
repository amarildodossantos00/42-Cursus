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


size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen2(src));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	slen;
	size_t	sub;
	if (!s)
		return (0);
	slen = ft_strlen2(s);
	sub = 0;
	if (start < slen)
		sub = slen - start;
	if (sub > len)
		sub = len;
	new = (char *)malloc(sizeof(char) * (sub + 1));
	if (!new)
		return (0);
	ft_strlcpy(new, s + start, sub + 1);
	return (new);
}

static int	ft_check_set(char const c, char const *set)
{
	int	i;
	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;
	char	*new;
	if (!s1 || !set)
		return (NULL);
	while (s1)
	{
		if (ft_check_set(((char)*s1), set))
			s1++;
		else
			break ;
	}
	size = ft_strlen2(s1);
	while (size != 0)
	{
		if (ft_check_set(s1[size - 1], set))
			size--;
		else
			break ;
	}
	new = (char *)malloc(size * sizeof(char) + 1);
	if (!new)
		return (NULL);
	ft_strlcpy(new, (char *)s1, size + 1);
	return (new);
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