#include "libx.h"

char	*ft_strstr(char *haystack, char *needle)
{
	char	*h;
	char	*n;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			h = haystack;
			n = needle;
			while (*n && *h == *n)
			{
				h++;
				n++;
			}
			if (*n == '\0')
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
