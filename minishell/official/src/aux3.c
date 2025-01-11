#include "../header/header.h"

int	is_special(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

int	is_delimiter(char c)
{
	return (c == ' ' || c == '\t' || c == '\0');
}

char	*ft_var_name(char *str, int n)
{
	char	*res;
	int		i;
	int		len;

	i = n;
	len = 0;
	if (str[n + 1] == '?')
		len++;
	if (!is_special(str[n]) && (isalnum(str[n + 1]) \
	|| str[n + 1] == '_'))
		while (str[++n] && (!is_special(str[n]) \
		&& (isalnum(str[n]) || str[n] == '_')))
			len++;
	else
		len++;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, &str[++i], (len + 1));
	return (res);
}

void	expand_no_env(char **str, char *var_name, int *i)
{
	char	*tmp;
	int		k;
	int		j;

	tmp = ft_strdup(*str);
	if (!tmp)
	{
		free(tmp);
		return ;
	}
	free(*str);
	*str = (char *)malloc(sizeof(char) * (ft_strlen(tmp) \
	- ft_strlen(var_name) + 1));
	if (!(*str))
	{
		free(tmp);
		*str = NULL;
		return ;
	}
	bzero(*str, ft_strlen(tmp) - ft_strlen(var_name) + 1);
	k = ft_strnfill(*str, tmp, *i);
	j = k + ft_strlen(var_name);
	ft_strcpy(&(*str)[k], &tmp[++j]);
	free(tmp);
}
