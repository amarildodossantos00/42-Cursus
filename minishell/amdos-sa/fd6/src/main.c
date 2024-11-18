#include "../header/header.h"

static  void    init_values(t_vars *vars)
{
    extern char	**environ;

    vars->input = NULL;
    vars->path = NULL;
    vars->home = NULL;
    vars->matrix = NULL;
    vars->args = NULL;
    vars->env = environ;
    vars->cargs = 0;
}

int		main(void)
{
    t_vars  vars;

    init_values(&vars);
    start_promp(&vars);
    return (0);
}