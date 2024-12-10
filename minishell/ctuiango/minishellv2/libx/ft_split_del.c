#include "libx.h"

static int deli(char c, const char *delimiters)
{
    while (*delimiters)
    {
        if (c == *delimiters)
            return 1;
        delimiters++;
    }
    return 0;
}

char **ft_split_del(char *str, const char *delimiters)
{
	int x;
	int y = 0;
	int l = 0;
	char **m;

	while (*str && deli(*str, delimiters))
		str++;
	while (str[l])
		l++;
	m = malloc(sizeof(char *) * (l + 1));
	if (!m)
		return NULL;
	while (*str)
	{
		x = 0;
		m[y] = malloc(sizeof(char) * (l + 1));
		if (!m[y])
			return NULL;
		while (*str && !deli(*str, delimiters))
			m[y][x++] = *(str++);
		while (*str && deli(*str, delimiters))
			str++;
		m[y][x] = '\0';
		y++;
	}
	m[y] = NULL;
	return m;
}
