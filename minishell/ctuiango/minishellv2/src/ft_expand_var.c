#include "../header/header.h"

char    *replace_variable(char *input, int start, int len, char *replace)
{
    int new_line;
    char    *new_input;

    new_line = ft_strlen(input) - len, + ft_strlen(replace);
    new_input = malloc(new_line + 1);
    strncpy(new_input, input, start);
    ft_strcpy(&new_input[start], replace);
    ft_strcpy(&new_input[start + ft_strlen(replace)], &input[start + len]);
    free(input);
    return (new_input);
}

char    *replace_exit_status(char *input)
{
    int i;
    //int	last_status = 0;

    i = 0;
    while (input[i])
    {
        if (input[i] == '$' && input[i + 1] == '?')
        {
            char *exit_status = ft_itoa(last_status); // Converta last_status para string
            char *new_input = replace_variable(input, i, 2, exit_status); // Substitua "$?" pelo código de saída
            free(exit_status);
            return new_input;
        }
        i++;
    }
    return (input);
}

int    search_var(t_vars *vars, char *var, int *p, int len)
{
    int		i;
    int		j;
    t_env   *tmp;
    char    *new_line;

    i = 0;
    tmp = vars->env_ref;
    while (tmp)
    {
        if (ft_strcmp(tmp->var, var) == 0)
        {
            struct stat path_stat;
            if (stat(tmp->value, &path_stat) == 0 && S_ISDIR(path_stat.st_mode))
            {
                printf("bash: %s: Is a directory\n", tmp->value);
                free(var);
                return (1);
            }
            new_line = malloc(sizeof(char) * ft_strlen(vars->input) - ft_strlen(var) + ft_strlen(tmp->value));
            while (i < *p)
            {
                new_line[i] = vars->input[i];
                i++;
            }
            j = 0;
            while (tmp->value[j])
            {
                new_line[i] = tmp->value[j];
                i++;
                j++;
            }
            *p = i;
            if (ft_strlen(vars->input) > len && vars->input[len])
            {
                while (vars->input[len])
                {
                    new_line[i] = vars->input[len];
                    i++;
                    len++;
                }
                new_line[i] = '\0';
                free(vars->input);
                vars->input = new_line;
            }
            else
            {
               new_line[i] = '\0';
                free(vars->input);
                vars->input = new_line; 
            }
            return (0);
        }
        tmp = tmp->next;
    }
    new_line = malloc(sizeof(char) * ft_strlen(vars->input) - ft_strlen(var));
    while (i < *p)
    {
        new_line[i] = vars->input[i];
        i++;
    }
    if (ft_strlen(vars->input) > len && vars->input[len])
    {
        while (vars->input[len])
        {
            new_line[i] = vars->input[len];
            i++;
            len++;
        }
        new_line[i] = '\0';
        free(vars->input);
        vars->input = new_line;
    }
    else
    {
        new_line[i] = '\0';
        free(vars->input);
        vars->input = new_line; 
    }
}   

char    *return_name(char *str)
{
    int		i;
    int		len;
    char    *var;
    i = 0;
    len = 0;
    while (str[i] && (isdigit(str[i]) || isalpha(str[i]) || str[i] == '_'))
    {
        len++;
        i++;
    }
    var = malloc(sizeof(char) * len + 1);
    i = 0;
    while (i < len)
    {
        var[i] = str[i];
        i++;
    }
    var[i] = '\0';
    return (var);
}

int    expand_var(t_vars *vars)
{
    int		i;
    char    *var;

    i = 0;
    vars->input = replace_exit_status(vars->input);
    while (vars->input[i])
    {
        if (vars->input[i] == '$' && vars->input[i + 1] != ' ' && vars->input[i + 1] != '\t' && vars->input[i + 1] != '\0')
        {
            var = return_name(&vars->input[i + 1]);
            if (search_var(vars, var, &i, ft_strlen(var) + i + 1))
                return (1);
        }
        i++;
    }
}