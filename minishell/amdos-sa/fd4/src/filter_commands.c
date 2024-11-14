#include "../header/header.h"

int filter_commands(t_vars *vars)
{
    if (ft_strncmp(vars->input, "", ft_strlen(vars->input)) == 0)
        return (0);
    else if (ft_strncmp(vars->input, "env", ft_strlen(vars->input)) == 0)
    {
        print_variables(vars);
        return (1);
    }
    else if (ft_strncmp(vars->input, "unset", ft_strlen(vars->input)) == 0)
    {
        remove_variable(vars, "PATH");
    }
    else if (ft_strncmp(vars->input, "export", ft_strlen(vars->input)) == 0)
    {
        add_variables(vars, "pzau");
        return (1);
    }
    else if (ft_strncmp(vars->input, "path", ft_strlen(vars->input)) == 0)
    {
        printf("%s\n", vars->pwd);
        return (1);
    }
    return (0);
}