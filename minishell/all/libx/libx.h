#ifndef LIBX_H
# define LIBX_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_split_token
{
	int		i;
	int		j;
	int		size;
	int		point;
	char	*tmp;
	char	**mtx;
}	t_split_token;

int	ft_strlen(char *str);
int     ft_strcmp(char *s1, char *s2);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *str, int c);
char    *ft_strdup(char *src);
char	**ft_split_args(char *str);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int ft_strlen2(const char *str);

#endif
