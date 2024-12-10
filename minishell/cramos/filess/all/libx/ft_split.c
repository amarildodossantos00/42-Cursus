#include "libx.h"
int	deli(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char    **ft_split(char *str)
{
	int x;
	int y = 0;
	int l = 0;
	char **m;

	while (*str && deli(*str))
		str++;
	while (str[l])
		l++;
	m = malloc(sizeof(char *) * (l + 1));
	while (*str)
	{
		x = 0;
		m[y] = malloc(sizeof(char *) * (l + 1));
		while (*str && !deli(*str))
			m[y][x++] = *(str++);
		while (*str && deli(*str))
			str++;
		m[y++][x] = '\0';
	}
	m[y] = NULL;
	return (m);
}
