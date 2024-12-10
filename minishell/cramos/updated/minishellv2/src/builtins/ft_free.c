#include "../../header/header.h"

void free_env(t_env *env_ref)
{
    t_env *temp;

    while (env_ref)
    {
        temp = env_ref->next;
        free(env_ref->var);
        free(env_ref->value);
        free(env_ref);
        env_ref = temp;
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