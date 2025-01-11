#include "libx.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	srcsize;
	size_t	destsize;

	if (!dest || !src)
		return (0);
	srcsize = ft_strlen(src);
	destsize = ft_strlen(dest);
	if (size < destsize)
		return (srcsize + size);
	else
	{
		dest = dest + destsize;
		ft_strlcpy(dest, src, size - destsize);
		return (srcsize + destsize);
	}
}
