#include "libx.h"

char	*ft_strdup(char *src)
{
	int	len;
	char	*str;

	len = 0;
	while (src[len])
		len++;
	str = malloc(sizeof(char) * (len + 1));
	len = 0;
	while (src[len])
	{
		str[len] = src[len];
		len++;
	}
	str[len] = '\0';
	return (str);
}