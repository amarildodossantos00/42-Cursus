#include "libx.h"

static int	red_deli(char c)
{
	return (c == '>' || c == '<');
}

char	**ft_split_red(char *str)
{
	int		x;
	int		y;
	int		l;
	char	**m;

	y = 0;
	l = 0;
	while (*str && red_deli(*str))
		str++;
	while (str[l])
		l++;
	m = malloc(sizeof(char *) * (l + 1));
	while (*str)
	{
		x = 0;
		m[y] = malloc(sizeof(char *) * (l + 1));
		while (*str && !red_deli(*str))
			m[y][x++] = *(str++);
		while (*str && red_deli(*str))
			str++;
		m[y++][x] = '\0';
	}
	m[y] = NULL;
	return (m);
}
