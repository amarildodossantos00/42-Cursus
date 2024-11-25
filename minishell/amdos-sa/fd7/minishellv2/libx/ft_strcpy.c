#include "libx.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*dest_ptr;

	dest_ptr = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest_ptr);
}
