#include "libx.h"

char    *ft_space(char *str)
{
    int     i;
    int     j;
    int     count;
    char    *new;

    if (!str)
        return (NULL);
    i = 0;
    count = 0;
    while (str[i])
    {
        if (str[i] != ' ')
            count++;
        i++;
    }
    new = malloc(sizeof(char) * (count + 1));
    i = 0;
    j = 0;
    while (str[i])
    {
        if (str[i] != ' ')
            new[j++] = str[i];
        i++;
    }
    new[j] = '\0';
    return (new);
}