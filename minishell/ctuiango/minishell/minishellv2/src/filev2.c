#include "../header/header.h"

static int  cheak_string(t_vars *vars)
{
    int i;

    i = 0;
    while (vars->input[i])
    {
        if (vars->input[i] == '|')
            return (1);
        i++;
    }
    i = 0;
    while (vars->input[i])
    {
        if (vars->input[i] == '>' || vars->input[i] == '<')
        {
            if ((vars->input[i + 1] && vars->input[i]) == vars->input[i + 1])
                return (2);
            return (3);
        }
        i++;
    }
    return (0);
}

void    redirecionamento(t_vars *vars)
{
    char    **redic;

    redic = org_red(vars->input);
    for (int i = 0; redic[i]; i++)
        printf("%s\n", redic[i]);
    
}

void    read_readline(t_vars *vars)
{
    int val;

    if (expand_var(vars))
        return ;
    val = cheak_string(vars);
    if (val == 1)
        printf("pipe not done yet!\n");
    else if (val == 2 || val == 3)
        redirecionamento(vars);
    else
        only_comands(vars);
    return ;
}