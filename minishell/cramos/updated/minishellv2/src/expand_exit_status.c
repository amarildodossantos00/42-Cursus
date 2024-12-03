#include "../header/header.h"

void    execute_command(t_vars *vars, char *command)
{
    vars->exit_status = 0;
    if (!command || !vars->args || !vars->args[0])
    {
        vars->exit_status = 127;
        return ;
    }
    if (access(command, X_OK) == -1)
    {
        vars->exit_status = 127;
        return ;
    }
    pid_t pid = fork();
    int status;
    if (pid == 0)
    {
        if (execve(command, vars->args, vars->env) == -1)
        {
            perror("execve");
            exit(127);
        }
    }
    /*else if (pid > 0)
    {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status))
            vars->exit_status = WEXITSTATUS(status);
        else if (WIFSIGNALED(status))
            vars->exit_status = 128 + WTERMSIG(status);
        else
            vars->exit_status = 1;
    }*/
    else
    {
        perror("fork");
        vars->exit_status = 1;
    }
}

void    expand_exit_status(t_vars *vars)
{
    char    *new_input;
    char    *pos = strstr(vars->input, "$?");
    char    *exit;
    
    if (!pos)
        return ;
    vars->exit_status %= 256;
    if (vars->exit_status < 0 || vars->exit_status > 255)
        vars->exit_status %= 256;
    exit = ft_itoa(vars->exit_status);
    if (!exit)
        return ;
    new_input = malloc(ft_strlen(vars->input) - 2 + ft_strlen(exit) + 1);
    if (!new_input)
    {
        free(exit);
        return ;
    }
    strncpy(new_input, vars->input, pos - vars->input);
    new_input[pos - vars->input] = '\0';
    strcat(new_input, exit);
    strcat(new_input, pos + 2);
    free(exit);
    free(vars->input);
    vars->input = new_input;
}