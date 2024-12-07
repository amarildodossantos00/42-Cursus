#include "../header/header.h"

// files 1
void    redirect_output(char *file)
{
    int fd;

    fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644); 
    if (fd < 0)
    {
        perror("open");
        return ;
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
}

void    append_output(char *file)
{
    int fd;

    fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0)
    {
        perror("open");
        return ;
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
}

int    redirect_input(char *file)
{
    int     fd;

    if (access(file, F_OK) != 0)
        return (1);      
    if (access(file, R_OK) != 0)
        return (1);
    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        printf("open");
        return (2);
    }
    dup2(fd, STDIN_FILENO);
    close(fd);
    return (0);
}

static void close_x(int *pipe_fd, int stdin_backup)
{
    close(pipe_fd[1]);
    dup2(pipe_fd[0], STDIN_FILENO);
    close(pipe_fd[0]);
    dup2(stdin_backup, STDIN_FILENO);
    close(stdin_backup);
}

void redirect_herdoc(t_vars *vars, char *delimiter)
{
    int     pipe_fd[2];
    char    buffer[1024];
    size_t  bytes_read;
    size_t  delimiter_len;
    int     stdin_backup;

    delimiter_len = ft_strlen(delimiter);
    stdin_backup = dup(STDIN_FILENO);
    if (stdin_backup < 0)
    {
        perror("dup");
        return;
    }
    if (pipe(pipe_fd) < 0)
    {
        perror("pipe");
        return;
    }
    while (1)
    {
        write(STDOUT_FILENO, "> ", 2);
        bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
        if (bytes_read <= 0)
            break;
        buffer[bytes_read] = '\0';
        if (buffer[bytes_read - 1] == '\n')
            buffer[bytes_read - 1] = '\0';

        if (ft_strncmp(buffer, delimiter, delimiter_len) == 0)
            break;
        write(pipe_fd[1], buffer, bytes_read);
        write(pipe_fd[1], "\n", 1);
    }
    close_x(pipe_fd, stdin_backup);
}

//files 1

static char *add_spaces_around_operators(const char *input)
{
    const char *operators = "><";
    size_t len = strlen(input);
    char *output = malloc(len * 3 + 1);
    int j = 0;

    for (size_t i = 0; i < len; i++)
    {
        if (strchr(operators, input[i]))
        {
            if (j > 0 && output[j - 1] != ' ')
                output[j++] = ' ';
            output[j++] = input[i];
            if (input[i + 1] == input[i])
            {
                output[j++] = input[i++];
            }
            if (input[i + 1] != ' ')
                output[j++] = ' ';
        }
        else
        {
            output[j++] = input[i];
        }
    }

    output[j] = '\0';
    return (output);
}

char **org_red(const char *input)
{
    char **result = NULL;
    int count = 0;
    char *normalized_input = add_spaces_around_operators(input);
    char *input_copy = strdup(normalized_input);
    char *token = strtok(input_copy, " ");
    char buffer[256] = {0};
    int buffer_filled = 0;
    char *prev = NULL;

    while (token)
    {
        int is_operator = (strcmp(token, ">") == 0 || strcmp(token, "<") == 0 || 
                           strcmp(token, ">>") == 0 || strcmp(token, "<<") == 0);

        if (is_operator)
        {
            if (prev)
            {
                result = realloc(result, (count + 1) * sizeof(char *));
                result[count++] = strdup(buffer);
            }
            snprintf(buffer, sizeof(buffer), "%s", prev ? prev : "");
            strncat(buffer, " ", sizeof(buffer) - strlen(buffer) - 1);
            strncat(buffer, token, sizeof(buffer) - strlen(buffer) - 1);
            buffer_filled = 1;
        }
        else
        {
            if (buffer_filled)
            {
                strncat(buffer, " ", sizeof(buffer) - strlen(buffer) - 1);
                strncat(buffer, token, sizeof(buffer) - strlen(buffer) - 1);
            } else
            {
                snprintf(buffer, sizeof(buffer), "%s", token);
                buffer_filled = 1;
            }
        }

        prev = token;
        token = strtok(NULL, " ");

        if (!token && buffer_filled)
        {
            result = realloc(result, (count + 1) * sizeof(char *));
            result[count++] = strdup(buffer);
        }
    }

    result = realloc(result, (count + 1) * sizeof(char *));
    result[count] = NULL;

    free(input_copy);
    free(normalized_input);
    return result;
}


//files 3
static int more_than_two(char *new)
{
    int i;
    char *str;

    i = 0;
    str = ft_space(new);
    while (str[i])
    {
        if (str[i] == '>' && str[i + 1] == '>' && str[i + 2] == '>')
            return (1);
        i++;
    }
    free(str);
    return (0);
}

static int  cheack_in_tree(char *new)
{
    char    *str;
    int     i;

    i = 0;
    str = ft_space(new);
    while (str[i])
    {
        if (str[i] == '<' && str[i + 1] == '<' && str[i + 2] == '<')
            return (1);
        if (str[i] == '<' && str[i + 1] == '<' && str[i + 2] != '<')
            return (2);
        i++;
    }
    free(str);
    return (0);
}

int    cheack_input_red(t_vars *vars, char *str, char **redic)
{
    int     i;
    char    *str1;
    char    **new;

    if (more_than_two(str))
    {
        printf("minishell: syntax error near unexpected token `>'\n");
        return (1);
    }
    i = 0;
    while (redic[i])
    {
        new = ft_split_red(redic[i]);
        if (cheack_in_tree(redic[i]) == 1)
        {
            i++;
            continue ;
        }
        if (cheack_in_tree(redic[i]) == 2)
        {
            str1 = ft_space(new[1]);
            redirect_herdoc(vars, str1);
            free(str1);
        }
        i++;
    }
}
// files 3
