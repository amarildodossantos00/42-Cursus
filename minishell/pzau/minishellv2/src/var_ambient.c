#include "../header/header.h"

char	*get_path(t_vars *vars)
{
    t_env *current;

    if (!vars->env_ref)
    {
        init_env(vars);
    }
    current = vars->env_ref;
    while (current)
    {
        if (strcmp(current->var, "PATH") == 0)
            return current->value;
        current = current->next;
    }
    return "nothing";
}

