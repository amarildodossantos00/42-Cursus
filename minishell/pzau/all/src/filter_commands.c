#include "../header/header.h"

int filter_commands(t_vars *vars)
{
    if (ft_strncmp(vars->input, "env", ft_strlen(vars->input)) == 0)
    {
        print_variables(vars);
        return (1);
    }
    else if (ft_strncmp(vars->input, "unset", ft_strlen(vars->input)) == 0)
    {
        remove_variable(vars, "PATH");
        return (1);
    }
    else if (ft_strncmp(vars->input, "export", ft_strlen(vars->input)) == 0)
    {
        add_variables(vars, "pzau");
        return (1);
    }
    else if (ft_strncmp(vars->input, "path", ft_strlen(vars->input)) == 0)
    {
        printf("%s\n", vars->path);
        return (1);
    }
    //cc
    vars->matrix = ft_split(vars->input);
    if (ft_strncmp(vars->matrix[0], "cd", 2) == 0)
    {
        cd(vars);
        return (1);
    }
    if (ft_strncmp(vars->input, "pwd", ft_strlen(vars->input)) == 0)
    {
        pwd(vars);
        return (1);
    }
    if (ft_strncmp(vars->matrix[0], "echo", ft_strlen(vars->matrix[0])) == 0)
    {
        echo(vars);
        return (1);
    }
    //cc
    return (0);
}