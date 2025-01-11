#include "libx.h"

int	ft_strnfill(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	if (!dest || !src)
		return (0);
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (i);
}
