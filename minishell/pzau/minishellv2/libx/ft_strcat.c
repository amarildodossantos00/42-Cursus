#include "libx.h"

static int	ft_strlen3(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strcat(char *s1, const char *s2)
{
    char *result;
    size_t len1;
    size_t len2;
    size_t total_len;

    len1 = ft_strlen3(s1);
    len2 = ft_strlen3(s2);
    total_len = len1 + len2 + 1;
    result = malloc(total_len);
    if (!result)
        return NULL;
    size_t i = 0;
    while (i < len1)
    {
        result[i] = s1[i];
        i++;
    }
    size_t j = 0;
    while (j < len2)
    {
        result[i] = s2[j];
        i++;
        j++;
    }
    result[i] = '\0';
    return result;
}
