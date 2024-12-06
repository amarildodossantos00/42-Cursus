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
    char    *str;
    char    **redic;
    char    **command;

    i = 0;
    redic = org_red(vars->input);
    vars->terminal = dup(STDOUT_FILENO);
    if (cheack_input_red(vars ,vars->input, redic))
        return ;
    while (redic[i] != NULL)
    {
        command = ft_split_red(redic[i]);
        if (count_words(command[1]) > 1)
            command = ft_split(ft_strjoin(" a ", command[1]));
        if (cheack_red(redic[i]) == 2)
            redirect_output(ft_space(command[1]));
        else if (cheack_red(redic[i]) == 1)
            append_output(ft_space(command[1]));
        else if (cheack_red(redic[i]) == 4)
        {
            if (redirect_input(ft_space(command[1])) == 1)
            {
                dup2(vars->terminal, STDOUT_FILENO);
                printf("%s: No such file or directory\n", ft_space(command[1]));
                return ;
            }
        }
        else if (cheack_red(redic[i]) == 3)
        {
            i++;
            continue ; 
        }
        i++;
        free(command);
    }
    i = 0;
    command = ft_split_red(redic[0]);
    str = command[0];
    while (redic[i] != NULL)
    {
        command = ft_split_red(redic[i]);
        if (count_words(command[1]) > 1)
        {
            command = ft_split(command[1]);
            int j = 1;
            while (command[j])
            {
                str = ft_strjoin(ft_strjoin(str, " "), command[j]);
                j++;
            }
        }
        i++;
    }

    /*if (vars->val_red > 0 && redic[0] != NULL)
    {
        char *file = ft_strjoin("/tmp/", ft_itoa(vars->val_red));
        char *redstr = ft_strjoin(redic[0], " ");
        redstr = ft_strjoin(redstr, ler_arquivo(file));
        vars->input = redstr;
        only_comands(vars);
    }*/
    vars->input = str;
    only_comands(vars);
    dup2(vars->terminal, STDOUT_FILENO);
    close(vars->terminal);
}

void    read_readline(t_vars *vars)
{
    char	**env_array;
    int val;

    val = cheak_string(vars);
    env_array = convert_env_list(vars->env_ref);
    if (expand_var(vars))
    	return ;
    if (val == 1)
        execute_pipe(vars);
    else if (val == 2 || val == 3)
        redirecionamento(vars);
    else
        only_comands(vars);
    return ;
}
