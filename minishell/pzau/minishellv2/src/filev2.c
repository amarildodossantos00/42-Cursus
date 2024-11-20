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

static int  cheack_red(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '>')
        {
            if ((str[i + 1] && str[i]) == str[i + 1])
                return (1);
            return (2);
        }
        i++;
    }
    i = 0;
    while (str[i])
    {
        if (str[i] == '<')
        {
            if ((str[i + 1] && str[i]) == str[i + 1])
                return (3);
            return (4);
        }
        i++;
    }
    return (0);
}

void    redirecionamento(t_vars *vars)
{
    int     i;
    char    **redic;
    char    **command;

    i = 0;
    redic = org_red(vars->input);
    vars->terminal = dup(STDOUT_FILENO);
    while (redic[i] != NULL)
    {
        command = ft_split_red(redic[i]);
        if (cheack_red(redic[i]) == 2)
            redirect_output(ft_space(command[1]));
        else if (cheack_red(redic[i]) == 1)
            append_output(ft_space(command[1]));
        else if (cheack_red(redic[i]) == 4)
        {
            if (redirect_input(ft_space(command[1])) == 1)
            {
                printf("%s: No such file or directory\n", ft_space(command[1]));
                dup2(vars->terminal, STDOUT_FILENO);
                return ;
            }
        }
        else if (cheack_red(redic[i]) == 3)
            printf("Not done yet !\n");
        i++;
    }
    command = ft_split_red(redic[0]);
    vars->input = command[0];
    only_comands(vars);
    dup2(vars->terminal, STDOUT_FILENO);
    close(vars->terminal);
}

void    read_readline(t_vars *vars)
{
    int val;

    val = cheak_string(vars);
    if (val == 1)
        printf("pipe not done yet!\n");
    else if (val == 2 || val == 3)
        redirecionamento(vars);
    else
        only_comands(vars);
    return ;
}