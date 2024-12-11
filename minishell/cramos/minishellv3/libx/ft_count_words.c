#include "libx.h"

static int ft_isspace(char c)
{
        return (c == ' ' || c == '\t' || 
            c == '\n' || c == '\v' || 
            c == '\f' || c == '\r');
}

int count_words(const char *str)
{
    int count;
    int in_word;

    count = 0;
    in_word = 0;
    if (!str)
        return (0);
    while (*str)
    {
        if (ft_isspace(*str))
            in_word = 0;
        else if (!in_word)
        {
            in_word = 1;
            count++;
        }
        str++;
    }
    return (count);
}