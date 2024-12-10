#include "libx.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int	len1;
	int	len2;
	char	*result;

	if (!s1 || !s2) return NULL;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc(len1 + len2 + 1);
	if (!result) return NULL;
	ft_strcpy(result, s1);
	ft_strcpy(result + len1, s2);
	return result;
}
