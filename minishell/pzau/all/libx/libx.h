#ifndef LIBX_H
# define LIBX_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str);
int     ft_strcmp(char *s1, char *s2);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *str, int c);
char    *ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strtok(char *str, const char *delim);
char	*sncat(char *dest, const char *src, size_t n);
char    **ft_split(char *str);
char    **red_ft_split(char *str);

#endif
