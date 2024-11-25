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
int 	ft_strlen2(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *str, int c);
char    *ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strtok(char *str, const char *delim);
char	*sncat(char *dest, const char *src, size_t n);
char    **ft_split(char *str);
char    **red_ft_split(char *str);
void	*ft_memset(void *s, int c, size_t n);
char    **ft_split_red(char *str);
char    *ft_space(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split_args(char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif
