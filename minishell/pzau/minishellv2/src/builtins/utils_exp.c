#include "../../header/header.h"

int export_var(t_vars *vars, char *input)
{
    char *equal = ft_strchr(input, '=');
    if (equal)
    {
        char *var = ft_substr(input, 0, equal - input);
        char *value = ft_strdup(equal + 1);
        if (!var || !value)
        {
            free(var);
            free(value);
            return (0);
        }
        add_and_update(&vars->env_ref, var, value, 0);
        free(var);
        free(value);
        return (1);
    }
    return (0);
}