#include "libx.h"

char	*sncat(char *dest, const char *src, size_t n)
{
	char	*original_dest;

	original_dest = dest;
	while (*dest)
		dest++;
	while (n-- > 0 && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (original_dest);
}
