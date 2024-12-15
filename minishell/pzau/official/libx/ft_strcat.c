#include "libx.h"

static int	ft_strlen3(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_allocate_result(size_t total_len)
{
	char	*result;

	result = malloc(total_len);
	if (!result)
		return (NULL);
	return (result);
}

static void	ft_copy_s1_to_result(char *result, const char *s1, size_t len1)
{
	size_t	i;

	i = 0;
	while (i < len1)
	{
		result[i] = s1[i];
		i++;
	}
}

static void	ftcopys2(char *result, const char *s2, size_t len2, size_t offset)
{
	size_t	j;

	j = 0;
	while (j < len2)
	{
		result[offset + j] = s2[j];
		j++;
	}
}

char	*ft_strcat(char *s1, const char *s2)
{
	char		*result;
	size_t		len1;
	size_t		len2;
	size_t		total_len;

	len1 = ft_strlen3(s1);
	len2 = ft_strlen3(s2);
	total_len = len1 + len2 + 1;
	result = ft_allocate_result(total_len);
	if (!result)
		return (NULL);
	ft_copy_s1_to_result(result, s1, len1);
	ftcopys2(result, s2, len2, len1);
	result[len1 + len2] = '\0';
	return (result);
}
