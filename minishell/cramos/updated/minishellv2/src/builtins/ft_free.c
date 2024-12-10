#include "../../header/header.h"

void    free_env(t_env *env)
{
    t_env *tmp;

    while (env)
    {
        tmp = env;
        env = env->next;
        free(tmp->var);
        free(tmp->value);
        free(tmp);
    }
}

void    free_array(char **env)
{
    int		i;

    i = 0;

    if (!env)
        return ;
    while (env[i])
    {
        free(env[i]);
        i++;
    }
    free(env);
}