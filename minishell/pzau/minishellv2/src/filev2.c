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

int  cheack_red(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '>')
        {
            if (str[i + 1] == '>')
                return (1);
            return (2);
        }
        if (str[i] == '<')
        {
            if (str[i + 1] == '<')
                return (3);
            return (4);
        }
        i++;
    }

    return (0);
}

static int  check_one_red(char **str)
{
    int i;

    i = 1;
    while (str[i])
    {
        if (cheack_red(str[i]) != 3)
            return (0);
        i++;
    }
    return (1);
}

void    redirecionamento(t_vars *vars, int status)
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
    if (vars->val_red > 0 && redic[0] != NULL && status != 1)
    {
        int fd;
        int  pid;
        extern char **environ;

        pid = fork();
        char *file = ft_strjoin("/tmp/", ft_itoa(vars->val_red));
        if (pid == 0)
        {
            fd = open(file, O_RDONLY);
            if (fd < 0)
                perror("Error opening the file");
            dup2(fd, 0);
            close(fd);
            char *str2 = find_executable(redic[0], vars->path);
            char   **str1 = malloc(sizeof(char *) * 2);
            str1[0] = redic[0];
            str1[1] = NULL;
            execve(str2, str1, NULL);
        }
        else
            wait(NULL);
    }
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
    vars->input = str;
    if (!check_one_red(redic))
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
        redirecionamento(vars, 0);
    else
        only_comands(vars);
    return ;
}
